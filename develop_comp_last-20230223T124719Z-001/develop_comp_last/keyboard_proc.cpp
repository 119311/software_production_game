#include "./common.h"
#include <stdlib.h>

void init_zokusei();
void timer();
void bom_charge();
void keyboard_proc(unsigned char key, int x, int y)
{
	static int n;
	int        i;
	switch (key)
	{
		case 'x':
			rotx += 3.0;
			break;
		case 'X':
			rotx -= 3.0;
			break;
		case 'y':
			roty += 3.0;
			break;
		case 'Y':
			roty -= 3.0;
			break;
		case 'z':
			rotz += 3.0;
			break;
		case 'Z':
			rotz -= 3.0;
			break;
		case ' ':    //自機ミサイル
			if (auto_flag == 0)
			{
				if (miss[n].tflag == 0)
				{
					miss[n].tflag = 1;
					miss[n].posx  = myChara.posx;
					miss[n].posy  = myChara.posy;
					n++;
					n %= misnum;
				}
			} else
			{
				if (bomcharge == 0)
				{
					Bom.tflag = 1;
					bomcharge = 1;
					Bom.posx  = myChara.posx;
					Bom.posy  = myChara.posy;
					charge    = 0;
				}
			}
			break;
		case 't':    //敵ミサイル
			if (tekimiss[n].tflag == 0)
			{
				tekimiss[n].tflag = 1;
				tekimiss[n].posx  = teki[0].posx;
				tekimiss[n].posy  = teki[0].posy;
				n++;
				n %= misnum;
			}
			break;
		case 'b':    //自機ボム
			if (bomcharge == 0)
			{
				Bom.tflag = 1;
				bomcharge = 1;
				Bom.posx  = myChara.posx;
				Bom.posy  = myChara.posy;
				charge    = 0;
			}
			break;
		case 'u':
			mv++;
			break;
		case 'p':
			for (i = 0; i < tekinum; i++)
			{
				init_zokusei();
			}
			break;
		case 'q':
			exit(1);

			if (select_flag == GL_FALSE)
			{
				case 'd':
					myChara.posx += 2.0;
					if (myChara.posx >= 25)    // Xの移動上限
						myChara.posx = 25;
					break;
				case 'a':
					myChara.posx -= 2.0;
					if (myChara.posx <= -25)    // Xの移動上限
						myChara.posx = -25;
					break;
				case 'w':
					myChara.posy += 2.0;
					if (myChara.posy >= 20)    // Yの移動上限
						myChara.posy = 20;
					break;
				case 's':
					myChara.posy -= 2.0;
					if (myChara.posy <= -5)    // Yの移動上限
						myChara.posy = -5;
					break;
				case 'f':
					if (scenario_flag < 1)
					{
						story_flag += 1;
						second1 = 0;
						second2 = 0;
						minute1 = 0;
						minute2 = 0;
						if (story_flag >= 3)
							story_flag == 3;
					} else if (scenario_flag >= 1)
					{
						scenario_flag += 1;
						if (scenario_flag >= 4)
							scenario_flag = 0;
					}
					break;
				case 'g':
					if (story_flag == 0 && scenario_flag == 0)
						scenario_flag = 1;
					break;
				case 'l':
					if (story_flag == 2)
					{
						if (Lunatic_flag == 0)
						{
							Lunatic_flag = 1;
							printf("Lunatic Mode\n");
						} else if (Lunatic_flag == 1)
						{
							Lunatic_flag = 0;
							printf("Normal Mode\n");
						}
					}
					break;
				case 'm':
					if (auto_flag == 0)
					{
						auto_flag = 1;
						printf("オート射撃\n");
					} else
					{
						auto_flag = 0;
						printf("マニュアル射撃\n");
					}
					break;
			}

		case 'c':
			select_flag += 1;
			if (select_flag >= 2)
			{
				myChara.posx = myChara.posy = 0;
				select_flag                 = GL_FALSE;
				init_zokusei();
			}
			break;
		case 'r':
			if (story_flag != 0 && teki[0].tflag == 0)    //タイマー再起
				glutTimerFunc(1000, timer, 0);
			story_flag    = 0;
			scenario_flag = 0;
			Lunatic_flag  = 0;
			init_zokusei();
			auto_flag = 0;

			break;
	}
	if (rotx >= 360.)
		rotx -= 360.;
	if (rotx < 0.)
		rotx += 360.;
	if (roty >= 360.)
		rotx -= 360.;
	if (roty < 0.)
		roty += 360.;
	if (rotz >= 360.)
		rotx -= 360.;
	if (rotz < 0.)
		rotz += 360.;

	glutPostRedisplay();
}
