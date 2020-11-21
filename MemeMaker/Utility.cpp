﻿#include "Utility.h"
#include "Text.h"
#include <vector>

using namespace std;

void Utility::printText(const std::string& Input)
{
	Text* text = new Text();
	text->makeRasterFont();
	
	//Tách từng từ ra khỏi câu
	string word = "";
	vector<string> sentence;
	for (auto x : Input)
	{
		if (x == ' ')
		{
			sentence.push_back(word);
			word = "";
		}
		else {
			word = word + x;
		}
	}
	sentence.push_back(word);

	//Tạo text
	int length = Config::WINDOW_WIDTH / 2 - Input.length() * 8;
	for (string x : sentence)
	{
		glRasterPos2i(length, 25);
		text->generateText(x);
		length += x.length()*8 + (x.length() - 1) * 4;
	}

}
