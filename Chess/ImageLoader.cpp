#include "stdafx.h"
#include "ImageLoader.h"


ImageLoader::ImageLoader()
{
	std::shared_ptr<Image> rook_image = std::make_shared<Image>(L"C:\\Users\\Karl Bennett\\source\\repos\\Chess\\Chess\\Rook.png");
	UINT width = rook_image->GetWidth();
	UINT height = rook_image->GetHeight();
	this->images.insert(std::pair<std::string, std::shared_ptr<Image>>("Rook", rook_image));
}


ImageLoader::~ImageLoader()
{
}

std::map<std::string, std::shared_ptr<Image>> ImageLoader::getImageMap()
{	
	return this->images;
}
