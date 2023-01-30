#include <common.hpp>

void initLightSettings(void)
{
	const float ambient[]  = {0.5, 0.5, 0.5, 1.0};
	const float diffuse[]  = {0.7, 0.7, 0.7, 1.0};
	const float specular[] = {1.0, 1.0, 1.0, 1.0};
	const float position[] = {10.0, 5.0, 10.0, 0.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
