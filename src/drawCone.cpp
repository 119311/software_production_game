#include <common.hpp>

void drawCone(const float *a, const float *d, const float *s)
{
	const float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidCone(6.0, 15.0, 20, 20);
}
