#include "stdafx.h"
#include "Piece.h"




Piece::~Piece()
{
}

void Piece::setPosition(POINT pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

void Piece::setPosition(Tile tile)
{
	this->pos.x = tile.getX();
	this->pos.y = tile.getY();
}

void Piece::press(POINT mousePos) {
	this->pos.x = mousePos.x;
	this->pos.y = mousePos.y;
}

void Piece::drag(POINT mousePos) {
	this->pos.x = mousePos.x;
	this->pos.y = mousePos.y;
}

bool Piece::isWhite() {
	return this->white;
}