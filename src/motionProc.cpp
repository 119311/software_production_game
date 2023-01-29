#include <common.hpp>

void motionProc(int x, int v)
{
	tx = (x - WINDOW_WIDTH / 2) / XRATE;
	glutPostRedisplay();
}
