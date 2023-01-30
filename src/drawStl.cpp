#include <common.hpp>
void drawStl(const float *a, const float *d, const float *s, point po[][3], point nv[], int trinum)
{
	const float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	for (int i = 0; i < trinum; i++)
	{
		glBegin(GL_POLYGON);
		glNormal3f(-nv[i].x, -nv[i].y, -nv[i].z);
		glVertex3f(po[i][0].x, po[i][0].y, po[i][0].z);
		glVertex3f(po[i][1].x, po[i][1].y, po[i][1].z);
		glVertex3f(po[i][2].x, po[i][2].y, po[i][2].z);
		glEnd();
	}
}
