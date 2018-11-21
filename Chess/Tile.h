#pragma once
class Tile
{
	int colour;
	int x;
	int y;
public:
	const static int SIZE = 50;
	const static int EMPTY = -1;
	const static int HIGHLIGHTED = 2;
	Tile(int x, int y, int colour);
	~Tile();

	void draw(HDC canvas);
};

