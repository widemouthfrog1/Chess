#include "stdafx.h"
#include "Tile.h"


Tile::Tile(int x, int y, int colour)
{
	this->x = x;
	this->y = y;
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
	tile.left = this->x;
	tile.top = this->y;
	tile.bottom = this->y + Tile::SIZE;
	tile.right = this->x + Tile::SIZE;

	//draws the rectangle to the canvas
	FillRect(canvas, &tile, colour);

	//deletes the brush to make space for other brushes
	DeleteObject(colour);
}

void Tile::left_button_down(POINT mouse_position)
{
	if (isOn(mouse_position)) {
		if (this->colour == 0) {
			this->colour = 2;
		}else if (this->colour == 1) {
			this->colour = 3;
		}else if (this->colour == 2) {
			this->colour = 0;
		}else if (this->colour == 3) {
			this->colour = 1;
		}
	}
}

void Tile::left_button_up(POINT mouse_position)
{
}

bool Tile::isOn(POINT point)
{
	return point.x > this->x && point.x < this->x + Tile::SIZE && point.y > this->y && point.y < this->y + Tile::SIZE;
}


