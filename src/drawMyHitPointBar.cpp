#include <common.hpp>

void drawPlayerHitPointBar(int c)
{
	const float shininess[] = {25.0};
	glPushMatrix();
	const float ambient[]  = {0.6, 0.6, 0.6, 1.0};
	const float diffuse[]  = {0.6, 0.6, 0.6, 1.0};
	const float specular[] = {0.6, 0.6, 0.6, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glBegin(GL_POLYGON);
	glVertex3f(25.3, -1.5, -8.0);
	glVertex3f(9.7, -1.5, -8.0);
	glVertex3f(9.7, -5.5, -8.0);
	glVertex3f(25.3, -5.5, -8.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	const float ambient1[]  = {0.0, 0.0, 0.0, 1.0};
	const float diffuse1[]  = {0.0, 0.0, 0.0, 1.0};
	const float specular1[] = {0.0, 0.0, 0.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glBegin(GL_POLYGON);
	glVertex3f(25.0, -2.0, -7.0);
	glVertex3f(10.0, -2.0, -7.0);
	glVertex3f(10.0, -5.0, -7.0);
	glVertex3f(25.0, -5.0, -7.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	const float ambient2[]  = {0.5, 0.2, 0.6, 1.0};
	const float diffuse2[]  = {0.5, 0.3, 0.6, 1.0};
	const float specular2[] = {0.4, 0.3, 0.6, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse2);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glBegin(GL_POLYGON);
	glVertex3f(25 - c * 3, -2.0, -5.0);
	glVertex3f(10.0, -2.0, -5.0);
	glVertex3f(10.0, -5.0, -5.0);
	glVertex3f(25 - c * 3, -5.0, -5.0);
	glEnd();
	glPopMatrix();
}
