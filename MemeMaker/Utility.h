#pragma once

#include <glut.h>
#include <iostream>
#include <windows.h>
#include <string.h>
#include "Config.h"

class Utility
{
public: 
	//Dùng để in một dòng text với font đã được cài đặt sẵn
	static void printText(const std::string& Input);

	//Dùng để đọc ảnh, lúc hiển thị thì sẽ dùng hàm "display" ở MemeMaker.cpp
	static void ReadImage();

	//Áp dụng convolution ở đây
	static void Filter(float ImageMatrix[1000][1000], float Kernel[3][3]);
};
