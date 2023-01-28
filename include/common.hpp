#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <const.hpp>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
struct zokusei
{
	double posx;
	double posy;
	double posz;
	double vx;
	double vy;
	double rotx;
	double roty;
	double rotz;
	int    tflag;
	int    shape;
};

struct point
{
	float x;
	float y;
	float z;
};

extern double         rotx, roty, rotz;
extern double         TX, TY, TZ;
extern int            mouse_flag;
extern int            mv, back_flag;
extern unsigned char  TexImage[TexNum][ImWidth * ImHeight * 3];
extern unsigned char  background[BXsize * BYsize * 3];
extern struct zokusei teki[ENEMY_NUMBER], miss[MISSILE_NUMBER];
extern struct point   po[TRINUM][3], nv[TRINUM];
void                  collision_judge()
{
	for (int j = 0; j < MISSILE_NUMBER; j++)
	{
		for (int i = 0; i < ENEMY_NUMBER; i++)
		{
			double d = sqrt((teki[i].posx - miss[j].posx) * (teki[i].posx - miss[j].posx) + (teki[i].posy - miss[j].posy) * (teki[i].posy - miss[j].posy));
			if (d < DIS)
			{
				teki[i].tflag = 0;
				miss[j].tflag = 0;
				miss[j].posy  = 0.0;
				break;
			}
		}
	}
}
void draw_cone(float *a, float *d, float *s)
{
	float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidCone(6.0, 15.0, 20, 20);
}
void draw_cube(float *a, float *d, float *s)
{
	float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidCube(10.0);
}
void SolidCylinder(double r, double h, int n)
{
	double x, y, z, dq;
	int    i;
	glEnable(GL_NORMALIZE);
	dq = 2.0 * M_PI / (double) n;
	y  = 0.5 * h;
	glPushMatrix();
	glRotatef(-dq * 180.0 / 2.0 * M_PI, 0.0, 0.1, 0.0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= n; i += 1)
	{
		x = r * cos(dq * (double) i);
		z = r * sin(dq * (double) i);
		glNormal3f(x, 0, z);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, -1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * (double) i);
		z = r * sin(dq * (double) i);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * (double) i);
		z = r * sin(dq * (double) i);
		glVertex3f(x, y, z);
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_NORMALIZE);
}
void draw_cylinder(float *a, float *d, float *s)
{
	float shininess[] = {50.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	SolidCylinder(3.0, 8.0, 20);
}
void draw_dodecahedron(float *a, float *d, float *s)
{
	float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidDodecahedron();
}
void draw_icosahedron(float *a, float *d, float *s)
{
	float shininess[] = {50.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidIcosahedron();
}
void draw_octahedron(float *a, float *d, float *s)
{
	float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidOctahedron();
}
void draw_plane()
{
	glBegin(GL_POLYGON);
	glVertex3f(-10.0, -10.0, 0.0);
	glVertex3f(+10.0, -10.0, 0.0);
	glVertex3f(+10.0, +10.0, 0.0);
	glVertex3f(-10.0, +10.0, 0.0);
	glEnd();
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
void draw_sphere(float *a, float *d, float *s)
{
	float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidSphere(5., 30, 30);
}
void draw_teapot(float *a, float *d, float *s)
{
	float shininess[] = {50.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidTeapot(5.0);
}
void draw_torus(float *a, float *d, float *s)
{
	float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidTorus(2.0, 6.0, 20, 20);
}
char fname[][100] = {"./assets/img/myPicture.ppm", "./assets/img/teki1.ppm", "./assets/img/teki2.ppm", "./assets/img/teki3.ppm", "./assets/img/teki4.ppm"};
void loadTexture(int n)
{
	FILE *fp;
	char  buf[100];
	int   header_lines = 3;
	if ((fp = fopen(fname[n], "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", fname[n]);
		exit(0);
	}
	for (int i = 0; i < header_lines; i++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			i--;
	}
	fread(TexImage[n], ImWidth * ImHeight * 3, 1, fp);
	fclose(fp);
}
void initialize_Texture()
{
	int i;
	for (i = 0; i < TexNum; i++)
	{
		loadTexture(i);
		glPixelStorei(GL_UNPACK_ALIGNMENT, i);
		glBindTexture(GL_TEXTURE_2D, i);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ImWidth, ImHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, TexImage[i]);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_AUTO_NORMAL);
		glEnable(GL_NORMALIZE);
		glEnable(GL_DEPTH_TEST);
		glFrontFace(GL_CW);
	}
}

void init_teki_zokusei();
void keyboard_proc(unsigned char key, int x, int y)
{
	static int n;
	int        i;
	switch (key)
	{
		case 'x':
			rotx += 3.0;
			break;
		case 'X':
			rotx -= 3.0;
			break;
		case 'y':
			roty += 3.0;
			break;
		case 'Y':
			roty -= 3.0;
			break;
		case 'z':
			rotz += 3.0;
			break;
		case 'Z':
			rotz -= 3.0;
			break;
		case ' ':
			if (miss[n].tflag == 0)
			{
				miss[n].tflag = 1;
				miss[n].posx  = TX;
				miss[n].posy  = TY;
				n++;
				n %= MISSILE_NUMBER;
			}
			break;
		case 'u':
			mv++;
			break;
		case 'p':
			for (i = 0; i < ENEMY_NUMBER; i++)
			{
				init_teki_zokusei();
			}
			break;
		case 'q':
			exit(1);
		case 'd':
			TX += 1.0;
			break;
		case 'a':
			TX -= 1.0;
			break;
		case 'w':
			TY += 1.0;
			break;
		case 's':
			TY -= 1.0;
			break;
	}
	if (rotx >= 360.)
		rotx -= 360.;
	if (rotx < 0.)
		rotx += 360.;
	if (roty >= 360.)
		rotx -= 360.;
	if (roty < 0.)
		roty += 360.;
	if (rotz >= 360.)
		rotx -= 360.;
	if (rotz < 0.)
		rotz += 360.;
	glutPostRedisplay();
}
void loadBackground()
{
	FILE *fp;
	char  buf[100];
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./assets/img/bg.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (int i = 0; i < header_lines; i++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			i--;
	}
	fread(background, BXsize * BYsize * 3, 1, fp);
	fclose(fp);
}

void draw_sphere(float *, float *, float *);
void missile()
{
	float ambient[4]  = {0.3, 0.2, 0.1, 1.0};
	float diffuse[4]  = {0.7, 0.6, 0.2, 1.0};
	float specular[4] = {1.0, 1.0, 1.0, 1.0};
	for (int i = 0; i < MISSILE_NUMBER; i++)
	{
		if (miss[i].tflag)
		{
			glPushMatrix();
			glEnable(GL_NORMALIZE);
			glScalef(0.2, 0.2, 0.2);
			draw_sphere(ambient, diffuse, specular);
			glPopMatrix();
		}
	}
}
void draw_missile()
{
	int i;
	for (i = 0; i < MISSILE_NUMBER; i++)
	{
		if (miss[i].tflag)
		{
			miss[i].posy += 1.5;
			glPushMatrix();
			glTranslatef(miss[i].posx, miss[i].posy, 0.0);
			missile();
			glPopMatrix();
			if (miss[i].posy > MAX_Y * 2)
			{
				miss[i].posy  = 0.0;
				miss[i].tflag = 0;
			}
		}
	}
}
void mouse_proc(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			mouse_flag = 1;
			TX         = (x - X_SIZE / 2) / XRATE;
		} else
			mouse_flag = 0;
	}
	glutPostRedisplay();
}
void motion_proc(int x, int y)
{
	TX = (x - X_SIZE / 2) / XRATE;
	glutPostRedisplay();
}
void myCharacter()
{
	glPushMatrix();
	glEnable(GL_NORMALIZE);
	glScalef(0.6, 0.7, 0.1);
	draw_plane_with_texture(0);
	glPopMatrix();
}
void myCircle(double r, int n)
{
	double x, y, z, dq;
	int    i;
	dq = 2.0 * M_PI / (double) n;
	glPushMatrix();
	y = 0.0;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		x = r * cos(dq * (double) i);
		z = r * sin(dq * (double) i);
		glVertex3f(x, y, z);
	}
	glEnd();
	glPopMatrix();
}
void myDisc(double r, int n)
{
	double x, y, z, dq;
	int    i;
	glEnable(GL_NORMALIZE);
	dq = 2.0 * M_PI / (double) n;
	glPushMatrix();
	y = 0.0;
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * (double) i);
		z = r * sin(dq * (double) i);
		glVertex3f(x, y, z);
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_NORMALIZE);
}
void mySolidCylinder(double r, double h, int n)
{
	double x, y, z, dq;
	int    i;
	glEnable(GL_NORMALIZE);
	dq = 2.0 * M_PI / (double) n;
	y  = 0.5 * h;
	glPushMatrix();
	glRotatef(-dq * 180.0 / 2.0 * M_PI, 0.0, 0.1, 0.0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= n; i += 1)
	{
		x = r * cos(dq * (double) i);
		z = r * sin(dq * (double) i);
		glNormal3f(x, 0, z);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, -1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * (double) i);
		z = r * sin(dq * (double) i);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * (double) i);
		z = r * sin(dq * (double) i);
		glVertex3f(x, y, z);
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_NORMALIZE);
}
void myWireCylinder(double r, double h, int n)
{
	double x, y, z, dq;
	int    i;
	dq = 2.0 * M_PI / (double) n;
	y  = 0.5 * h;
	glPushMatrix();
	glRotatef(-dq * 180.0 / 2.0 * M_PI, 0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	for (i = 0; i < n; i++)
	{
		x = r * cos(dq * (double) i);
		z = r * sin(dq * (double) i);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		x = r * cos(dq * (double) i);
		z = r * sin(dq * (double) i);
		glVertex3f(x, y, z);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		x = r * cos(dq * (double) i);
		z = r * sin(dq * (double) i);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glPopMatrix();
}
void story()
{
	printf("やぁ！ 岡田戦記をプレイしてくれてありがとう！\n");
	printf("ENTERキーで次へ進む\n");
	while (getchar() == EOF)
		;
	printf("赤い彗星の王子の物語が今・・・始まる\n");
	printf("GAME START for push ENTER key \n");
	while (getchar() == EOF)
		;
}
void tekiCharacter()
{
	for (int i = 0; i < ENEMY_NUMBER; i++)
	{
		if (teki[i].tflag)
		{
			if (teki[i].posx > MAX_X || teki[i].posx < MIN_X)
				teki[i].vx *= -1;
			teki[i].vy *= 1;
			teki[i].posx += teki[i].vx;
			teki[i].posy -= teki[i].vy;
			teki[i].roty += 3.0;
			if (teki[i].roty > 360.)
				teki[i].roty -= 360.;
			glPushMatrix();
			glTranslatef(teki[i].posx, teki[i].posy, 0.0);
			glPushMatrix();
			glRotatef(teki[i].roty, 0.0, 1.0, 0.0);
			glPushMatrix();
			glEnable(GL_NORMALIZE);
			glScalef(1.2, 1.2, 1.2);
			float ambient[4]  = {0.3, 0.3, 0.3, 1.0};
			float diffuse[4]  = {0.7, 0.7, 0.7, 1.0};
			float specular[4] = {1.0, 1.0, 1.0, 1.0};
			if (teki[i].shape == 1)
			{
				glPushMatrix();
				glScalef(0.4, 0.4, 0.4);
				draw_plane_with_texture(1);
				glPopMatrix();
			} else if (teki[i].shape == 2)
				draw_icosahedron(ambient, diffuse, specular);
			else if (teki[i].shape == 3)
				draw_dodecahedron(ambient, diffuse, specular);
			else
				draw_octahedron(ambient, diffuse, specular);
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
		} else
		{
			teki[i].posx = MIN_X;
			teki[i].posy = MAX_Y;
		}
	}
}
void image()
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	unsigned char *buf;
	static int     offset;
	int            j, k;
	int            mv = 10;
	glPixelZoom((float) X_SIZE / BXsize, (float) Y_SIZE / BYsize);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glRasterPos2f(MIN_Z, -10.0);
	buf = (unsigned char *) malloc(BXsize * BYsize * 3);
	k   = 0;
	for (i = 0; i < (BYsize - offset); i++)
	{
		for (j = 0; j < BXsize * 3; j++)
		{
			buf[k] = background[(i + offset) * (BXsize * 3) + j];
			k++;
		}
	}
	for (i = 0; i < offset; i++)
	{
		for (j = 0; j < BXsize * 3; j++)
		{
			buf[k] = background[i * (BXsize * 3) + j];
			k++;
		}
	}
	glDrawPixels(BXsize, BYsize, GL_RGB, GL_UNSIGNED_BYTE, buf);
	offset += mv;
	if (offset >= BYsize)
		offset -= BYsize;
	glPushMatrix();
	glTranslatef(0.0, 0.0, 10.0);
	tekiCharacter();
	draw_missile();
	collision_judge();
	glPushMatrix();
	glTranslatef(TX, TY, TZ);
	glPushMatrix();
	myCharacter();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
void idle_proc()
{
	roty += 3.;
	if (roty >= 360.)
		roty -= 360.;
	glutPostRedisplay();
}
void init_teki_zokusei()
{
	teki[0].shape = 1;
	teki[0].posy  = 45;
	teki[0].vx    = 0.2;
	teki[0].vy    = 0.2;
	teki[0].roty  = 0;
	teki[0].tflag = 1;
	teki[1].shape = 2;
	teki[1].posy  = 40;
	teki[1].vx    = 0.5;
	teki[1].vy    = 0.2;
	teki[1].roty  = 0;
	teki[1].tflag = 1;
	teki[2].shape = 3;
	teki[2].posy  = 35;
	teki[2].vx    = 1.0;
	teki[2].vy    = 0.2;
	teki[2].roty  = 0;
	teki[2].tflag = 1;
	teki[3].shape = 3;
	teki[3].posy  = 38;
	teki[3].vx    = 2.0;
	teki[3].vy    = 0.2;
	teki[3].roty  = 0;
	teki[3].tflag = 1;
	teki[4].shape = 3;
	teki[4].posy  = 42;
	teki[4].vx    = 0.8;
	teki[4].vy    = 0.2;
	teki[4].roty  = 0;
	teki[4].tflag = 1;
}
void init_zokusei()
{
	rotx = roty = rotz = 0.0;
	TX                 = 0;
	TY                 = 0;
	TZ                 = 0;
	init_teki_zokusei();
}
void init_gl_settings()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(MIN_X, MAX_Y, MIN_Y, MAX_Y, MIN_Z, MAX_Z);
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
