#include <common.hpp>

void playerCircle(const float r, int n)
{
	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; i++)
	{
		glVertex3f(r * cos(PI2 / n * i), 0, r * sin(PI2 / n * i));
	}
	glEnd();
	glPopMatrix();
}
