#pragma once
class ImageLoader
{
	std::map<std::string, std::shared_ptr<Image>> images;
public:


	ImageLoader();
	~ImageLoader();
	std::map<std::string, std::shared_ptr<Image>> getImageMap();
};

