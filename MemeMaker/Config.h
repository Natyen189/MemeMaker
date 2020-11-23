#pragma once

class Config
{
public:
	const static int WINDOW_HEIGHT = 500;
	const static int WINDOW_WIDTH = 500;

	const static int WINDOW_POSITION_X = 710;
	const static int WINDOW_POSITION_Y = 290;

	enum Filter
	{
		NONE,
		EDGE_DETECTION,
		BLUR,
		SHARPEN,
		BRIGHT,
		INVERT,
	};

	const static GLfloat edgeDetection[3][3];

	const static GLfloat blur[3][3];

	const static GLfloat sharpen[3][3];

	const static GLfloat bright[3][3];
};