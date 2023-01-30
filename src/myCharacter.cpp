#include <common.hpp>

void updatePlayer(void)
{
	if (player.tflag)
	{
		glPushMatrix();
		glEnable(GL_NORMALIZE);
		glScalef(0.6, 0.7, 0.1);
		drawPlaneWithTexture(0);
		glPopMatrix();
	}
}
