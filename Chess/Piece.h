#pragma once
#include "Tile.h"
class Piece
{
protected:
	unsigned char ** image;
	bool white;
	POINT pos;
public:

	virtual ~Piece();
	virtual void move(Tile before, Tile after) = 0;
	virtual void draw(HDC canvas);
	void setPosition(POINT pos);
	void setPosition(Tile tile);
	void press(POINT mousePos);
	void drag(POINT mousePos);
	bool isWhite();

};

