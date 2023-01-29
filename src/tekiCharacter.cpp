#include <common.hpp>
void enemyCharacter(property *enemy)
{
	for (int i = 0; i < ENEMY_NUMBER; i++)
	{
		if (enemy[i].tflag)
		{
			if (enemy[i].posx > MAX_X || enemy[i].posx < MIN_X)
				enemy[i].vx *= -1;
			enemy[i].vy *= 1;
			enemy[i].posx += enemy[i].vx;
			enemy[i].posy -= enemy[i].vy;
			enemy[i].rotY += 3.0;
			if (enemy[i].rotY > 360.)
				enemy[i].rotY -= 360.;
			glPushMatrix();
			glTranslatef(enemy[i].posx, enemy[i].posy, 0.0);
			glPushMatrix();
			glRotatef(enemy[i].rotY, 0.0, 1.0, 0.0);
			glPushMatrix();
			glEnable(GL_NORMALIZE);
			glScalef(1.2, 1.2, 1.2);
			float ambient[4]  = {0.3, 0.3, 0.3, 1.0};
			float diffuse[4]  = {0.7, 0.7, 0.7, 1.0};
			float specular[4] = {1.0, 1.0, 1.0, 1.0};
			if (enemy[i].shape == 1)
			{
				glPushMatrix();
				glScalef(0.4, 0.4, 0.4);
				drawPlaneWithTexture(1);
				glPopMatrix();
			} else if (enemy[i].shape == 2)
				drawIcosahedron(ambient, diffuse, specular);
			else if (enemy[i].shape == 3)
				drawDodecahedron(ambient, diffuse, specular);
			else
				drawOctahedron(ambient, diffuse, specular);
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
		} else
		{
			enemy[i].posx = MIN_X;
			enemy[i].posy = MAX_Y;
		}
	}
}
