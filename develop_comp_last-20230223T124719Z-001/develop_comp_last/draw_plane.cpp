#include "./common.h"

void draw_plane()
{
	glBegin(GL_POLYGON);
	glVertex3f(-25.0, 42.0, 20.0);
	glVertex3f(-10.0, 42.0, 20.0);
	glVertex3f(-10.0, +45.0, 20.0);
	glVertex3f(-25.0, +45.0, 20.0);
	glEnd();
}

void draw_teki_HPbar(int c)
{
	float ambient[4], diffuse[4], specular[4];
	float shininess[] = {25.0};
	float a;

	if (Lunatic_flag != 1)    // normal Mode
		a = 15.0 / TEKIDUR;
	else
		a = 15.0 / (TEKIDUR * 2);    // Lunatic Mode

	// HPバーのフレーム
	glPushMatrix();

	ambient[0]  = 0.8;
	ambient[1]  = 0.8;
	ambient[2]  = 0.8;
	ambient[3]  = 1.0;
	diffuse[0]  = 0.8;
	diffuse[1]  = 0.8;
	diffuse[2]  = 0.8;
	diffuse[3]  = 1.0;
	specular[0] = 0.8;
	specular[1] = 0.8;
	specular[2] = 0.8;
	specular[3] = 1.0;

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

	// HPバー底
	glPushMatrix();

	ambient[0]  = 0.0;
	ambient[1]  = 0.0;
	ambient[2]  = 0.0;
	ambient[3]  = 1.0;
	diffuse[0]  = 0.0;
	diffuse[1]  = 0.0;
	diffuse[2]  = 0.0;
	diffuse[3]  = 1.0;
	specular[0] = 0.0;
	specular[1] = 0.0;
	specular[2] = 0.0;
	specular[3] = 1.0;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glBegin(GL_POLYGON);

	glVertex3f(-25.0, 42.0, -7.0);
	glVertex3f(-10.0, 42.0, -7.0);
	glVertex3f(-10.0, 45.0, -7.0);
	glVertex3f(-25.0, 45.0, -7.0);
	glEnd();
	glPopMatrix();

	// HPバー本体
	glPushMatrix();

	ambient[0]  = 0.9;
	ambient[1]  = 0.6;
	ambient[2]  = 1.0;
	ambient[3]  = 1.0;
	diffuse[0]  = 0.9;
	diffuse[1]  = 0.7;
	diffuse[2]  = 1.0;
	diffuse[3]  = 1.0;
	specular[0] = 0.8;
	specular[1] = 0.7;
	specular[2] = 1.0;
	specular[3] = 1.0;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glBegin(GL_POLYGON);
	glVertex3f(-25.0 + (c * a), 42.0, -5.0);
	glVertex3f(-10.0, 42.0, -5.0);
	glVertex3f(-10.0, +45.0, -5.0);
	glVertex3f(-25.0 + (c * a), +45.0, -5.0);
	glEnd();
	glPopMatrix();
}

