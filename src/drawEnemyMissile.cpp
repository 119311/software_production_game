#include <common.hpp>

void drawEnemyMissile(void)
{
	for (int i = 0; i < MISSILE_NUMBER; i++)
	{
		if (enemyMissile[i].tflag)
		{
			enemyMissile[i].posY -= 1.5;
			glPushMatrix();
			glTranslatef(enemyMissile[i].posX, enemyMissile[i].posY, 0.0);
			updateEnemyMissile();
			glPopMatrix();
			if (enemyMissile[i].posY < MIN_Y * 2)
			{
				enemyMissile[i].posY  = enemy[0].posY;
				enemyMissile[i].tflag = 0;
			}
		}
	}
}
