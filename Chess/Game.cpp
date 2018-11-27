#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	int x;
	int y;
	int n;
	unsigned char * rook_image = stbi_load("Rook.png", &x, &y, &n, 0);
	std::map<std::string, unsigned char *> images;
	images.insert(std::pair<std::string, unsigned char *>("Rook", rook_image));
	this->board = Board(images);
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

void Game::left_button_down(POINT mouse_position)
{
	this->board.press(mouse_position);
}

void Game::left_button_up(POINT mouse_position)
{
}
