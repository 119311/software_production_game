#include "./common.h"

void draw_icosahedron(float *, float *, float *),
    draw_octahedron(float *, float *, float *),
    draw_plane_with_texture(int),
    draw_dodecahedron(float *, float *, float *),
    tekiCharacter_stl1();

void tekiCharacter()
{
	int   i;
	float ambient[4], diffuse[4], specular[4];

	for (i = 0; i < tekinum; i++)
	{
		if (teki[i].tflag)
		{
			if (teki[i].posx > MAX_X || teki[i].posx < MIN_X)
				teki[i].vx *= -1;
			if (teki[i].posy < MIN_Y)
				teki[i].posy = MAX_Y * 2;
			teki[i].vy *= 1;
			teki[i].posx += teki[i].vx;
			teki[i].posy -= teki[i].vy;
			teki[i].roty += 3.0;
			if (teki[i].roty > 360.)
				teki[i].roty -= 360.;
			glPushMatrix();
			glTranslatef(teki[i].posx, teki[i].posy, 0.0);
			glPushMatrix();
			glRotatef(teki[i].roty, 0.0, 1.0, 0.0);
			glPushMatrix();
			glEnable(GL_NORMALIZE);
			glScalef(1.2, 1.2, 1.2);
			ambient[0]  = 0.3;
			ambient[1]  = 0.3;
			ambient[2]  = 0.3;
			ambient[3]  = 1.0;
			diffuse[0]  = 0.7;
			diffuse[1]  = 0.7;
			diffuse[2]  = 0.7;
			diffuse[3]  = 1.0;
			specular[0] = 1.0;
			specular[1] = 1.0;
			specular[2] = 1.0;
			specular[3] = 1.0;
			if (teki[i].shape == 1)
			{
				// draw_octahedron(ambient, diffuse, specular);
				glPushMatrix();    // modified 12/16
				glScalef(0.8, 0.8, 0.8);
				tekiCharacter_stl1();
				// draw_plane_with_texture(1);
				glPopMatrix();
			} else if (teki[i].shape == 2)
			{
				glPushMatrix();
				glScalef(1.0, 1.0, 1.0);
				draw_icosahedron(ambient, diffuse, specular);
				glPopMatrix();
			} else if (teki[i].shape == 3)
			{
				glPushMatrix();
				draw_dodecahedron(ambient, diffuse, specular);
				glScalef(2.0, 2.0, 2.0);
				glPopMatrix();
			} else
				draw_octahedron(ambient, diffuse, specular);
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
		} else
		{
			teki[i].posx = MIN_X;
			teki[i].posy = MAX_Y;
		}
	}
}
