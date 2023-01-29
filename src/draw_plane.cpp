#include <common.hpp>

void draw_plane()
{
	glBegin(GL_POLYGON);
	glVertex3f(-10.0, -10.0, 0.0);
	glVertex3f(+10.0, -10.0, 0.0);
	glVertex3f(+10.0, +10.0, 0.0);
	glVertex3f(-10.0, +10.0, 0.0);
	glEnd();
}
