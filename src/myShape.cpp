#include <common.hpp>
void myWireCylinder(double r, double h, int n)
{
	double x, y, z, dq;
	int    i;
	dq = (2.0 * M_PI) / n;
	y  = 0.5 * h;
	glPushMatrix();
	glRotatef(-dq * 180.0 / (2.0 * M_PI), 0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	for (i = 0; i < n; i++)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glVertex3f(x, y, z);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glPopMatrix();
}
