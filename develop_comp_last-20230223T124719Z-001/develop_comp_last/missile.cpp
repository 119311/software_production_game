#define MAIN 0
#include "common.h"

void draw_sphere(float *, float *, float *);
void missile()
{
	float ambient[4], diffuse[4], specular[4];
	int   i;
	ambient[0]  = 0.8;
	ambient[1]  = 0.8;
	ambient[2]  = 0.0;
	ambient[3]  = 1.0;
	diffuse[0]  = 0.8;
	diffuse[1]  = 0.8;
	diffuse[2]  = 0.0;
	diffuse[3]  = 1.0;
	specular[0] = 0.8;
	specular[1] = 0.8;
	specular[2] = 0.0;
	specular[3] = 1.0;
	for (i = 0; i < misnum; i++)
	{
		if (miss[i].tflag)
		{
			glPushMatrix();
			glEnable(GL_NORMALIZE);
			glScalef(0.1, 0.1, 0.1);
			draw_sphere(ambient, diffuse, specular);
			glPopMatrix();
		}
	}
}

void teki_missile()
{
	float ambient[4], diffuse[4], specular[4];
	int   i;
	if (Lunatic_flag != 1)
	{
		//ヒートサーベル
		ambient[0]  = 1.0;
		ambient[1]  = 0.3;
		ambient[2]  = 0.0;
		ambient[3]  = 1.0;
		diffuse[0]  = 1.0;
		diffuse[1]  = 0.3;
		diffuse[2]  = 0.0;
		diffuse[3]  = 1.0;
		specular[0] = 1.0;
		specular[1] = 0.3;
		specular[2] = 0.0;
		specular[3] = 1.0;
	} else
	{
		//ビームライフル
		ambient[0]  = 1.2;
		ambient[1]  = 0.3;
		ambient[2]  = 1.0;
		ambient[3]  = 1.0;
		diffuse[0]  = 1.2;
		diffuse[1]  = 0.2;
		diffuse[2]  = 1.0;
		diffuse[3]  = 1.0;
		specular[0] = 1.2;
		specular[1] = 0.2;
		specular[2] = 1.0;
		specular[3] = 1.0;
	}
	for (i = 0; i < misnum; i++)
	{
		if (tekimiss[i].tflag)
		{
			glPushMatrix();
			glEnable(GL_NORMALIZE);
			glScalef(0.1, 0.1, 0.1);
			draw_sphere(ambient, diffuse, specular);
			glPopMatrix();
		}
	}
}

void bom()
{
	float ambient[4], diffuse[4], specular[4];
	int   i;
	ambient[0]  = 0.0;
	ambient[1]  = 0.4;
	ambient[2]  = 0.8;
	ambient[3]  = 1.0;
	diffuse[0]  = 0.0;
	diffuse[1]  = 0.4;
	diffuse[2]  = 0.8;
	diffuse[3]  = 1.0;
	specular[0] = 0.0;
	specular[1] = 0.4;
	specular[2] = 0.8;
	specular[3] = 1.0;
	if (Bom.tflag)
	{
		glPushMatrix();
		glEnable(GL_NORMALIZE);
		glScalef(0.3, 0.3, 0.3);
		draw_sphere(ambient, diffuse, specular);
		glPopMatrix();
	}
}

void draw_missile()
{
	int i;
	for (i = 0; i < misnum; i++)
	{
		if (miss[i].tflag)
		{
			miss[i].posy += 1.5;
			glPushMatrix();
			glTranslatef(miss[i].posx, miss[i].posy, 0.0);
			missile();
			glPopMatrix();
			if (miss[i].posy > MAX_Y * 2)
			{
				miss[i].posy  = myChara.posy - 150;    //自機の位置にすると当たり判定が重複する
				miss[i].tflag = 0;
			}
		}
	}
}

void draw_teki_missile()
{
	int i;
	for (i = 0; i < misnum; i++)
	{
		if (tekimiss[i].tflag)
		{
			if (Lunatic_flag != 1)
				tekimiss[i].posy -= 0.7;
			else
				tekimiss[i].posy -= 1.2;
			glPushMatrix();
			glTranslatef(tekimiss[i].posx, tekimiss[i].posy, 0.0);
			teki_missile();
			glPopMatrix();
			if (tekimiss[i].posy < MIN_Y)
			{
				tekimiss[i].posy  = teki[0].posy + 150;
				tekimiss[i].tflag = 0;
			}
		}
	}
}

void draw_bom()
{
	if (Bom.tflag)
	{
		Bom.posy += 0.4;
		glPushMatrix();
		glTranslatef(Bom.posx, Bom.posy, 0.0);
		bom();
		glPopMatrix();
		if (Bom.posy > MAX_Y * 2)
		{
			Bom.posy  = myChara.posy - 150;    //自機の位置にすると当たり判定が重複する
			Bom.tflag = 0;
		}
	}
}
