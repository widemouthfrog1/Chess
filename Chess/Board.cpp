#include "stdafx.h"
#include "Board.h"


Board::Board(std::map<std::string, unsigned char *> images)
{
	this->x = 300;
	this->y = 50;
	for (int row = 0; row < 8; row++) {
		tiles.push_back(std::vector<Tile>());
		for (int col = 0; col < 8; col++) {
			POINT pos;
			pos.x = x + row * Tile::SIZE;
			pos.y = y + col * Tile::SIZE;
			tiles.at(row).push_back(Tile(pos, (row + col + 1) % 2));
		}
	}
}

Board::Board(int size, std::map<std::string, unsigned char *> images)
{
	this->x = 300;
	this->y = 50;
	for (int row = 0; row < size; row++) {
		tiles.push_back(std::vector<Tile>());
		for (int col = 0; col < size; col++) {
			POINT pos;
			pos.x = x + row * Tile::SIZE;
			pos.y = y + col * Tile::SIZE;
			tiles.at(row).push_back(Tile(pos, (row + col + 1) % 2));
		}
	}
}

Board::Board(int width, int height, std::map<std::string, unsigned char *> images)
{
	this->x = 300;
	this->y = 50;
	for (int row = 0; row < width; row++) {
		tiles.push_back(std::vector<Tile>());
		for (int col = 0; col < height; col++) {
			POINT pos;
			pos.x = x + row * Tile::SIZE;
			pos.y = y + col * Tile::SIZE;
			tiles.at(row).push_back(Tile(pos, (row + col + 1) % 2));
		}
	}
}

Board::Board(std::vector<std::vector<Tile>> tiles, std::map<std::string, unsigned char *> images)
{
	this->tiles = tiles;
}


Board::~Board()
{
}

void Board::draw(HDC canvas)
{
	for (std::vector<Tile> row : this->tiles) {
		for (Tile tile : row) {
			tile.draw(canvas);
		}
	}
	for (int i = 0; i < this->pieces.size(); i++) {
		this->pieces.at(i).draw(canvas);
	}
	this->held->draw(canvas);//make sure the held piece is always in front
	
}

void Board::press(POINT mouse_position)
{
	for (int i = 0; i < this->tiles.size(); i++) {
		for (int j = 0; j < this->tiles.at(i).size(); j++) {
			tiles.at(i).at(j).press(mouse_position, this->held);
		}
	}
}

void Board::drag(POINT mouse)
{
	if (this->held != NULL) {
		this->held->drag(mouse);
	}
}

void Board::release(POINT mouse_position)
{
	this->held = NULL;

}

bool Board::addPiece(Piece* piece, Tile* tile)
{
	if (tile->addPiece(piece)) {
		this->pieces.push_back(*piece);
		return true;
	}
	return false;
}

void Board::setPiece(Piece* piece, Tile* tile)
{
	if (tile->getPiece() != NULL) {
		for (int i = 0; i < this->pieces.size(); i++) {
			if (&(this->pieces.at(i)) == tile->getPiece()) {//check for the exact same piece as the one in the tile
				this->pieces.erase(this->pieces.begin() + i);
			}
		}
	}
	tile->setPiece(piece);
	this->pieces.push_back(*piece);
}
