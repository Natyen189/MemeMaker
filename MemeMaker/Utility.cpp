#include "Utility.h"
#include "Text.h"
#include "BitMap.h"

Text* text = new Text();
BitMap* image = new BitMap();
unsigned int textures[1];

void Utility::printText(const std::string& Input)
{
	text->makeRasterFont();
	
	//Tách từng từ ra khỏi câu
	std::string word = "";
	std::vector<std::string> sentence;
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
	for (std::string x : sentence)
	{
		glRasterPos2i(length, 10);
		text->generateText(x);
		length += x.length()*8 + (x.length() - 1) * 8 + 15;
	}
}

void Utility::DisplayImage()
{
	image = BitMap::loadTexture("Images/1.bmp");
	glRasterPos2i(0, 40);
	glDrawPixels(image->sizeX, image->sizeY, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	glFlush();
}

void Utility::Filter()
{
	GLfloat laplacian[3][3] = {
		 { -1, -1, -1 },
		 { -1, 8, -1 },
		 { -1, -1, -1 }
	};

	glConvolutionFilter2D(GL_CONVOLUTION_2D, GL_RGB, 3, 3, GL_RGB, GL_FLOAT, laplacian);
	glEnable(GL_CONVOLUTION_2D);
}

