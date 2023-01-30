#include <common.hpp>

void drawEnemyHitPointBar(int c)
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
	glVertex3f(-25.3, 41.5, -8.0);
	glVertex3f(-9.7, 41.5, -8.0);
	glVertex3f(-9.7, 45.5, -8.0);
	glVertex3f(-25.3, 45.5, -8.0);
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
	glVertex3f(-25.0, 42.0, -7.0);
	glVertex3f(-10.0, 42.0, -7.0);
	glVertex3f(-10.0, 45.0, -7.0);
	glVertex3f(-25.0, 45.0, -7.0);
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
	glVertex3f(-25.0 + c * 0.15, 42.0, -5.0);
	glVertex3f(-10.0, 42.0, -5.0);
	glVertex3f(-10.0, +45.0, -5.0);
	glVertex3f(-25.0 + c * 0.15, +45.0, -5.0);
	glEnd();
	glPopMatrix();
}
