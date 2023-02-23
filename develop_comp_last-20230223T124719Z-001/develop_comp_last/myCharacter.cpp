#include "./common.h"

void draw_plane(), draw_plane_with_texture();
void draw_stl(float *, float *, float *);

void myCharacter()
{
	if (myChara.tflag)
	{
		float ambient[4], diffuse[4], specular[4];
		glPushMatrix();
		glEnable(GL_NORMALIZE);    // glScalef()$B$N$H$-I,MW(B
		glScalef(0.6, 0.7, 0.1);
		ambient[0]  = 0.0;
		ambient[1]  = 0.3;
		ambient[2]  = 0.0;
		ambient[3]  = 1.0;
		diffuse[0]  = 0.0;
		diffuse[1]  = 0.7;
		diffuse[2]  = 0.0;
		diffuse[3]  = 1.0;
		specular[0] = 1.0;
		specular[1] = 1.0;
		specular[2] = 1.0;
		specular[3] = 1.0;
		// draw_plane();
		draw_plane_with_texture(0);
		glPopMatrix();
	}
}

void myCharacter_stl1()
{
	if (myChara.tflag)
	{
		float ambient[4], diffuse[4], specular[4];
		glPushMatrix();
		glPushMatrix();
		glTranslatef(myChara.posx, myChara.posy, 0);

		glEnable(GL_NORMALIZE);
		glScalef(0.07, 0.07, 0.07);    //変更 02/06
		//シャア専用機
		ambient[0]  = 0.9;
		ambient[1]  = 0.3;
		ambient[2]  = 0.3;
		ambient[3]  = 1.0;
		diffuse[0]  = 0.9;
		diffuse[1]  = 0.2;
		diffuse[2]  = 0.2;
		diffuse[3]  = 1.0;
		specular[0] = 0.9;
		specular[1] = 0.2;
		specular[2] = 0.2;
		specular[3] = 1.0;
		draw_stl(ambient, diffuse, specular);
		glPopMatrix();
		glPopMatrix();
	}
}

void tekiCharacter_stl1()
{
	if (teki[0].tflag)
	{
		float ambient[4], diffuse[4], specular[4];
		glPushMatrix();
		glPushMatrix();
		glTranslatef(teki[0].posx, teki[0].posy, 0);

		glEnable(GL_NORMALIZE);
		glScalef(0.07, 0.07, 0.07);    //変更　02/06
		glRotatef(teki[0].posy, 0.0, 0.0, 1.0);
		glRotatef(teki[0].posy, 0.0, 0.0, 1.0);
		glRotatef(teki[0].posy, 0.0, 0.0, 1.0);
		glRotatef(teki[0].posy, 0.0, 0.0, 1.0);
		glRotatef(teki[0].roty, 0.0, 1.0, 0.0);
		if (Lunatic_flag != 1)
		{
			//ザク
			ambient[0]  = 0.3;
			ambient[1]  = 0.6;
			ambient[2]  = 0.3;
			ambient[3]  = 1.0;
			diffuse[0]  = 0.3;
			diffuse[1]  = 0.7;
			diffuse[2]  = 0.3;
			diffuse[3]  = 1.0;
			specular[0] = 0.4;
			specular[1] = 0.0;
			specular[2] = 0.4;
			specular[3] = 1.0;
		} else
		{
			//白い悪魔
			ambient[0]  = 1.1;
			ambient[1]  = 1.1;
			ambient[2]  = 1.1;
			ambient[3]  = 1.0;
			diffuse[0]  = 0.4;
			diffuse[1]  = 0.4;
			diffuse[2]  = 0.4;
			diffuse[3]  = 1.0;
			specular[0] = 0.0;
			specular[1] = 0.1;
			specular[2] = 0.1;
			specular[3] = 1.0;
		}
		draw_stl(ambient, diffuse, specular);
		glPopMatrix();
		glPopMatrix();
	}
}
