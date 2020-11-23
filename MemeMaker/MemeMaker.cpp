#include "Utility.h"
static GLdouble zoomFactor = 1.0;
static GLint height;

void display()
{	
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	//Hiển thị text với font định sẵn
	GLfloat white[3] = { 1.0, 1.0, 1.0 };
	glColor3fv(white);
	Utility::printText("MEME IN A NUTSHELL");
	glFlush();

	//Viết hàm để hiển thị ảnh ở đây
	Utility::DisplayImage("Images/3.bmp");
}

void reshape(int w, int h)
{
	glutReshapeWindow(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);  // Sets the shading model
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 49:
		Utility::Filter(Config::Filter::BLUR);
		break;
	case 50:
		Utility::Filter(Config::Filter::EDGE_DETECTION);
		break;
	case 51:
		Utility::Filter(Config::Filter::SHARPEN);
		break;
	case 52:
		Utility::Filter(Config::Filter::BRIGHT);
		break;
	case 53:
		Utility::Filter(Config::Filter::INVERT);
		break;
	case 27:
		exit(EXIT_SUCCESS);
		break;

	case 'r':
		zoomFactor = 1.0;
		break;
	case 'z':
		zoomFactor += 0.5;
		break;
	case 'Z':
		zoomFactor -= 0.5;
		break;

	default:
		glDisable(GL_CONVOLUTION_2D);
		glDisable(GL_POST_CONVOLUTION_COLOR_TABLE);
	}

	glutPostRedisplay();
}

void motion(int x, int y)
{
	static GLint screeny;
	screeny = height - (GLint)y;
	glRasterPos2i(x, screeny);
	glPixelZoom(zoomFactor, zoomFactor);
	glCopyPixels(0, 0, 512, 512, GL_COLOR);
	glPixelZoom(1.0, 2.0);
	glFlush();
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
	glutKeyboardFunc(keyboard);
	glutMotionFunc(motion);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}