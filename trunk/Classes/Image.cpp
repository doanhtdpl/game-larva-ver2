#include "Image.h"


Image::Image()
{

}

Image::Image( vector<string> arr)
{
	//id = atoi(arr[0].c_str());
	filename = strdup(arr[1].c_str());
	//ScaleX = atoi(arr[2].c_str());
	//ScaleY =  atoi(arr[3].c_str());
}

char* Image::getFileName()
{
	return filename;
}

float Image::getScaleX()
{
	return ScaleX;
}

float Image::getScaleY()
{
	return ScaleY;
}

Image::~Image()
{

}