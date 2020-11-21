#include "Utility.h"

void init()
{	
	glShadeModel(GL_FLAT);
}

void display()
{
	GLfloat white[3] = { 1.0, 1.0, 1.0 };
	glClear(GL_COLOR_BUFFER_BIT);
	//Viết hàm để hiển thị ảnh ở đây

	//Viết hàm filter ảnh ở đây

	//Hiển thị text với font định sẵn
	glColor3fv(white);
		Utility::printText("THIS IS A MEME");
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT);
	glutInitWindowPosition(Config::WINDOW_POSITION_X, Config::WINDOW_POSITION_Y);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}