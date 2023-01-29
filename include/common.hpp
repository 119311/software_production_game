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
	double rotx;
	double roty;
	double rotz;
	int    tflag;
	int    shape;
} property;

typedef struct
{
	float x;
	float y;
	float z;
} point;

void collision_judge(property *enemy, property *missile);
void draw_sphere(float *a, float *d, float *s);
void draw_teapot(float *a, float *d, float *s);
void draw_torus(float *a, float *d, float *s);
void drawCone(float *a, float *d, float *s);
void drawCube(float *a, float *d, float *s);
void drawCylinder(float *a, float *d, float *s);
void drawDodecahedron(float *a, float *d, float *s);
void drawIcosahedron(float *a, float *d, float *s);
void drawMissile(property *missile);
void drawOctahedron(float *a, float *d, float *s);
void drawPlaneWithTexture(int i);
void enemyCharacter(property *enemy);
void idleProc(void);
void image(void);
void initEnemyProperty(property enemy[]);
void initGlSettings(void);
void initializeTexture(uint8_t TexImage[][IMAGE_WIDTH * IMAGE_HEIGHT * 3], const char *fname[]);
void initLightSettings(void);
void keyboardProc(uint8_t key, int x, int v);
void loadBackground(uint8_t background[]);
void loadTexture(int n, const char *fname[], uint8_t TexImage[][IMAGE_WIDTH * IMAGE_HEIGHT * 3]);
void motionProc(int x, int v);
void mouseProc(int button, int state, int x, int v);
void myCharacter(void);
void myCircle(double r, int n);
void myDisc(double r, int n);
void mySolidCylinder(double r, double h, int n);
void myWireCylinder(double r, double h, int n);
void SolidCylinder(double r, double h, int n);
void story(void);
void updateMissile(property *missile);
