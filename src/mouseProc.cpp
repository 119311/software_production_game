#include <common.hpp>

void mouseProc(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			mouseFlag   = 1;
			player.posX = (x - WINDOW_WIDTH / 2) / XRATE;
		} else
			mouseFlag = 0;
	}
	glutPostRedisplay();
}
