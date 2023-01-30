#include <common.hpp>

void playerDisc(const float r, int n)
{

	glEnable(GL_NORMALIZE);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	for (int i = 0; i < n; i += 1)
	{
		glVertex3f(r * cos(PI2 / n * i), 0.0, r * sin(PI2 / n * i));
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_NORMALIZE);
}
