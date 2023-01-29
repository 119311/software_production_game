#include <common.hpp>

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
	collisionJudge(enemy, missile);
	glPushMatrix();
	glTranslatef(tx, ty, tz);
	glPushMatrix();
	myCharacter();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
