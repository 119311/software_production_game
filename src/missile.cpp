#include <common.hpp>
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
			drawSphere(ambient, diffuse, specular);
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
