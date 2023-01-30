#include <common.hpp>

void updateEnemyMissile(void)
{
	const float ambient[]  = {0.0, 0.3, 0.8, 1.0};
	const float diffuse[]  = {0.0, 0.2, 0.8, 1.0};
	const float specular[] = {0.0, 0.2, 0.8, 1.0};
	for (int i = 0; i < MISSILE_NUMBER; i++)
	{
		if (enemyMissile[i].tflag)
		{
			glPushMatrix();
			glEnable(GL_NORMALIZE);
			glScalef(0.1, 0.1, 0.1);
			drawSphere(ambient, diffuse, specular);
			glPopMatrix();
		}
	}
}
