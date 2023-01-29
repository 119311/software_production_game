#include <common.hpp>
void keyboardProc(uint8_t key, int x, int v)
{
	static int n;
	switch (key)
	{
		case 'x':
			rotX += 3.0;
			break;
		case 'X':
			rotX -= 3.0;
			break;
		case 'y':
			rotY += 3.0;
			break;
		case 'Y':
			rotY -= 3.0;
			break;
		case 'z':
			rotZ += 3.0;
			break;
		case 'Z':
			rotZ -= 3.0;
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
			if (tx >= 20)
				tx = 20;
			break;
		case 'a':
			tx -= 2.0;
			if (tx <= -20)
				tx = -20;
			break;
		case 'w':
			ty += 2.0;
			if (ty >= 20)
				ty = 20;
			break;
		case 's':
			ty -= 2.0;
			if (ty <= 0)
				ty = 0;
			break;
		case 'f':
			storyFlag += 1;
			if (storyFlag >= 2)
				storyFlag = 2;
			break;
		case 'c':
			selectFlag += 1;
			if (selectFlag >= 2)
			{
				selectFlag = 0;
				initEnemyProperty(enemy);
			}
			break;
	}
	if (rotX >= 360.)
		rotX -= 360.;
	if (rotX < 0.)
		rotX += 360.;
	if (rotY >= 360.)
		rotX -= 360.;
	if (rotY < 0.)
		rotY += 360.;
	if (rotZ >= 360.)
		rotX -= 360.;
	if (rotZ < 0.)
		rotZ += 360.;
	glutPostRedisplay();
}
