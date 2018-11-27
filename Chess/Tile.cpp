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

void Tile::draw(HDC canvas)
{
	if (this->colour == -1) {//this allows tiles to be empty
		return;
	}
	HBRUSH colour;
	//sets the colour of this tile to white if this->colour == 1 
	//or black if this->colour == 0
	if (this->colour == 3) {
		colour = CreateSolidBrush(RGB(240, 255, 0));
	}
	else if (this->colour == 2) {
		colour = CreateSolidBrush(RGB(130, 155, 255));
	}
	else if (this->colour) {
		colour = CreateSolidBrush(RGB(255, 255, 255));
	}
	else {
		colour = CreateSolidBrush(RGB(0, 0, 0));
	}

	//defines the rectangle to be drawn for this tile
	RECT tile;
	tile.left = this->pos.x;
	tile.top = this->pos.y;
	tile.bottom = this->pos.y + Tile::SIZE;
	tile.right = this->pos.x + Tile::SIZE;

	//draws the rectangle to the canvas
	FillRect(canvas, &tile, colour);

	//deletes the brush to make space for other brushes
	DeleteObject(colour);
}

bool Tile::isOn(POINT point)
{
	return point.x > this->pos.x && point.x < this->pos.x + Tile::SIZE && point.y > this->pos.y && point.y < this->pos.y + Tile::SIZE;
}

void Tile::press(POINT mouse, Piece* held)
{
	if (isOn(mouse)) {
		if (piece != NULL) {
			piece->press(mouse);
			held = piece;
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

bool Tile::addPiece(Piece * piece)
{
	if (this->piece == NULL) {
		this->piece = piece;
		return true;
	}
	return false;
}

void Tile::setPiece(Piece * piece)
{
	this->piece = piece;
}

Piece* Tile::getPiece()
{
	return this->piece;
}


