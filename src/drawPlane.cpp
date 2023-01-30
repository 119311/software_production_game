#include <common.hpp>

void drawPlane(void)
{
	glBegin(GL_POLYGON);
	glVertex3f(-25.0, 42.0, 20.0);
	glVertex3f(-10.0, 42.0, 20.0);
	glVertex3f(-10.0, +45.0, 20.0);
	glVertex3f(-25.0, +45.0, 20.0);
	glEnd();
}
