#include "./common.h"
#include <string.h>

char fname[][100] = {"myPicture.ppm",
                     "teki1.ppm",
                     "teki2.ppm",
                     "teki3.ppm",
                     "teki4.ppm"};

void loadTexture(int n)
{
	char folderpath[20] = "./img/";
	strcat(folderpath, fname[n]);
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	if ((fp = fopen(folderpath, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", fname[n]);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(TexImage[n], ImWidth * ImHeight * 3, 1, fp);
	fclose(fp);
}

void initialize_Texture()
{
	int i;
	for (i = 0; i < TexNum; i++)
	{
		loadTexture(i);
		glPixelStorei(GL_UNPACK_ALIGNMENT, i);
		glBindTexture(GL_TEXTURE_2D, i);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ImWidth, ImHeight,
		             0, GL_RGB, GL_UNSIGNED_BYTE, TexImage[i]);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_AUTO_NORMAL);
		glEnable(GL_NORMALIZE);
		glEnable(GL_DEPTH_TEST);
		glFrontFace(GL_CW);
	}
}
