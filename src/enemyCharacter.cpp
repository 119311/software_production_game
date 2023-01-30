#include <common.hpp>

void enemyCharacter(property *enemy)
{
	for (int i = 0; i < ENEMY_NUMBER; i++)
	{
		if (enemy[i].tflag)
		{
			if (enemy[i].posX > MAX_X || enemy[i].posX < MIN_X)
				enemy[i].vx *= -1;
			if (enemy[i].posY < MIN_Y)
				enemy[i].posY = MAX_Y * 2;
			enemy[i].vy *= 1;
			enemy[i].posX += enemy[i].vx;
			enemy[i].posY -= enemy[i].vy;
			enemy[i].rotY += 3.0;
			if (enemy[i].rotY > 360.0)
				enemy[i].rotY -= 360.0;
			glPushMatrix();
			glTranslatef(enemy[i].posX, enemy[i].posY, 0.0);
			glPushMatrix();
			glRotatef(enemy[i].rotY, 0.0, 1.0, 0.0);
			glPushMatrix();
			glEnable(GL_NORMALIZE);
			glScalef(1.2, 1.2, 1.2);
			const float ambient[4]  = {0.3, 0.3, 0.3, 1.0};
			const float diffuse[4]  = {0.7, 0.7, 0.7, 1.0};
			const float specular[4] = {1.0, 1.0, 1.0, 1.0};
			if (enemy[i].shape == 1)
			{
				glPushMatrix();
				glScalef(0.4, 0.4, 0.4);
				drawPlaneWithTexture(1);
				glPopMatrix();
			} else if (enemy[i].shape == 2)
			{
				glPushMatrix();
				glScalef(1.0, 1.0, 1.0);
				drawIcosahedron(ambient, diffuse, specular);
				glPopMatrix();
			} else if (enemy[i].shape == 3)
			{
				glPushMatrix();
				drawDodecahedron(ambient, diffuse, specular);
				glScalef(2.0, 2.0, 2.0);
				glPopMatrix();
			} else
				drawOctahedron(ambient, diffuse, specular);
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
		} else
		{
			enemy[i].posX = MIN_X;
			enemy[i].posY = MAX_Y;
		}
	}
}
