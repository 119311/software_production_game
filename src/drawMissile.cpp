#include <common.hpp>

void drawMissile(void)
{

	for (int i = 0; i < MISSILE_NUMBER; i++)
	{
		if (missile[i].tflag)
		{
			missile[i].posY += 1.5;
			glPushMatrix();
			glTranslatef(missile[i].posX, missile[i].posY, 0.0);
			updateMissile();
			glPopMatrix();
			if (missile[i].posY > MAX_Y * 2)
			{
				missile[i].posY  = player.posY;
				missile[i].tflag = 0;
			}
		}
	}
}
