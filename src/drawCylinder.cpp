#include <common.hpp>

void drawCylinder(const float *a, const float *d, const float *s)
{
	const float shininess[] = {50.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	SolidCylinder(3.0, 8.0, 20);
}
