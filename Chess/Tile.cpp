#include "stdafx.h"
#include "Tile.h"


Tile::Tile(POINT pos, int colour)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	this->colour = colour;
}

Tile::~Tile()
{
}

void Tile::draw(Graphics* canvas)
{
	if (this->colour == -1) {//this allows tiles to be empty
		return;
	}
	Color colour;
	//sets the colour of this tile to white if this->colour == 1 
	//or black if this->colour == 0
	if (this->colour == 3) {
		colour = Color(240, 255, 0);
	}
	else if (this->colour == 2) {
		colour = Color(130, 155, 255);
	}
	else if (this->colour) {
		colour = Color(255, 255, 255);
	}
	else {
		colour = Color(0, 0, 0);
	}
	canvas->FillRectangle(&SolidBrush(colour), this->pos.x, this->pos.y, Tile::SIZE, Tile::SIZE);
}

bool Tile::isOn(POINT point)
{
	return point.x > this->pos.x && point.x < this->pos.x + Tile::SIZE && point.y > this->pos.y && point.y < this->pos.y + Tile::SIZE;
}

void Tile::press(POINT mouse, std::shared_ptr<Piece>* held)
{
	if (isOn(mouse)) {
		if (piece != NULL) {
			piece->press(mouse);
			*held = piece;
		}
		if (this->colour == 0) {
			this->colour = 2;
		}
		else if (this->colour == 1) {
			this->colour = 3;
		}
		else if (this->colour == 2) {
			this->colour = 0;
		}
		else if (this->colour == 3) {
			this->colour = 1;
		}
	}
		
}


POINT Tile::getPos() {
	return this->pos;
}

bool Tile::addPiece(std::shared_ptr<Piece> piece)
{
	if (this->piece == NULL) {
		this->piece = piece;
		return true;
	}
	return false;
}

void Tile::setPiece(std::shared_ptr<Piece> piece)
{
	this->piece = piece;
}

std::shared_ptr<Piece> Tile::getPiece()
{
	return this->piece;
}


