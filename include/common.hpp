#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <array>
#include <cmath>
#include <const.hpp>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
typedef struct
{
	float posX;
	float posY;
	float posZ;
	float vx;
	float vy;
	float rotX;
	float rotY;
	float rotZ;
	int   tflag;
	int   shape;
	int   durability;
} property;

typedef struct
{
	float x;
	float y;
	float z;
} point;

extern float    rotX, rotY, rotZ, tx, ty, tz;
extern int      mouseFlag, mv, selectFlag, storyFlag, trinum;
extern property enemy[ENEMY_NUMBER], missile[MISSILE_NUMBER], player, enemyMissile[MISSILE_NUMBER];
extern int      gamePop[popXsize * popYsize * 3], background[WINDOW_WIDTH * WINDOW_HEIGHT * 3], gameClear[popXsize * popYsize * 3], gameOver[popXsize * popYsize * 3], story1[WINDOW_WIDTH * WINDOW_HEIGHT * 3], story2[WINDOW_WIDTH * WINDOW_HEIGHT * 3], TexImage[TexNum][IMAGE_WIDTH * IMAGE_HEIGHT * 3], title[WINDOW_WIDTH * WINDOW_HEIGHT * 3];

void collisionJudge(property *enemy, property *missile, property *enemyMissile);
void drawCone(const float *a, const float *d, const float *s);
void drawCube(const float *a, const float *d, const float *s);
void drawCylinder(const float *a, const float *d, const float *s);
void drawDodecahedron(const float *a, const float *d, const float *s);
void drawEnemyHitPointBar(int c);
void drawEnemyMissile(void);
void drawIcosahedron(const float *a, const float *d, const float *s);
void drawMissile(void);
void drawPlayerHitPointBar(int c);
void drawOctahedron(const float *a, const float *d, const float *s);
void drawPlane(void);
void drawPlaneWithTexture(int i);
void drawSphere(const float *a, const float *d, const float *s);
void drawStl(const float *a, const float *d, const float *s, point po[][3], point nv[], int trinum);
void drawTeapot(const float *a, const float *d, const float *s);
void drawTorus(const float *a, const float *d, const float *s);
void enemyCharacter(property *enemy);
void idleProc(void);
void image(void);
void initEnemyProperty(int i, property enemy[]);
void initGlSettings(void);
void initializeTexture(int TexImage[][IMAGE_WIDTH * IMAGE_HEIGHT * 3], const char *fname[]);
void initLightSettings(void);
void initPlayerProperty(void);
void initProperty(void);
void keyboardProc(uint8_t key, int x, int v);
void loadBackground(int background[]);
void loadGameClear(int gameClear[]);
void loadGameOver(int gameOver[]);
void loadStoryImage1(int story1[]);
void loadStoryImage2(void);
void loadTexture(int n, const char *fname[], int TexImage[][IMAGE_WIDTH * IMAGE_HEIGHT * 3]);
void loadTitle(int title[]);
void motionProc(int x, int v);
void mouseProc(int button, int state, int x, int y);
void playerCircle(const float r, int n);
void playerDisc(const float r, int n);
void playerSolidCylinder(const float r, const float h, int n);
void playerStl1(point po[][3], point nv[], int trinum);
void playerWireCylinder(const float r, const float h, int n);
void readStlFighter(point po[][3], point nv[], int trinum);
void SolidCylinder(const float r, const float h, int n);
void story(int storyFlag);
void updateEnemyMissile(void);
void updateMissile(void);
void updatePlayer(void);
