#define Main 1
#include "./common.h"
#include "./gl_settings.h"
#include <math.h>

void myCharacter(), tekiCharacter(), draw_missile(), image();
void collision_judge();
void loadtitle(), loadBackground(), loadOperation(), loadModechange(), loadscenario1(), loadscenario2(), loadscenario3(), loadgameover(), loadgameclear(), loadPop1(), loadPop2(), loadPop3();
void draw_plane_with_texture();
void read_stl_fighter(), myCharacter_stl1(), tekiCharacter_stl1();
void init_zokusei(), init_teki_zokusei(), init_myChara_zokusei();
void draw_teki_HPbar(), draw_my_HPbar(), draw_mischarge();
void draw_teki_missile(), draw_bom();
void tekiAutoMiss();
void draw_count();

story_flag    = 0;    //ゴリ押し出力
scenario_flag = 0;    //ゴリ押し出力
auto_flag     = 0;

void image()
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	unsigned char *buf;
	static int     offset;
	int            j, k;
	int            mv = 10;
	glPixelZoom((float) X_SIZE / BXsize, (float) Y_SIZE / BYsize);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glRasterPos2f(MIN_Z, -10.0);

	// title
	if (story_flag == 0 && scenario_flag == 0)
	{
		init_zokusei();    // 耐久値初期化
		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos2f(-30, 50);
		glDrawPixels(BXsize, BYsize, GL_RGB, GL_UNSIGNED_BYTE, title);
		draw_plane_with_texture(0);

		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos3f(-5, 11, 3);
		glDrawPixels(pop_Xsize, pop_Ysize, GL_RGB, GL_UNSIGNED_BYTE, fkey1);    // Pop
		draw_plane_with_texture(0);

		glPopMatrix();
		glPopMatrix();
		glutSwapBuffers();    // 強制出力
	}

	// シナリオ出力
	else if (scenario_flag == 1)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// printf("a\n");    //デバック用
		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos3f(-30, 50, 4);
		glDrawPixels(BXsize, BYsize, GL_RGB, GL_UNSIGNED_BYTE, scenario1);
		draw_plane_with_texture(0);
		glPopMatrix();

		glutSwapBuffers();    // 強制出力
	}

	else if (scenario_flag == 2)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// printf("a\n");    //デバック用
		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos3f(-30, 50, 4);
		glDrawPixels(BXsize, BYsize, GL_RGB, GL_UNSIGNED_BYTE, scenario2);
		draw_plane_with_texture(0);
		glPopMatrix();

		glutSwapBuffers();    // 強制出力
	}

	else if (scenario_flag == 3)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// printf("a\n");    //デバック用
		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos3f(-30, 50, 4);
		glDrawPixels(BXsize, BYsize, GL_RGB, GL_UNSIGNED_BYTE, scenario3);
		draw_plane_with_texture(0);
		glPopMatrix();

		glutSwapBuffers();    // 強制出力
	}

	// 操作説明
	else if (story_flag == 1 && scenario_flag == 0)
	{
		init_zokusei();    // 耐久値初期化
		glPushMatrix();
		glDrawPixels(BXsize, BYsize, GL_RGB, GL_UNSIGNED_BYTE, background);    // 背景
		draw_plane_with_texture(0);

		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos3f(-5, 11, 3);
		glDrawPixels(pop_Xsize, pop_Ysize, GL_RGB, GL_UNSIGNED_BYTE, fkey1);    // Pop
		draw_plane_with_texture(0);

		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos3f(-18, 47, 1);
		glDrawPixels(OpeXsize, OpeYsize, GL_RGB, GL_UNSIGNED_BYTE, operate);    // 取扱説明書
		draw_plane_with_texture(0);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 5.0);
		myCharacter_stl1();

		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		glutSwapBuffers();    // 強制出力
	}

	// 操作説明2
	else if (story_flag == 2 && scenario_flag == 0)
	{
		init_zokusei();    // 耐久値初期化
		glPushMatrix();
		glDrawPixels(BXsize, BYsize, GL_RGB, GL_UNSIGNED_BYTE, background);    // 背景
		draw_plane_with_texture(0);

		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos3f(-18, 47, 1);
		glDrawPixels(OpeXsize, OpeYsize, GL_RGB, GL_UNSIGNED_BYTE, operate2);    // 取扱説明書
		draw_plane_with_texture(0);

		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos3f(-9, 11, 3);
		glDrawPixels(pop2_Xsize, pop_Ysize, GL_RGB, GL_UNSIGNED_BYTE, fkey2);    // Pop
		draw_plane_with_texture(0);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 5.0);
		myCharacter_stl1();

		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		glutSwapBuffers();    // 強制出力
	}

	// キャラ選択
	else if (select_flag == GL_TRUE)
	{
		myChara.posx = myChara.posy = 0;
		glDrawPixels(BXsize, BYsize, GL_RGB, GL_UNSIGNED_BYTE, background);
		draw_plane_with_texture(0);

		glPushMatrix();
		glTranslatef(0, 0, 10);
		myCharacter_stl1();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10, 0, 10);
		myCharacter_stl1();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(10, 0, 10);
		myCharacter_stl1();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(20, 0, 10);
		myCharacter_stl1();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-20, 0, 10);
		myCharacter_stl1();
		glPopMatrix();

		glutSwapBuffers();    // 強制出力
	}
	// gameclear
	else if (teki[0].tflag == 0)
	{

		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos2f(-30, 50);
		glDrawPixels(BXsize, BYsize, GL_RGB, GL_UNSIGNED_BYTE, gameclear);
		draw_plane_with_texture(0);

		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos3f(-9, 11, 3);
		glDrawPixels(pop2_Xsize, pop_Ysize, GL_RGB, GL_UNSIGNED_BYTE, rkey);    // Pop
		draw_plane_with_texture(0);

		glTranslatef(0, 0, 10);
		myCharacter_stl1();

		glPopMatrix();
		glPopMatrix();
		glutSwapBuffers();    // 強制出力
	}
	// gameover
	else if (myChara.tflag == 0)
	{
		glPushMatrix();
		glPixelZoom(1, -1);    // y出力反転
		glRasterPos2f(-30, 50);
		glDrawPixels(BXsize, BYsize, GL_RGB, GL_UNSIGNED_BYTE, gameover);
		draw_plane_with_texture(0);

		glPushMatrix();
		glPixelZoom(1, -1);
		glRasterPos3f(-9, 11, 3);
		glDrawPixels(pop2_Xsize, pop_Ysize, GL_RGB, GL_UNSIGNED_BYTE, rkey);    // Pop
		draw_plane_with_texture(0);

		glPopMatrix();

		glutSwapBuffers();    // 強制出力
	}

	else if (story_flag >= 3)    // ゲーム画面
	{
		// 背景ロール
		buf = (unsigned char *) malloc(BXsize * BYsize * 3);
		k   = 0;
		for (i = 0; i < (BYsize - offset); i++)
		{
			for (j = 0; j < BXsize * 3; j++)
			{
				buf[k] = background[(i + offset) * (BXsize * 3) + j];
				k++;
			}
		}
		for (i = 0; i < offset; i++)
		{
			for (j = 0; j < BXsize * 3; j++)
			{
				buf[k] = background[i * (BXsize * 3) + j];
				k++;
			}
		}
		glDrawPixels(BXsize, BYsize, GL_RGB, GL_UNSIGNED_BYTE, buf);
		free(buf);
		offset += mv;
		if (offset >= BYsize)
			offset -= BYsize;

		glPushMatrix();
		glTranslatef(0.0, 0.0, 10.0);

		if (Lunatic_flag != 1)
			draw_teki_HPbar(TEKIDUR - teki[0].durability);    // 敵機HP
		else
		{
			draw_teki_HPbar(TEKIDUR * 2 - teki[0].durability);    // 敵機HP Lunatic
		}

		// printf("%d\n",teki[0].durability);    //体力チェック
		// printf("%d\n", Lunatic_flag);    //フラグチェック

		draw_my_HPbar(MYDUR - myChara.durability);    // 自機HP
		draw_mischarge(charge);                       // ミサイルチャージゲージ

		// タイマー描画
		glRasterPos3d(-1, 0, 1);

		glRasterPos3d(-19.0, 37, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0' + minute2);
		glRasterPos3d(-18.2, 37, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0' + minute1);
		glRasterPos3d(-17.3, 37, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ':');
		glRasterPos3d(-16.6, 37, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0' + second2);
		glRasterPos3d(-15.8, 37, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0' + second1);

		tekiCharacter();
		draw_missile();
		draw_teki_missile();
		draw_bom();
		collision_judge();

		// printf("%d\n",myChara.durability);    //自機HP デバッグ用

		glPushMatrix();

		myCharacter_stl1();    // 戦闘機
		tekiCharacter_stl1();

		glPopMatrix();
		glPopMatrix();
		glutSwapBuffers();

		if (teki[1].tflag == 0)
		{
			init_teki_zokusei(1);
		}

		if (teki[3].tflag == 0)
		{
			init_teki_zokusei(3);
		}

		if (teki[4].tflag == 0)
		{
			init_teki_zokusei(4);
		}

		if (teki[5].tflag == 0)
		{
			init_teki_zokusei(5);
		}

		if (teki[6].tflag == 0)
		{
			init_teki_zokusei(6);
		}
	}
}

void tekiAutoMiss()
{
	glutTimerFunc(150, tekiAutoMiss, 0);
	static int n;
	if (story_flag >= 3)
	{
		if (Lunatic_flag != 1)
		{
			if (tekimiss[0].tflag == 0)
			{
				tekimiss[0].tflag = 1;
				tekimiss[0].posx  = teki[0].posx;
				tekimiss[0].posy  = teki[0].posy;
				n++;
				n %= misnum;
			}
		} else
		{
			if (tekimiss[n].tflag == 0)
			{
				tekimiss[n].tflag = 1;
				tekimiss[n].posx  = teki[0].posx;
				tekimiss[n].posy  = teki[0].posy;
				n++;
				n %= misnum;
			}
		}
	}
}

void myAutoMiss()
{
	glutTimerFunc(150, myAutoMiss, 0);
	static int n;
	if (auto_flag == 1)
	{
		if (story_flag >= 3)
		{
			if (miss[n].tflag == 0)
			{
				miss[n].tflag = 1;
				miss[n].posx  = myChara.posx;
				miss[n].posy  = myChara.posy;
				n++;
				n %= misnum;
			}
		}
	}
}

void flamerate()
{
	glutTimerFunc(1000 / 120, flamerate, 0);
	roty += 3.;
	if (roty >= 360.)
		roty -= 360.;
	glutPostRedisplay();
}

void timer()
{
	if (teki[0].tflag != 0)
	{
		glutTimerFunc(1000, timer, 0);
		Recoad[0] = second1;
		Recoad[1] = second2;
		Recoad[2] = minute1;
		Recoad[3] = minute2;
		second1++;
		charge++;
		// printf("%d\n" ,charge);    //デバッグ用
		// printf("%d\n" ,bomcharge);    //デバッグ用
		if (charge >= 10)
		{
			charge    = 10;
			bomcharge = 0;
		}
		if (second1 >= 10)
		{
			second1 = 0;
			second2++;
			if (second2 >= 6)
			{
				second2 = 0;
				minute1++;
				if (minute1 >= 10)
				{
					minute1 = 0;
					minute2++;
					if (minute2 >= 10)
						minute2 = 0;
				}
			}
		}
		// printf("%d %d : %d %d\n", Recoad[3], Recoad[2], Recoad[1], Recoad[0]);
	} else if (myChara.durability == MYDUR)
	{
		// ノーダメ特典
		printf("No Damage Clear!!\n");
		printf("Conguratulation!!!\n");
		if (Lunatic_flag == 1)
			printf("称号：認めたくないものだな、自分自身の若さ故の過ちというものを\n");    //ルナティック
		else
			printf("称号：チャンスは最大限に活かす、それが私の主義だ\n");    //ノーマル
		printf("clear time %d %d : %d %d\n", Recoad[3], Recoad[2], Recoad[1], Recoad[0]);
	} else
	{
		if (Lunatic_flag == 1)
			printf("称号：赤い彗星\n");    //ルナティック
		else
			printf("称号：戦いとは、常に二手三手先を読んで行うものだ\n");                    //ノーマル
		printf("clear time %d %d : %d %d\n", Recoad[3], Recoad[2], Recoad[1], Recoad[0]);    // クリアタイム
	}
}

void init_teki_zokusei(int i)
{
	// 難易度ノーマル
	if (Lunatic_flag == 0)
	{
		if (i == 0)
		{
			teki[0].shape = 1;
			teki[0].posy  = 45;
			teki[0].vx    = 0.2;
			teki[0].vy = 0, teki[0].posx = 0;
			teki[0].roty       = 0;
			teki[0].tflag      = 1;
			teki[0].durability = TEKIDUR;    // 耐久値
		}

		else if (i == 1)
		{
			teki[1].shape      = 2;
			teki[1].posy       = MAX_Y + 80;
			teki[1].posx       = 10;
			teki[1].vx         = 0.17;
			teki[1].vy         = 0.3;
			teki[1].roty       = 0;
			teki[1].tflag      = 1;
			teki[1].durability = 7;    // 耐久値
		}

		else if (i == 2)
		{
			teki[2].shape      = 3;
			teki[2].posy       = MAX_Y + 250;
			teki[2].posx       = -10;
			teki[2].vx         = -0.13;
			teki[2].vy         = 0.4;
			teki[2].roty       = 0;
			teki[2].tflag      = 1;
			teki[2].durability = 8;    // 耐久値
		}

		else if (i == 3)
		{
			teki[3].shape      = 3;
			teki[3].posy       = MAX_Y + 148;
			teki[3].posx       = 15;
			teki[3].vx         = 0.1;
			teki[3].vy         = 0.3;
			teki[3].roty       = 0;
			teki[3].tflag      = 1;
			teki[3].durability = 4;    // 耐久値
		}

		else if (i == 4)
		{
			teki[4].shape      = 3;
			teki[4].posy       = MAX_Y + 152;
			teki[4].posx       = -25;
			teki[4].vx         = 0.2;
			teki[4].vy         = 0.3;
			teki[4].roty       = 0;
			teki[4].tflag      = 1;
			teki[4].durability = 9;    // 耐久値
		}

		else if (i == 5)
		{
			teki[5].shape      = 2;
			teki[5].posy       = MAX_Y + 93;
			teki[5].posx       = 25;
			teki[5].vx         = 0.2;
			teki[5].vy         = 0.3;
			teki[5].roty       = 0;
			teki[5].tflag      = 1;
			teki[5].durability = 2;    // 耐久値
		}

		else if (i == 6)
		{
			teki[6].shape      = 4;
			teki[6].posy       = MAX_Y + 176;
			teki[6].posx       = -15;
			teki[6].vx         = -0.1;
			teki[6].vy         = 0.4;
			teki[6].roty       = 0;
			teki[6].tflag      = 1;
			teki[6].durability = 6;    // 耐久値
		}

		else if (i == 7)
		{
			for (int i = 0; i <= misnum; i++)
			{
				tekimiss[i].posx = 150;
				tekimiss[i].posy = 150;
			}
		}
	}

	// 難易度Lunatic
	else if (Lunatic_flag == 1)
	{
		if (i == 0)
		{
			teki[0].shape = 1;
			teki[0].posy  = 45;
			teki[0].vx    = 0.25;
			teki[0].vy = 0, teki[0].posx = 0;
			teki[0].roty       = 0;
			teki[0].tflag      = 1;
			teki[0].durability = (TEKIDUR * 2);    // 耐久値
		}

		else if (i == 1)
		{
			teki[1].shape      = 2;
			teki[1].posy       = MAX_Y + 80;
			teki[1].posx       = 10;
			teki[1].vx         = 0.17;
			teki[1].vy         = 0.5;
			teki[1].roty       = 0;
			teki[1].tflag      = 1;
			teki[1].durability = 15;    // 耐久値
		}

		else if (i == 2)
		{
			teki[2].shape      = 3;
			teki[2].posy       = MAX_Y + 250;
			teki[2].posx       = -10;
			teki[2].vx         = -0.03;
			teki[2].vy         = 0.1;
			teki[2].roty       = 0;
			teki[2].tflag      = 1;
			teki[2].durability = 30;    // 耐久値
		}

		else if (i == 3)
		{
			teki[3].shape      = 3;
			teki[3].posy       = MAX_Y + 148;
			teki[3].posx       = 15;
			teki[3].vx         = 0.3;
			teki[3].vy         = 1.0;
			teki[3].roty       = 0;
			teki[3].tflag      = 1;
			teki[3].durability = 4;    // 耐久値
		}

		else if (i == 4)
		{
			teki[4].shape      = 3;
			teki[4].posy       = MAX_Y + 152;
			teki[4].posx       = -25;
			teki[4].vx         = 0.15;
			teki[4].vy         = 0.09;
			teki[4].roty       = 0;
			teki[4].tflag      = 1;
			teki[4].durability = 20;    // 耐久値
		}

		else if (i == 5)
		{
			teki[5].shape      = 2;
			teki[5].posy       = MAX_Y + 93;
			teki[5].posx       = 25;
			teki[5].vx         = 0.19;
			teki[5].vy         = 0.08;
			teki[5].roty       = 0;
			teki[5].tflag      = 1;
			teki[5].durability = 30;    // 耐久値
		}

		else if (i == 6)
		{
			teki[6].shape      = 4;
			teki[6].posy       = MAX_Y + 176;
			teki[6].posx       = -15;
			teki[6].vx         = -0.13;
			teki[6].vy         = 1.0;
			teki[6].roty       = 0;
			teki[6].tflag      = 1;
			teki[6].durability = 5;    // 耐久値
		} else if (i == 7)
		{
			for (int j = 0; j <= misnum; j++)
			{
				tekimiss[j].posx = 150;
				tekimiss[j].posy = 150;
			}
		}
	}
}

void init_myChara_zokusei()
{
	myChara.posx       = 0;
	myChara.posy       = 0;
	myChara.posz       = 0;
	myChara.durability = MYDUR;
	myChara.tflag      = 1;
	rotx = roty = rotz = 0.0;
	for (int j = 0; j <= misnum; j++)
	{
		miss[j].posx = myChara.posx - 150;
		miss[j].posy = myChara.posy - 150;
	}
	Bom.posx  = myChara.posx - 150;
	Bom.posy  = myChara.posy - 150;
	bomcharge = 1;
	charge    = 0;
}

void init_zokusei()
{
	init_myChara_zokusei();
	init_teki_zokusei(0);
	init_teki_zokusei(1);
	init_teki_zokusei(2);
	init_teki_zokusei(3);
	init_teki_zokusei(4);
	init_teki_zokusei(5);
	init_teki_zokusei(6);
	init_teki_zokusei(7);
}

int main(int argc, char **argv)
{
	read_stl_fighter();
	loadtitle();
	loadBackground();
	loadOperation();
	loadModechange();
	loadscenario1();
	loadscenario2();
	loadscenario3();
	loadPop1();
	loadPop2();
	loadPop3();
	loadgameover();
	loadgameclear();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(X_SIZE, Y_SIZE);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("okdsenki");
	init_light_settings();
	init_gl_settings();
	initialize_Texture();    // append 11/22
	glPushMatrix();
	glTranslatef(0, -20, 0);
	glutDisplayFunc(image);
	glutMouseFunc(mouse_proc);
	glutMotionFunc(motion_proc);
	glutKeyboardFunc(keyboard_proc);
	glutTimerFunc(1000 / 120, flamerate, 0);    // idlecallbackの代わり（環境依存なし）
	glutTimerFunc(150, tekiAutoMiss, 0);        //敵ミサイル
	glutTimerFunc(150, myAutoMiss, 0);
	glutTimerFunc(1000, timer, 0);    //システムタイマー

	glutMainLoop();

	glPopMatrix();
	glPopMatrix();
}
