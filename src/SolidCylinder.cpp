#include <common.hpp>
void SolidCylinder(double r, double h, int n)
{
	double x, y, z, dq;
	int    i;
	glEnable(GL_NORMALIZE);
	dq = (2.0 * M_PI) / n;
	y  = 0.5 * h;
	glPushMatrix();
	glRotatef(-dq * 180.0 / (2.0 * M_PI), 0.0, 0.1, 0.0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= n; i += 1)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glNormal3f(x, 0, z);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, -1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glVertex3f(x, y, z);
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_NORMALIZE);
}
