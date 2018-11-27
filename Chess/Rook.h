#pragma once
#include "Piece.h"
class Rook :
	public Piece
	
{
public:
	Rook(unsigned char ** image_address, bool white);
	~Rook();
};

