#include <common.hpp>
void drawPlaneWithTexture(int i)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, i);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-5.0, -5.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(+5.0, -5.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(+5.0, +5.0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-5.0, +5.0, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
