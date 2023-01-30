#include <common.hpp>

void playerWireCylinder(const float r, const float h, int n)
{
	glPushMatrix();
	glRotatef(-(2.0 * M_PI) / n * 180.0 / PI2, 0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	for (int i = 0; i < n; i++)
	{
		glVertex3f(r * cos((2.0 * M_PI) / n * i), 0.5 * h, r * sin((2.0 * M_PI) / n * i));
		glVertex3f(r * cos((2.0 * M_PI) / n * i), -0.5 * h, r * sin((2.0 * M_PI) / n * i));
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; i++)
	{
		glVertex3f(r * cos((2.0 * M_PI) / n * i), 0.5 * h, r * sin((2.0 * M_PI) / n * i));
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; i++)
	{
		glVertex3f(r * cos((2.0 * M_PI) / n * i), -0.5 * h, r * sin((2.0 * M_PI) / n * i));
	}
	glEnd();
	glPopMatrix();
}
