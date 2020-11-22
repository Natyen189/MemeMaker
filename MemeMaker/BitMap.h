#pragma once

#include "Utility.h"

class BitMap
{
public:
	int sizeX;
	int sizeY;
	unsigned char* data;

	static BitMap* loadTexture(std::string filename);
	void displayTexture();
};