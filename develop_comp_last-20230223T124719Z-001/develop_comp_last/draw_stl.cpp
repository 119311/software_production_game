#include "./common.h"
#include <stdio.h>

void draw_stl(float *a, float *d, float *s)
{
	static int state;
	float      ambient[]   = {0.3, 0.3, 0.0, 1.0};
	float      diffuse[]   = {0.7, 0.7, 0.0, 1.0};
	float      specular[]  = {1.0, 1.0, 1.0, 1.0};
	float      shininess[] = {25.0};
	int        i, j;

	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	for (i = 0; i < trinum; i++)
	{
		glBegin(GL_POLYGON);
		glNormal3f(nv[i].x, nv[i].y, nv[i].z);
		glVertex3f(po[i][0].x, po[i][0].y, po[i][0].z);
		glVertex3f(po[i][1].x, po[i][1].y, po[i][1].z);
		glVertex3f(po[i][2].x, po[i][2].y, po[i][2].z);
		glEnd();
	}
}
