#include "Utility.h"

void init()
{
	//Viết hàm filter ảnh ở đây
	Utility::Filter();
}

void display()
{	
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	//Hiển thị text với font định sẵn
	GLfloat white[3] = { 1.0, 1.0, 1.0 };
	glColor3fv(white);
	Utility::printText("THIS IS MY FUTURE");
	glFlush();

	//Viết hàm để hiển thị ảnh ở đây
	Utility::DisplayImage();
}

void reshape(int w, int h)
{
	//glutReshapeWindow(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);  // Sets the shading model
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT);
	glutInitWindowPosition(Config::WINDOW_POSITION_X, Config::WINDOW_POSITION_Y);
	glutCreateWindow(argv[0]);
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}