#include <common.hpp>

void drawOctahedron(const float *a, const float *d, const float *s)
{
	const float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidOctahedron();
}
