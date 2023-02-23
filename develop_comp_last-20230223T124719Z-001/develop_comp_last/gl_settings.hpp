#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init_gl_settings()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(MIN_X, MAX_Y, MIN_Y, MAX_Y, MIN_Z, MAX_Z);
	// gluPerspective(80.0, 1.0, 1.0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
}

void init_light_settings()
{
	float ambient[]  = {0.5, 0.5, 0.5, 1.0};
	float diffuse[]  = {0.7, 0.7, 0.7, 1.0};
	float specular[] = {1.0, 1.0, 1.0, 1.0};
	float position[] = {10.0, 5.0, 10.0, 0.0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
