#include <common.hpp>
void mouseProc(int button, int state, int x, int v)
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			mouseFlag = 1;
			tx        = (x - WINDOW_HEIGHT / 2) / XRATE;
		} else
			mouseFlag = 0;
	}
	glutPostRedisplay();
}
