#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include <const.hpp>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
typedef struct
{
	double posx;
	double posy;
	double posz;
	double vx;
	double vy;
	double rotX;
	double rotY;
	double rotZ;
	int    tflag;
	int    shape;
	int    durability;
} property;

typedef struct
{
	float x;
	float y;
	float z;
} point;

extern double   rotX, rotY, rotZ, tx, ty, tz;
extern property enemy[ENEMY_NUMBER], missile[MISSILE_NUMBER];
extern uint8_t  background[WINDOW_WIDTH * WINDOW_HEIGHT * 3];
extern int      mouseFlag, mv, selectFlag, storyFlag, trinum;

void collisionJudge(property *enemy, property *missile);
void drawCone(float *a, float *d, float *s);
void drawCube(float *a, float *d, float *s);
void drawCylinder(float *a, float *d, float *s);
void drawDodecahedron(float *a, float *d, float *s);
void drawIcosahedron(float *a, float *d, float *s);
void drawMissile(property *missile);
void drawOctahedron(float *a, float *d, float *s);
void drawPlaneWithTexture(int i);
void drawSphere(float *a, float *d, float *s);
void drawStl(float *a, float *d, float *s, point po[][3], point nv[], int trinum);
void drawTeapot(float *a, float *d, float *s);
void drawTorus(float *a, float *d, float *s);
void enemyCharacter(property *enemy);
void idleProc(void);
void image(void);
void initEnemyProperty(property enemy[]);
void initGlSettings(void);
void initializeTexture(uint8_t TexImage[][IMAGE_WIDTH * IMAGE_HEIGHT * 3], const char *fname[], int n);
void initLightSettings(void);
void keyboardProc(uint8_t key, int x, int v);
void loadBackground(uint8_t background[]);
void loadStoryImage1(uint8_t story1[]);
void loadStoryImage2(uint8_t story2[]);
void loadTexture(int n, const char *fname[], uint8_t TexImage[][IMAGE_WIDTH * IMAGE_HEIGHT * 3]);
void motionProc(int x, int v);
void mouseProc(int button, int state, int x, int v);
void myCharacter(void);
void myCharacterStl1(point po[][3], point nv[], int trinum);
void myCircle(double r, int n);
void myDisc(double r, int n);
void mySolidCylinder(double r, double h, int n);
void myWireCylinder(double r, double h, int n);
void SolidCylinder(double r, double h, int n);
void story(int storyFlag);
void updateMissile(property *missile);
void initializeTexture(uint8_t TexImage[][IMAGE_WIDTH * IMAGE_HEIGHT * 3], const char *fname[]);
