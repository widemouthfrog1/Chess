#pragma once
#include "Tile.h"
class Board
{
	std::vector<std::vector<Tile>> tiles;//Two dimensional vector for storing Tiles
	int x;
	int y;
public:
	Board();
	//These following constructors are for creating chess-like games with a different sized board 
	Board(int size);
	Board(int width, int height);
	//This constructor also accommodates boards with a different shape (not simply a square or rectangle) 
	Board(std::vector<std::vector<Tile>> tiles);
	~Board();

	void draw(HDC canvas);
	void left_button_down(POINT mouse_position);
	void left_button_up(POINT mouse_position);
};

