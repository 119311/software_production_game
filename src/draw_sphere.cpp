#include <common.hpp>
void drawSphere(float *a, float *d, float *s)
{
	float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidSphere(5., 30, 30);
}
