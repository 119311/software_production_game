#include <common.hpp>

double   rotx = 0.0, roty = 0.0, rotz = 0.0, tx = 0.0, ty = 0.0, tz = 0.0;
property enemy[ENEMY_NUMBER], missile[MISSILE_NUMBER];
uint8_t  background[WINDOW_WIDTH * WINDOW_HEIGHT * 3];
int      mouse_flag = 0, mv = 0;

int main(int argc, char **argv)
{
	point       po[TRINUM][3], nv[TRINUM];
	int         back_flag = 0.0, trinum = 0.0;
	uint8_t     TexImage[TexNum][IMAGE_WIDTH * IMAGE_HEIGHT * 3];
	const char *fname[MAX_FILENAME_LENGTH] = {"./assets/img/myPicture.ppm", "./assets/img/enemy1.ppm", "./assets/img/enemy2.ppm", "./assets/img/enemy3.ppm", "./assets/img/enemy4.ppm"};
	story();
	initEnemyProperty(enemy);
	loadBackground(background);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("sample1");
	initLightSettings();
	initGlSettings();
	initializeTexture(TexImage, fname);
	glPushMatrix();
	glTranslatef(0, -20, 0);
	glutDisplayFunc(image);
	glutMouseFunc(mouseProc);
	glutMotionFunc(motionProc);
	glutKeyboardFunc(keyboardProc);
	glutIdleFunc(idleProc);
	glutMainLoop();
	glPopMatrix();
	glPopMatrix();
}
void collision_judge(property *enemy, property *missile)
{
	for (int j = 0; j < MISSILE_NUMBER; j++)
	{
		for (int i = 0; i < ENEMY_NUMBER; i++)
		{
			double d = sqrt((enemy[i].posx - missile[j].posx) * (enemy[i].posx - missile[j].posx) + (enemy[i].posy - missile[j].posy) * (enemy[i].posy - missile[j].posy));
			if (d < DIS)
			{
				enemy[i].tflag   = 0;
				missile[j].tflag = 0;
				missile[j].posy  = 0.0;
				break;
			}
		}
	}
}
void drawCone(float *a, float *d, float *s)
{
	float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidCone(6.0, 15.0, 20, 20);
}
void drawCube(float *a, float *d, float *s)
{
	float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidCube(10.0);
}
void drawCylinder(float *a, float *d, float *s)
{
	float shininess[] = {50.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	SolidCylinder(3.0, 8.0, 20);
}
void drawDodecahedron(float *a, float *d, float *s)
{
	float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidDodecahedron();
}
void drawIcosahedron(float *a, float *d, float *s)
{
	float shininess[] = {50.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidIcosahedron();
}
void drawOctahedron(float *a, float *d, float *s)
{
	float shininess[] = {25.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glMaterialfv(GL_FRONT, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glutSolidOctahedron();
}
void drawPlaneWithTexture(int i)
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
void enemyCharacter(property *enemy)
{
	for (int i = 0; i < ENEMY_NUMBER; i++)
	{
		if (enemy[i].tflag)
		{
			if (enemy[i].posx > MAX_X || enemy[i].posx < MIN_X)
				enemy[i].vx *= -1;
			enemy[i].vy *= 1;
			enemy[i].posx += enemy[i].vx;
			enemy[i].posy -= enemy[i].vy;
			enemy[i].roty += 3.0;
			if (enemy[i].roty > 360.)
				enemy[i].roty -= 360.;
			glPushMatrix();
			glTranslatef(enemy[i].posx, enemy[i].posy, 0.0);
			glPushMatrix();
			glRotatef(enemy[i].roty, 0.0, 1.0, 0.0);
			glPushMatrix();
			glEnable(GL_NORMALIZE);
			glScalef(1.2, 1.2, 1.2);
			float ambient[4]  = {0.3, 0.3, 0.3, 1.0};
			float diffuse[4]  = {0.7, 0.7, 0.7, 1.0};
			float specular[4] = {1.0, 1.0, 1.0, 1.0};
			if (enemy[i].shape == 1)
			{
				glPushMatrix();
				glScalef(0.4, 0.4, 0.4);
				drawPlaneWithTexture(1);
				glPopMatrix();
			} else if (enemy[i].shape == 2)
				drawIcosahedron(ambient, diffuse, specular);
			else if (enemy[i].shape == 3)
				drawDodecahedron(ambient, diffuse, specular);
			else
				drawOctahedron(ambient, diffuse, specular);
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
		} else
		{
			enemy[i].posx = MIN_X;
			enemy[i].posy = MAX_Y;
		}
	}
}
void loadTexture(int n, const char *fname[], uint8_t TexImage[][IMAGE_WIDTH * IMAGE_HEIGHT * 3])
{
	FILE *fp;
	char  buf[MAX_FILENAME_LENGTH];
	int   header_lines = 3;
	if (!(fp = fopen(fname[n], "r")))
	{
		fprintf(stderr, "Cannot open texture file %s\n", fname[n]);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < header_lines; i++)
	{
		fgets(buf, MAX_FILENAME_LENGTH, fp);
		if (*buf == '#')
			i--;
	}
	fread(TexImage[n], IMAGE_WIDTH * IMAGE_HEIGHT * 3, 1, fp);
	fclose(fp);
}
void initializeTexture(uint8_t TexImage[][IMAGE_WIDTH * IMAGE_HEIGHT * 3], const char *fname[])
{
	for (int i = 0; i < TexNum; i++)
	{
		loadTexture(i, fname, TexImage);
		glPixelStorei(GL_UNPACK_ALIGNMENT, i);
		glBindTexture(GL_TEXTURE_2D, i);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, IMAGE_WIDTH, IMAGE_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, TexImage[i]);
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
void keyboardProc(uint8_t key, int x, int v)
{
	static int n;
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
			if (missile[n].tflag == 0)
			{
				missile[n].tflag = 1;
				missile[n].posx  = tx;
				missile[n].posy  = ty;
				n++;
				n %= MISSILE_NUMBER;
			}
			break;
		case 'u':
			mv++;
			break;
		case 'p':
			for (int i = 0; i < ENEMY_NUMBER; i++)

				initEnemyProperty(enemy);

			break;
		case 'q':
			exit(EXIT_SUCCESS);
		case 'd':
			tx += 1.0;
			break;
		case 'a':
			tx -= 1.0;
			break;
		case 'w':
			ty += 1.0;
			break;
		case 's':
			ty -= 1.0;
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
void loadBackground(uint8_t background[])
{
	FILE *fp;
	char  buf[MAX_FILENAME_LENGTH];
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./assets/img/bg.ppm");
	if (!(fp = fopen(name, "r")))
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < header_lines; i++)
	{
		fgets(buf, MAX_FILENAME_LENGTH, fp);
		if (*buf == '#')
			i--;
	}
	fread(background, WINDOW_WIDTH * WINDOW_HEIGHT * 3, 1, fp);
	fclose(fp);
}
void updateMissile(property *missile)
{
	float ambient[4]  = {0.3, 0.2, 0.1, 1.0};
	float diffuse[4]  = {0.7, 0.6, 0.2, 1.0};
	float specular[4] = {1.0, 1.0, 1.0, 1.0};
	for (int i = 0; i < MISSILE_NUMBER; i++)
	{
		if (missile[i].tflag)
		{
			glPushMatrix();
			glEnable(GL_NORMALIZE);
			glScalef(0.2, 0.2, 0.2);
			draw_sphere(ambient, diffuse, specular);
			glPopMatrix();
		}
	}
}
void drawMissile(property *missile)
{
	for (int i = 0; i < MISSILE_NUMBER; i++)
	{
		if (missile[i].tflag)
		{
			missile[i].posy += 1.5;
			glPushMatrix();
			glTranslatef(missile[i].posx, missile[i].posy, 0.0);
			updateMissile(missile);
			glPopMatrix();
			if (missile[i].posy > MAX_Y * 2)
			{
				missile[i].posy  = 0.0;
				missile[i].tflag = 0;
			}
		}
	}
}
void image(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	uint8_t   *buf;
	static int offset;
	int        k;
	int        mv = 10;
	glPixelZoom((float) WINDOW_WIDTH / WINDOW_WIDTH, (float) WINDOW_HEIGHT / WINDOW_HEIGHT);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glRasterPos2f(MIN_Z, -10.0);
	buf = (uint8_t *) malloc(WINDOW_WIDTH * WINDOW_HEIGHT * 3);
	for (uint8_t i = 0; i < (WINDOW_HEIGHT - offset); i++)
	{
		for (uint8_t j = 0; j < WINDOW_WIDTH * 3; j++)
		{
			buf[k] = background[(i + offset) * (WINDOW_WIDTH * 3) + j];
			k++;
		}
	}
	for (uint8_t i = 0; i < offset; i++)
	{
		for (uint8_t j = 0; j < WINDOW_WIDTH * 3; j++)
		{
			buf[k] = background[i * (WINDOW_WIDTH * 3) + j];
			k++;
		}
	}
	glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, buf);
	offset += mv;
	if (offset >= WINDOW_HEIGHT)
		offset -= WINDOW_HEIGHT;
	glPushMatrix();
	glTranslatef(0.0, 0.0, 10.0);
	enemyCharacter(enemy);
	drawMissile(missile);
	collision_judge(enemy, missile);
	glPushMatrix();
	glTranslatef(tx, ty, tz);
	glPushMatrix();
	myCharacter();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
void idleProc(void)
{
	roty += 3.;
	if (roty >= 360.)
		roty -= 360.;
	glutPostRedisplay();
}
void initEnemyProperty(property enemy[])
{
	enemy[0] = {1, 45, 0.2, 0.2, 0, 1, 0, 0, 0, 0};
	enemy[1] = {2, 40, 0.5, 0.2, 0, 1, 0, 0, 0, 0};
	enemy[2] = {3, 35, 1.0, 0.2, 0, 1, 0, 0, 0, 0};
	enemy[3] = {3, 38, 2.0, 0.2, 0, 1, 0, 0, 0, 0};
	enemy[4] = {3, 42, 0.8, 0.2, 0, 1, 0, 0, 0, 0};
}
void initGlSettings(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(MIN_X, MAX_Y, MIN_Y, MAX_Y, MIN_Z, MAX_Z);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
}
void initLightSettings(void)
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
void SolidCylinder(double r, double h, int n)
{
	double x, y, z, dq;
	int    i;
	glEnable(GL_NORMALIZE);
	dq = 2.0 * M_PI / n;
	y  = 0.5 * h;
	glPushMatrix();
	glRotatef(-dq * 180.0 / 2.0 * M_PI, 0.0, 0.1, 0.0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= n; i += 1)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glNormal3f(x, 0, z);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, -1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glVertex3f(x, y, z);
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_NORMALIZE);
}
void mouseProc(int button, int state, int x, int v)
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			mouse_flag = 1;
			tx         = (x - WINDOW_WIDTH / 2) / XRATE;
		} else
			mouse_flag = 0;
	}
	glutPostRedisplay();
}
void motionProc(int x, int v)
{
	tx = (x - WINDOW_WIDTH / 2) / XRATE;
	glutPostRedisplay();
}
void myCharacter(void)
{
	glPushMatrix();
	glEnable(GL_NORMALIZE);
	glScalef(0.6, 0.7, 0.1);
	drawPlaneWithTexture(0);
	glPopMatrix();
}
void myCircle(double r, int n)
{
	double x, y, z, dq;
	int    i;
	dq = 2.0 * M_PI / n;
	glPushMatrix();
	y = 0.0;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
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
	dq = 2.0 * M_PI / n;
	glPushMatrix();
	y = 0.0;
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
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
	dq = 2.0 * M_PI / n;
	y  = 0.5 * h;
	glPushMatrix();
	glRotatef(-dq * 180.0 / 2.0 * M_PI, 0.0, 0.1, 0.0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= n; i += 1)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glNormal3f(x, 0, z);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, -1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	for (i = 0; i < n; i += 1)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
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
	dq = 2.0 * M_PI / n;
	y  = 0.5 * h;
	glPushMatrix();
	glRotatef(-dq * 180.0 / 2.0 * M_PI, 0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	for (i = 0; i < n; i++)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glVertex3f(x, y, z);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		x = r * cos(dq * i);
		z = r * sin(dq * i);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glPopMatrix();
}
void story(void)
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
