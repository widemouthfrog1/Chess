#include "stdafx.h"
#include "Board.h"


Board::Board()
{
	this->x = 300;
	this->y = 50;
	for (int row = 0; row < 8; row++) {
		tiles.push_back(std::vector<Tile>());
		for (int col = 0; col < 8; col++) {
			tiles.at(row).push_back(Tile(x + row*Tile::SIZE, y + col*Tile::SIZE, (row + col + 1) % 2));
		}
	}
}

Board::Board(int size)
{
	for (int row = 0; row < size; row++) {
		tiles.push_back(std::vector<Tile>());
		for (int col = 0; col < size; col++) {
			tiles.at(row).push_back(Tile(row*Tile::SIZE, col*Tile::SIZE, (row + col + 1) % 2));
		}
	}
}

Board::Board(int width, int height)
{
	for (int row = 0; row < width; row++) {
		tiles.push_back(std::vector<Tile>());
		for (int col = 0; col < height; col++) {
			tiles.at(row).push_back(Tile(row*Tile::SIZE, col*Tile::SIZE, (row + col + 1) % 2));
		}
	}
}

Board::Board(std::vector<std::vector<Tile>> tiles)
{
	this->tiles = tiles;
}


Board::~Board()
{
}

//
//	FUNCTION: draw(HDC)
//	
//	PURPOSE: Drawing the board to the screen.
//
void Board::draw(HDC canvas)
{
	for (std::vector<Tile> row : this->tiles) {
		for (Tile tile : row) {
			tile.draw(canvas);
		}
	}
}

void Board::left_button_down(POINT mouse_position)
{
	for (int i = 0; i < this->tiles.size(); i++) {
		for (int j = 0; j < this->tiles.at(i).size(); j++) {
			tiles.at(i).at(j).left_button_down(mouse_position);
		}
	}
}

void Board::left_button_up(POINT mouse_position)
{
}
