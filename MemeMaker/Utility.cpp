#include "Utility.h"
#include "Text.h"
#include "BitMap.h"

Text* text = new Text();
BitMap* image = new BitMap();
unsigned int textures[1];

const GLfloat Config::edgeDetection[3][3] = {
		 { -1, -1, -1 },
		 { -1, 8, -1 },
		 { -1, -1, -1 }
};

const GLfloat Config::blur[3][3] = {
		 { 0.1111, 0.1111, 0.1111 },
		 { 0.1111, 0.1111, 0.1111 },
		 { 0.1111, 0.1111, 0.1111 }
};

const GLfloat Config::sharpen[3][3] = {
		 { 0, -1, 0 },
		 { -1, 5, -1 },
		 { 0, -1, 0 }
};

const GLfloat Config::bright[3][3] = {
		 { 0, 0.5, 0 },
		 { 0.5, 1, 0.5 },
		 { 0, 0.5, 0 }
};

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
	int length = Config::WINDOW_WIDTH / 2 - Input.length() * 6;
	for (std::string x : sentence)
	{
		glRasterPos2i(length, 10);
		text->generateText(x);
		length += x.length()*8 + (x.length() - 1) * 8 + 15;
	}
}

void Utility::DisplayImage(const std::string& Input)
{
	image = BitMap::loadTexture(Input);
	glRasterPos2i(0, 40);
	glDrawPixels(image->sizeX, image->sizeY, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	glFlush();
}

void Utility::Filter(Config::Filter FilterType)
{
	switch (FilterType)
	{
	case Config::Filter::EDGE_DETECTION:
		glConvolutionFilter2D(GL_CONVOLUTION_2D, GL_LUMINANCE, 3, 3, GL_LUMINANCE, GL_FLOAT, Config::edgeDetection);
		break;
	case Config::Filter::BLUR:
		glConvolutionFilter2D(GL_CONVOLUTION_2D, GL_LUMINANCE, 3, 3, GL_LUMINANCE, GL_FLOAT, Config::blur);
		break;
	case Config::Filter::SHARPEN:
		glConvolutionFilter2D(GL_CONVOLUTION_2D, GL_LUMINANCE, 3, 3, GL_LUMINANCE, GL_FLOAT, Config::sharpen);
		break;
	case Config::Filter::BRIGHT:
		glConvolutionFilter2D(GL_CONVOLUTION_2D, GL_LUMINANCE, 3, 3, GL_LUMINANCE, GL_FLOAT, Config::bright);
		break;
	default:
		break;
	}

	glEnable(GL_CONVOLUTION_2D);
}

