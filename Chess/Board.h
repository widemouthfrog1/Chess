#pragma once
#include "Tile.h"
class Board
{
	std::vector<std::vector<Tile>> tiles;//Two dimensional vector for storing Tiles
	int x;
	int y;
	Piece* held = NULL;
	std::vector<Piece> pieces;
public:
	Board(std::map<std::string, unsigned char *> images);
	//These following constructors are for creating chess-like games with a different sized board 
	Board(int size, std::map<std::string, unsigned char *> images);
	Board(int width, int height, std::map<std::string, unsigned char *> images);
	//This constructor also accommodates boards with a different shape (not simply a square or rectangle) 
	Board(std::vector<std::vector<Tile>> tiles, std::map<std::string, unsigned char *> images);
	~Board();

	void draw(HDC canvas);
	void press(POINT mouse);
	void drag(POINT mouse);
	void release(POINT mouse);
	bool addPiece(Piece* piece, Tile* tile);
	void setPiece(Piece* piece, Tile* tile);
};

