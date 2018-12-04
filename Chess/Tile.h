#pragma once
#include "Piece.h"

class Piece;

class Tile
{
	int colour;
	POINT pos;
	std::shared_ptr<Piece> piece;
public:
	const static int SIZE = 50;
	const static int EMPTY = -1;
	const static int HIGHLIGHTED = 2;
	Tile(POINT pos, int colour);
	~Tile();

	void draw(Graphics* canvas);
	bool isOn(POINT point);
	void press(POINT mouse, std::shared_ptr<Piece>* held);
	POINT getPos();
	bool addPiece(std::shared_ptr<Piece> piece);
	void setPiece(std::shared_ptr<Piece> piece);
	std::shared_ptr<Piece> getPiece();
};

