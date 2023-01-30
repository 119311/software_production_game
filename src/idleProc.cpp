#include <common.hpp>

void idleProc(void)
{
	rotY += 3.0;
	if (rotY >= 360.0)
		rotY -= 360.0;
	glutPostRedisplay();
}
