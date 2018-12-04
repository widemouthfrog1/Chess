#pragma once
#include "Board.h"
#include "ImageLoader.h"
class Game
{
	Board board = Board();
public:
	Game();
	~Game();
	void draw(Graphics* canvas, PAINTSTRUCT paint_struct);
	void press(POINT mouse);
	void drag(POINT mouse);
	void release(POINT mouse);
	void load_images();
};

