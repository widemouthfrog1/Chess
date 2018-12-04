#pragma once
#include "Tile.h"
class Board
{
	std::vector<std::vector<std::shared_ptr<Tile>>> tiles;//Two dimensional vector for storing Tiles
	int x;
	int y;
	std::shared_ptr<Piece> held;
	std::vector<std::shared_ptr<Piece>> pieces;
public:
	Board();
	Board(std::map<std::string, std::shared_ptr<Image>> images);
	//These following constructors are for creating chess-like games with a different sized board 
	Board(int size, std::map<std::string, std::shared_ptr<Image>> images);
	Board(int width, int height, std::map<std::string, std::shared_ptr<Image>> images);
	//This constructor also accommodates boards with a different shape (not simply a square or rectangle) 
	Board(std::vector<std::vector<std::shared_ptr<Tile>>> tiles, std::map<std::string, std::shared_ptr<Image>> images);
	~Board();


	void draw(Graphics* canvas);
	void press(POINT mouse);
	void drag(POINT mouse);
	void release(POINT mouse);
	bool addPiece(std::shared_ptr<Piece> piece, Tile* tile);
	void setPiece(std::shared_ptr<Piece> piece, Tile* tile);
};