void draw_my_HPbar(int c)
{
	float ambient[4], diffuse[4], specular[4];
	float shininess[] = {25.0};
	float a;
	a = 15.0 / MYDUR;

	// HPバーのフレーム
	glPushMatrix();

	ambient[0]  = 0.8;
	ambient[1]  = 0.8;
	ambient[2]  = 0.8;
	ambient[3]  = 1.0;
	diffuse[0]  = 0.8;
	diffuse[1]  = 0.8;
	diffuse[2]  = 0.8;
	diffuse[3]  = 1.0;
	specular[0] = 0.8;
	specular[1] = 0.8;
	specular[2] = 0.8;
	specular[3] = 1.0;

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

	// HPバー底
	glPushMatrix();

	ambient[0]  = 0.0;
	ambient[1]  = 0.0;
	ambient[2]  = 0.0;
	ambient[3]  = 1.0;
	diffuse[0]  = 0.0;
	diffuse[1]  = 0.0;
	diffuse[2]  = 0.0;
	diffuse[3]  = 1.0;
	specular[0] = 0.0;
	specular[1] = 0.0;
	specular[2] = 0.0;
	specular[3] = 1.0;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glBegin(GL_POLYGON);

	glVertex3f(25.0, -2.0, -7.0);
	glVertex3f(10.0, -2.0, -7.0);
	glVertex3f(10.0, -5.0, -7.0);
	glVertex3f(25.0, -5.0, -7.0);
	glEnd();
	glPopMatrix();

	// HPバー本体
	glPushMatrix();

	ambient[0]  = 0.0;
	ambient[1]  = 2.0;
	ambient[2]  = 0.0;
	ambient[3]  = 1.0;
	diffuse[0]  = 0.0;
	diffuse[1]  = 2.0;
	diffuse[2]  = 0.0;
	diffuse[3]  = 1.0;
	specular[0] = 0.0;
	specular[1] = 2.0;
	specular[2] = 0.0;
	specular[3] = 1.0;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glBegin(GL_POLYGON);

	glVertex3f(25 - (c * a), -2.0, -5.0);    //倍数は (HPバーのながさ 15）/MYDUR で決定
	glVertex3f(10.0, -2.0, -5.0);
	glVertex3f(10.0, -5.0, -5.0);
	glVertex3f(25 - (c * a), -5.0, -5.0);
	glEnd();
	glPopMatrix();
}

void draw_mischarge(int c)
{
	float ambient[4], diffuse[4], specular[4];
	float shininess[] = {25.0};

	//チャージバーのフレーム
	glPushMatrix();

	ambient[0]  = 0.8;
	ambient[1]  = 0.8;
	ambient[2]  = 0.8;
	ambient[3]  = 1.0;
	diffuse[0]  = 0.8;
	diffuse[1]  = 0.8;
	diffuse[2]  = 0.8;
	diffuse[3]  = 1.0;
	specular[0] = 0.8;
	specular[1] = 0.8;
	specular[2] = 0.8;
	specular[3] = 1.0;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glBegin(GL_POLYGON);

	glVertex3f(25.3, 0.5, -8.0);
	glVertex3f(9.7, 0.5, -8.0);
	glVertex3f(9.7, -1.5, -8.0);
	glVertex3f(25.3, -1.5, -8.0);
	glEnd();
	glPopMatrix();

	//チャージバー底
	glPushMatrix();

	ambient[0]  = 0.0;
	ambient[1]  = 0.0;
	ambient[2]  = 0.0;
	ambient[3]  = 1.0;
	diffuse[0]  = 0.0;
	diffuse[1]  = 0.0;
	diffuse[2]  = 0.0;
	diffuse[3]  = 1.0;
	specular[0] = 0.0;
	specular[1] = 0.0;
	specular[2] = 0.0;
	specular[3] = 1.0;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glBegin(GL_POLYGON);

	glVertex3f(25.0, 0.0, -7.0);
	glVertex3f(10.0, 0.0, -7.0);
	glVertex3f(10.0, -1.0, -7.0);
	glVertex3f(25.0, -1.0, -7.0);
	glEnd();
	glPopMatrix();

	//チャージバー本体
	glPushMatrix();

	ambient[0]  = 0.8;
	ambient[1]  = 1.1;
	ambient[2]  = 1.3;
	ambient[3]  = 1.0;
	diffuse[0]  = 0.8;
	diffuse[1]  = 1.1;
	diffuse[2]  = 1.3;
	diffuse[3]  = 1.0;
	specular[0] = 0.8;
	specular[1] = 1.1;
	specular[2] = 1.3;
	specular[3] = 1.0;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glBegin(GL_POLYGON);

	glVertex3f(10 + (c * 1.5), 0.0, -5.0);
	glVertex3f(10.0, 0.0, -5.0);
	glVertex3f(10.0, -1.0, -5.0);
	glVertex3f(10 + (c * 1.5), -1.0, -5.0);
	glEnd();
	glPopMatrix();
}

void draw_plane_with_texture(int i)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, i);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-5.0, -5.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(+5.0, -5.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(+5.0, +5.0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-5.0, +5.0, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
