#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	//Image* rook_image = Image::FromFile(L"C:\\Users\\Karl Bennett\\source\\repos\\Chess\\Chess\\Rook.png", 0);
	
}


Game::~Game()
{
	board.~Board();
}

void Game::draw(Graphics* canvas, PAINTSTRUCT paint_struct)
{
	//HBRUSH background_colour = CreateSolidBrush(RGB(200,200,200));
	canvas->FillRectangle(
		&SolidBrush(Color(200, 200, 200)),
		*(&paint_struct.rcPaint.left),
		*(&paint_struct.rcPaint.top), 
		*(&paint_struct.rcPaint.right) - *(&paint_struct.rcPaint.left), 
		*(&paint_struct.rcPaint.bottom) - *(&paint_struct.rcPaint.top)
	);
	this->board.draw(canvas);
}

void Game::press(POINT mouse)
{
	this->board.press(mouse);
}

void Game::drag(POINT mouse)
{
	this->board.drag(mouse);
}

void Game::release(POINT mouse)
{
}

void Game::load_images()
{
	ImageLoader loader;
	//this->board = Board(loader.getImageMap());
	this->board = Board(loader.getImageMap());
}
