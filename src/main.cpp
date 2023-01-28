#define Main 1
#include <common.hpp>
struct zokusei teki[ENEMY_NUMBER], miss[MISSILE_NUMBER];
struct point   po[TRINUM][3], nv[TRINUM];
double         rotx, roty, rotz;
double         TX, TY, TZ;
int            mouse_flag;
int            mv, back_flag;
int            trinum;
unsigned char  TexImage[TexNum][ImWidth * ImHeight * 3];
unsigned char  background[BXsize * BYsize * 3];
int main(int argc, char **argv)
{
	story();
	init_zokusei();
	loadBackground();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(X_SIZE, Y_SIZE);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("sample1");
	init_light_settings();
	init_gl_settings();
	initialize_Texture();
	glPushMatrix();
	glTranslatef(0, -20, 0);
	glutDisplayFunc(image);
	glutMouseFunc(mouse_proc);
	glutMotionFunc(motion_proc);
	glutKeyboardFunc(keyboard_proc);
	glutIdleFunc(idle_proc);
	glutMainLoop();
	glPopMatrix();
	glPopMatrix();
}
