#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#define MAX_X      30
#define MIN_X      -30
#define MAX_Y      30
#define MIN_Y      -30
#define MAX_Z      30
#define MIN_Z      -30
#define X_SIZE     1200
#define Y_SIZE     800
#define XRATE      (X_SIZE / (float) (MAX_X - MIN_X))
#define tekinum    7
#define misnum     3
#define BXsize     1200
#define BYsize     800
#define OpeXsize   720
#define OpeYsize   480
#define pop_Xsize  240
#define pop2_Xsize 350
#define pop_Ysize  60
#define TRINUM     100000
#define MYDUR      10
#define TEKIDUR    150

// Textureイメージのサイズ
#define ImWidth  120    // appended 11/22
#define ImHeight 160    // appended 11/22
#define TexNum   2      // appended 11/22

#ifdef Main
#define FLOAT  float
#define INT    int
#define STRUCT struct
#define UCHAR  unsigned char    // appended 12/16
#else
#define FLOAT  extern float
#define INT    extern int
#define STRUCT extern struct
#define UCHAR  extern unsigned char    // appended 11/22
#endif

FLOAT rotx, roty, rotz;
INT   mouse_flag, story_flag, select_flag, scenario_flag, Lunatic_flag, auto_flag;
INT   mv, back_flag, bomcharge, second1, second2, minute1, minute2, charge;    // For Rolling Background image
UCHAR Recoad[4];
UCHAR TexImage[TexNum][ImWidth * ImHeight * 3];    // appended 11/22
UCHAR background[BXsize * BYsize * 3];
UCHAR title[BXsize * BYsize * 3];
UCHAR operate[OpeXsize * OpeYsize * 3];
UCHAR operate2[OpeXsize * OpeYsize * 3];
UCHAR fkey1[pop_Xsize * pop_Ysize * 3];
UCHAR fkey2[pop2_Xsize * pop_Ysize * 3];
UCHAR rkey[pop2_Xsize * pop_Ysize * 3];
UCHAR scenario1[BXsize * BYsize * 3];
UCHAR scenario2[BXsize * BYsize * 3];
UCHAR scenario3[BXsize * BYsize * 3];
UCHAR gameover[BXsize * BYsize * 3];
UCHAR gameclear[BXsize * BYsize * 3];
UCHAR gamepop[pop_Xsize * pop_Ysize * 3];

STRUCT zokusei
{
	float posx;
	float posy;
	float posz;
	float vx;
	float vy;
	float rotx;
	float roty;
	float rotz;
	int   tflag;    //見えるor消える判定
	int   shape;    //形のフラグ
	int   durability;
}
teki[tekinum], miss[misnum], myChara, tekimiss[misnum], Bom;

STRUCT point
{
	float x;
	float y;
	float z;
}
po[TRINUM][3], nv[TRINUM];
INT trinum;

#ifdef Main
void keyboard_proc(unsigned char, int, int);
void mouse_proc(int, int, int, int);
void motion_proc(int, int);
void initialize_Texture(void);    // appended 11/22
#endif
