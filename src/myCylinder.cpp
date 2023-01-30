#include <common.hpp>

void playerSolidCylinder(const float r, const float h, int n)
{

	glEnable(GL_NORMALIZE);
	glPushMatrix();
	glRotatef(-PI2 / n * 180.0 / PI2, 0.0, 0.1, 0.0);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= n; i += 1)
	{
		glNormal3f(r * cos(PI2 / n * i), 0, r * sin(PI2 / n * i));
		glVertex3f(r * cos(PI2 / n * i), 0.5 * h, r * sin(PI2 / n * i));
		glVertex3f(r * cos(PI2 / n * i), -0.5 * h, r * sin(PI2 / n * i));
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, -1.0, 0.0);
	for (int i = 0; i < n; i += 1)
	{
		glVertex3f(r * cos(PI2 / n * i), -0.5 * h, r * sin(PI2 / n * i));
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	for (int i = 0; i < n; i += 1)
	{
		glVertex3f(r * cos(PI2 / n * i), 0.5 * h, r * sin(PI2 / n * i));
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_NORMALIZE);
}
