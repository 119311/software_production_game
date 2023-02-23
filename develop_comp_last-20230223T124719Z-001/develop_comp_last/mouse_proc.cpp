#include "common.h"

void mouse_proc(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			mouse_flag   = 1;
			myChara.posx = (x - X_SIZE / 2) / XRATE;
		} else
			mouse_flag = 0;
	}
	glutPostRedisplay();
}

void motion_proc(int x, int y)
{
	myChara.posx = (x - X_SIZE / 2) / XRATE;
	glutPostRedisplay();
}
