#pragma once
#include "Tile.h"
class Piece
{
public:

	virtual ~Piece();
	virtual void move(Tile tile) = 0;
	virtual std::vector<POINT> avaiable_moves() = 0;

};

