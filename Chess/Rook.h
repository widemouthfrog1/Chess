#pragma once
#include "Piece.h"
class Rook :
	public Piece
	
{
public:
	Rook(std::shared_ptr<Image> image_address, bool white, POINT pos);
	~Rook();
};

