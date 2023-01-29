#include <common.hpp>
double   rotX = 0.0, rotY = 0.0, rotZ = 0.0, tx = 0.0, ty = 0.0, tz = 0.0;
property enemy[ENEMY_NUMBER], missile[MISSILE_NUMBER];
uint8_t  background[WINDOW_WIDTH * WINDOW_HEIGHT * 3];
int      mouseFlag = 0, mv = 0, selectFlag = 0, storyFlag = 0, backFlag = 0, trinum = 0;

int main(int argc, char **argv)
{
	point   po[trinum][3], nv[trinum];
	uint8_t TexImage[TexNum][IMAGE_WIDTH * IMAGE_HEIGHT * 3];
	uint8_t story1[WINDOW_HEIGHT * WINDOW_HEIGHT * 3];
	uint8_t story2[WINDOW_HEIGHT * WINDOW_HEIGHT * 3];

	const char *fname[MAX_FILENAME_LENGTH] = {"./assets/img/myPicture.ppm", "./assets/img/enemy1.ppm", "./assets/img/enemy2.ppm", "./assets/img/enemy3.ppm", "./assets/img/enemy4.ppm"};
	story(storyFlag);
	initEnemyProperty(enemy);
	loadBackground(background);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("sample1");
	initLightSettings();
	initGlSettings();
	initializeTexture(TexImage, fname);
	glPushMatrix();
	glTranslatef(0, -20, 0);
	glutDisplayFunc(image);
	glutMouseFunc(mouseProc);
	glutMotionFunc(motionProc);
	glutKeyboardFunc(keyboardProc);
	glutIdleFunc(idleProc);
	glutMainLoop();
	glPopMatrix();
	glPopMatrix();
}
