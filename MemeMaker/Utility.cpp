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

void Utility::ReadImage()
{
	// Create texture index array.
	glGenTextures(1, textures);

	// Load the texture.
	image = BitMap::loadTexture("Images/1.bmp");

	// TO-DO: Activate texture index texture[0]. 
	glBindTexture(GL_TEXTURE_2D, textures[0]);

	// TO-DO: Set texture parameters for wrapping.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// TO-DO: Set texture parameters for filtering.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	// TO-DO: Specify an image as the texture to be bound with the currently active texture index.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->data);

	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image->sizeX, image->sizeY, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	
	//Turn on OpenGL texturing.
	glEnable(GL_TEXTURE_2D);

	// Specify how texture values combine with current surface color values.
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

void Utility::DisplayImage()
{
	ReadImage();

	glBindTexture(GL_TEXTURE_2D, 1);  // Activate a texture.

	glBegin(GL_QUADS);
	// sets the current texture coordinates
	// any subsequent vertex command has those texture coordinates associated with it
	// until glTexCoord2f is called again
	glTexCoord2f(0, 0); glVertex2f(0, 50);  // TO-DO: fix tex coord
	glTexCoord2f(0, 1); glVertex2f(0, 500);  // TO-DO: fix tex coord
	glTexCoord2f(1, 1); glVertex2f(500, 500);  // TO-DO: fix tex coord
	glTexCoord2f(1, 0); glVertex2f(500, 50);  // TO-DO: fix tex coord
	glEnd();
}

void Utility::Filter()
{
	/*GLfloat laplacian[3][3] = {
		 { -0.125, -0.125, -0.125 },
		 { -0.125, 1.0, -0.125 },
		 { -0.125, -0.125, -0.125 }
	};

	glConvolutionFilter2D(GL_CONVOLUTION_2D, GL_RGB, 3, 3, GL_RGB, GL_FLOAT, laplacian);
	glEnable(GL_CONVOLUTION_2D);*/
}

