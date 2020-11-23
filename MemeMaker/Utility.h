#pragma once

#include <glew.h>
#include <glut.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <cmath>
#include <vector>
#include <string.h>
#include "Config.h"

class Utility
{
public: 
	//Dùng để in một dòng text với font đã được cài đặt sẵn
	static void printText(const std::string& Input);

	//Dùng để hiển thị ảnh
	static void DisplayImage(const std::string& Input);

	//Áp dụng convolution ở đây
	static void Filter(Config::Filter FilterType);
};
