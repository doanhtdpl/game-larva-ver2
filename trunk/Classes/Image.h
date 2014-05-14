#ifndef __IMAGE_H_
#define __IMAGE_H_
#include <string>
#include <vector>
using namespace std;

class Image
{
private:
	int id;
	char* filename;
	float ScaleX;
	float ScaleY;
public:
	Image();
	Image( vector<string> );
	char* getFileName();
	float getScaleX();
	float getScaleY();
	~Image();
};
#endif