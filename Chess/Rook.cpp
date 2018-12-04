#include "stdafx.h"
#include "Rook.h"


Rook::Rook(std::shared_ptr<Image> image, bool white, POINT pos)
{
	this->image = image;
	this->white = white;
	this->pos = pos;
}


Rook::~Rook()
{
}

void Piece::move(Tile before, Tile after) {
	before.setPiece(NULL);
	after.setPiece(shared_from_this());
}

void Piece::draw(Graphics* canvas) {
	UINT width = this->image->GetWidth();
	UINT height = this->image->GetHeight();
	canvas->DrawImage(&(*(this->image)), this->pos.x, this->pos.y, Tile::SIZE, Tile::SIZE);
}




