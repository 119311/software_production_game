#include <common.hpp>

void playerStl1(point po[][3], point nv[], int trinum)
{
	const float ambient[]  = {0.7, 0.0, 0.0, 1.0};
	const float diffuse[]  = {0.7, 0.0, 0.0, 1.0};
	const float specular[] = {1.0, 1.0, 1.0, 1.0};
	glPushMatrix();
	glEnable(GL_NORMALIZE);
	glScalef(0.1, 0.1, 0.1);
	drawStl(ambient, diffuse, specular, po, nv, trinum);
	glPopMatrix();
}
