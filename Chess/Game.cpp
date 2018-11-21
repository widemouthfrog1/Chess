#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	this->board = Board();
}


Game::~Game()
{
}

void Game::draw(HDC canvas, PAINTSTRUCT paint_struct)
{
	HBRUSH background_colour = CreateSolidBrush(RGB(200,200,200));
	FillRect(canvas, &paint_struct.rcPaint, background_colour);
	this->board.draw(canvas);
}
