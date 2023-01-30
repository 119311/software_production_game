#include <common.hpp>

void updateMissile(void)
{
	const float ambient[]  = {0.8, 0.3, 0.0, 1.0};
	const float diffuse[]  = {0.8, 0.2, 0.0, 1.0};
	const float specular[] = {0.8, 0.2, 0.0, 1.0};

	for (int i = 0; i < MISSILE_NUMBER; i++)
	{
		if (missile[i].tflag)
		{
			glPushMatrix();
			glEnable(GL_NORMALIZE);
			glScalef(0.1, 0.1, 0.1);
			drawSphere(ambient, diffuse, specular);
			glPopMatrix();
		}
	}
}
