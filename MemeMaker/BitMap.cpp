#include "BitMap.h"

BitMap* BitMap::loadTexture(std::string filename)
{
	BitMap* bmp = new BitMap();
	unsigned int size, offset, headerSize;

	// Read input file name.
	std::ifstream infile(filename.c_str(), std::ios::binary);

	// Get the starting point of the image data.
	infile.seekg(10);
	infile.read((char*)&offset, 4);

	// Get the header size of the bitmap.
	infile.read((char*)&headerSize, 4);



	// Get width and height values in the bitmap header.
	infile.seekg(18);
	infile.read((char*)&bmp->sizeX, 4);
	infile.read((char*)&bmp->sizeY, 4);



	// Allocate buffer for the image.
	size = bmp->sizeX * bmp->sizeY * 24;
	bmp->data = new unsigned char[size];



	// Read bitmap data.
	infile.seekg(offset);
	infile.read((char*)bmp->data, size);

	// Reverse color from bgr to rgb.
	int temp;
	for (int i = 0; i < size; i += 3)
	{
		temp = bmp->data[i];
		bmp->data[i] = bmp->data[i + 2];
		bmp->data[i + 2] = temp;
	}

	return bmp;
}

void BitMap::displayTexture()
{

}
