#pragma once

class Config
{
public:
	const static int WINDOW_HEIGHT = 500;
	const static int WINDOW_WIDTH = 500;

	const static int WINDOW_POSITION_X = 700;
	const static int WINDOW_POSITION_Y = 200;

	enum Filter
	{
		EDGE_DETECTION,
		BLUR,
		SHARPEN,
		NONE,
	};

	const static GLfloat edgeDetection[3][3];

	const static GLfloat blur[3][3];

	const static GLfloat sharpen[3][3];
};