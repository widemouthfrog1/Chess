#pragma once
#include "Board.h"
class Game
{
	Board board = Board();
public:
	Game();
	~Game();
	void draw(HDC canvas, PAINTSTRUCT paint_struct);
};

