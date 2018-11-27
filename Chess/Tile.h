#pragma once
#include "Piece.h"

class Tile
{
	int colour;
	POINT pos;
	Piece* piece;
public:
	const static int SIZE = 50;
	const static int EMPTY = -1;
	const static int HIGHLIGHTED = 2;
	Tile(POINT pos, int colour);
	~Tile();

	void draw(HDC canvas);
	bool isOn(POINT point);
	void press(POINT mouse, Piece* held);
	POINT getPos();
	bool addPiece(Piece* piece);
	void setPiece(Piece* piece);
	Piece* getPiece();
};

