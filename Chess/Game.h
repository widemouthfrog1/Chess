#pragma once
#include "Board.h"
class Game
{
	Board board = Board();
public:
	Game();
	~Game();
	void draw(HDC canvas, PAINTSTRUCT paint_struct);
	void left_button_down(POINT mouse_position);
	void left_button_up(POINT mouse_position);
};

