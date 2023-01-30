#include <common.hpp>
float    rotX = 0, rotY = 0, rotZ = 0, tx = 0, ty = 0, tz;
int      mouseFlag = 0, mv = 0, selectFlag = 0, storyFlag = 0, trinum;
property enemy[ENEMY_NUMBER], missile[MISSILE_NUMBER], player, enemyMissile[MISSILE_NUMBER];
int      gamePop[popXsize * popYsize * 3], background[WINDOW_WIDTH * WINDOW_HEIGHT * 3], gameClear[popXsize * popYsize * 3], gameOver[popXsize * popYsize * 3], story1[WINDOW_WIDTH * WINDOW_HEIGHT * 3], story2[WINDOW_WIDTH * WINDOW_HEIGHT * 3], TexImage[TexNum][IMAGE_WIDTH * IMAGE_HEIGHT * 3], title[WINDOW_WIDTH * WINDOW_HEIGHT * 3];
point    po[TRINUM][3], nv[TRINUM];
void     image(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	uint8_t   *buf;
	static int offset;
	int        k;
	int        mv = 10;
	glPixelZoom(WINDOW_WIDTH / WINDOW_WIDTH, WINDOW_HEIGHT / WINDOW_HEIGHT);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glRasterPos2f(MIN_Z, -10.0);
	buf = (uint8_t *) malloc(WINDOW_WIDTH * WINDOW_HEIGHT * 3);
	if (storyFlag == 0)
	{
		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos2f(-30, 50);
		glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, title);
		glPopMatrix();
		glutSwapBuffers();
	} else if (storyFlag == 1)
	{
		initProperty();
		glPushMatrix();
		glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, background);
		glPopMatrix();
		glutSwapBuffers();
	} else if (selectFlag == GL_TRUE)
	{
		player.posX = player.posY = 0;
		glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, background);
		drawPlaneWithTexture(0);
		glPushMatrix();
		glTranslatef(0, 0, 10);
		playerStl1(po, nv, trinum);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-10, 0, 10);
		playerStl1(po, nv, trinum);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(10, 0, 10);
		playerStl1(po, nv, trinum);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(20, 0, 10);
		playerStl1(po, nv, trinum);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-20, 0, 10);
		playerStl1(po, nv, trinum);
		glPopMatrix();
		glutSwapBuffers();
	} else if (enemy[0].tflag == 0)
	{
		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos2f(-30, 50);
		glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, gameClear);
		playerStl1(po, nv, trinum);
		glPopMatrix();
		glutSwapBuffers();
	} else if (player.tflag == 0)
	{
		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos2f(-30, 50);
		glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, gameOver);
		glPopMatrix();
		glutSwapBuffers();
	} else if (storyFlag >= 2)
	{
		buf = (unsigned char *) malloc(WINDOW_WIDTH * WINDOW_HEIGHT * 3);
		k   = 0;
		for (int i = 0; i < (WINDOW_HEIGHT - offset); i++)
		{
			for (int j = 0; j < WINDOW_WIDTH * 3; j++)
			{
				buf[k] = background[(i + offset) * (WINDOW_WIDTH * 3) + j];
				k++;
			}
		}
		for (int i = 0; i < offset; i++)
		{
			for (int j = 0; j < WINDOW_WIDTH * 3; j++)
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
		drawEnemyHitPointBar(TEKIDUR - enemy[0].durability);
		drawPlayerHitPointBar(MYDUR - player.durability);
		enemyCharacter(enemy);
		drawMissile();
		drawEnemyMissile();
		collisionJudge(enemy, missile, enemyMissile);
		glPushMatrix();
		playerStl1(po, nv, trinum);
		glPopMatrix();
		glPopMatrix();
		glutSwapBuffers();
		if (enemy[1].tflag == 0 && enemy[2].tflag == 0 && enemy[3].tflag == 0 && enemy[4].tflag == 0)
		{
			for (int a = 1; a <= ENEMY_NUMBER; a++)
				initEnemyProperty(a, enemy);
		}
	}
}

void initPlayerProperty(void)
{
	player.posX       = 0;
	player.posY       = 0;
	player.posZ       = 0;
	player.durability = MYDUR + 3;
	player.tflag      = 1;
	rotX = rotY = rotZ = 0.0;
}
void initProperty(void)
{
	initPlayerProperty();
	for (int i = 0; i < ENEMY_NUMBER; i++)
		initEnemyProperty(i, enemy);
}

int main(int argc, char **argv)
{

	int TexImage[TexNum][IMAGE_WIDTH * IMAGE_HEIGHT * 3];
	int story1[WINDOW_HEIGHT * WINDOW_HEIGHT * 3];

	const char *fname[MAX_FILENAME_LENGTH] = {"./assets/img/myPicture.ppm", "./assets/img/enemy1.ppm", "./assets/img/enemy2.ppm", "./assets/img/enemy3.ppm", "./assets/img/enemy4.ppm"};

	readStlFighter(po, nv, trinum);
	initProperty();
	loadTitle(title);
	loadBackground(background);
	loadStoryImage1(story1);
	loadStoryImage2();
	loadGameOver(gameOver);
	loadGameClear(gameClear);
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
