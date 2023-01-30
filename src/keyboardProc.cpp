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
				missile[n].posX  = player.posX;
				missile[n].posY  = player.posY;
				n++;
				n %= MISSILE_NUMBER;
			}
			break;
		case 't':
			if (enemyMissile[n].tflag == 0)
			{
				enemyMissile[n].tflag = 1;
				enemyMissile[n].posX  = enemy[0].posX;
				enemyMissile[n].posY  = enemy[0].posY;
				n++;
				n %= MISSILE_NUMBER;
			}
			break;
		case 'u':
			mv++;
			break;
		case 'p':
			for (int i = 0; i < ENEMY_NUMBER; i++)
			{
				initProperty();
			}
			break;
		case 'q':
			exit(EXIT_FAILURE);
		case 'c':
			selectFlag += 1;
			if (selectFlag >= 2)
			{
				player.posX = player.posY = 0;
				selectFlag                = GL_FALSE;
				initProperty();
			}
			break;
		case 'r':
			storyFlag = 0;
			break;
	}
	if (selectFlag == GL_FALSE)
	{
		switch (key)
		{
			case 'd':
				player.posX += 2.0;
				if (player.posX >= 25)
					player.posX = 25;
				break;
			case 'a':
				player.posX -= 2.0;
				if (player.posX <= -25)
					player.posX = -25;
				break;
			case 'w':
				player.posY += 2.0;
				if (player.posY >= 30)
					player.posY = 30;
				break;
			case 's':
				player.posY -= 2.0;
				if (player.posY <= -5)
					player.posY = -5;
				break;
			case 'f':
				storyFlag += 1;
				if (storyFlag >= 2)
					storyFlag = 2;
				break;
		}
	}
	if (rotX >= 360.0)
		rotX -= 360.0;
	if (rotX < 0.)
		rotX += 360.0;
	if (rotY >= 360.0)
		rotX -= 360.0;
	if (rotY < 0.)
		rotY += 360.0;
	if (rotZ >= 360.0)
		rotX -= 360.0;
	if (rotZ < 0.)
		rotZ += 360.0;
	glutPostRedisplay();
}
