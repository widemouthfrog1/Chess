#pragma once
#include "Tile.h"
class Tile;

class Piece:
	std::enable_shared_from_this<Piece>
{
protected:
	
	bool white;
	POINT pos;
public:
	std::shared_ptr<Image> image;
	virtual ~Piece();
	virtual void move(Tile before, Tile after);
	virtual void draw(Graphics* canvas);
	void setPosition(POINT pos);
	void setPosition(Tile tile);
	void press(POINT mousePos);
	void drag(POINT mousePos);
	bool isWhite();

};

