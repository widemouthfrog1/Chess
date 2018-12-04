#include "stdafx.h"
#include "Board.h"
#include "Piece.h"
#include "Rook.h"



Board::Board()
{
}

Board::Board(std::map<std::string, std::shared_ptr<Image>> images)
{
	this->x = 300;
	this->y = 50;
	for (int row = 0; row < 8; row++) {
		tiles.push_back(std::vector<std::shared_ptr<Tile>>());
		for (int col = 0; col < 8; col++) {
			POINT pos;
			pos.x = x + row * Tile::SIZE;
			pos.y = y + col * Tile::SIZE;
			tiles.at(row).push_back(std::make_shared<Tile>(pos, (row + col + 1) % 2));
		}
	}
	POINT rook_pos;
	rook_pos.x = x;
	rook_pos.y = y;
	std::shared_ptr<Rook> rook = std::make_shared<Rook>(images.at("Rook"), 0, rook_pos);
	this->tiles.at(0).at(0)->addPiece(rook);
	this->pieces.push_back(this->tiles.at(0).at(0)->getPiece());
}

Board::Board(int size, std::map<std::string, std::shared_ptr<Image>> images)
{
	this->x = 300;
	this->y = 50;
	for (int row = 0; row < size; row++) {
		tiles.push_back(std::vector<std::shared_ptr<Tile>>());
		for (int col = 0; col < size; col++) {
			POINT pos;
			pos.x = x + row * Tile::SIZE;
			pos.y = y + col * Tile::SIZE;
			tiles.at(row).push_back(std::make_shared<Tile>(pos, (row + col + 1) % 2));
		}
	}
}

Board::Board(int width, int height, std::map<std::string, std::shared_ptr<Image>> images)
{
	this->x = 300;
	this->y = 50;
	for (int row = 0; row < width; row++) {
		tiles.push_back(std::vector<std::shared_ptr<Tile>>());
		for (int col = 0; col < height; col++) {
			POINT pos;
			pos.x = x + row * Tile::SIZE;
			pos.y = y + col * Tile::SIZE;
			tiles.at(row).push_back(std::make_shared<Tile>(pos, (row + col + 1) % 2));
		}
	}
}

Board::Board(std::vector<std::vector<std::shared_ptr<Tile>>> tiles, std::map<std::string, std::shared_ptr<Image>> images)
{
	this->tiles = tiles;
}


Board::~Board()
{
	this->pieces.~vector();
	this->tiles.~vector();
}

void Board::draw(Graphics* canvas)
{
	for (std::vector<std::shared_ptr<Tile>> row : this->tiles) {
		for (std::shared_ptr<Tile> tile : row) {
			tile->draw(canvas);
		}
	}
	for (int i = 0; i < this->pieces.size(); i++) {
			this->pieces.at(i)->draw(canvas);
		
	}
	if (this->held != NULL) {
		this->held->draw(canvas);//make sure the held piece is always in front
	}
	
}

void Board::press(POINT mouse_position)
{
	for (int i = 0; i < this->tiles.size(); i++) {
		for (int j = 0; j < this->tiles.at(i).size(); j++) {
			tiles.at(i).at(j)->press(mouse_position, &(this->held));
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

bool Board::addPiece(std::shared_ptr<Piece> piece, Tile* tile)
{
	if (tile->addPiece(piece)) {
		this->pieces.push_back(piece);
		return true;
	}
	return false;
}

void Board::setPiece(std::shared_ptr<Piece> piece, Tile* tile)
{
	if (tile->getPiece() != NULL) {
		for (int i = 0; i < this->pieces.size(); i++) {
			if (this->pieces.at(i) == tile->getPiece()) {//check for the exact same piece as the one in the tile
				this->pieces.erase(this->pieces.begin() + i);
			}
		}
	}
	tile->setPiece(piece);
	this->pieces.push_back(piece);
}
