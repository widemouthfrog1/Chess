#include "stdafx.h"
#include "Rook.h"


Rook::Rook(unsigned char ** image_address, bool white)
{
	this->image = image_address;
	this->white = white;
}


Rook::~Rook()
{
}

void Piece::move(Tile before, Tile after) {
}

void Piece::draw(HDC canvas) {
	
}




