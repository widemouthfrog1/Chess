#include "stdafx.h"
#include "Piece.h"




Piece::~Piece()
{
	this->image.~shared_ptr();
}

void Piece::setPosition(POINT pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

void Piece::setPosition(Tile tile)
{
	this->pos.x = tile.getPos().x;
	this->pos.y = tile.getPos().y;
}

void Piece::press(POINT mousePos) {
	this->pos.x = mousePos.x - Tile::SIZE / 2;
	this->pos.y = mousePos.y - Tile::SIZE / 2;
}

void Piece::drag(POINT mousePos) {
	this->pos.x = mousePos.x - Tile::SIZE / 2;
	this->pos.y = mousePos.y - Tile::SIZE / 2;
}

bool Piece::isWhite() {
	return this->white;
}