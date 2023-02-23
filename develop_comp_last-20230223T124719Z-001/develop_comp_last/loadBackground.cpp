#include "./common.h"

void loadBackground()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/bg.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(background, BXsize * BYsize * 3, 1, fp);
	fclose(fp);
}

void loadtitle()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/title.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(title, BXsize * BYsize * 3, 1, fp);
	fclose(fp);
}

void loadOperation()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/soft_operationimg.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(operate, OpeXsize * OpeYsize * 3, 1, fp);
	fclose(fp);
}

void loadModechange()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/modechange.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(operate2, OpeXsize * OpeYsize * 3, 1, fp);
	fclose(fp);
}

void loadPop1()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/fkey.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(fkey1, pop_Xsize * pop_Ysize * 3, 1, fp);
	fclose(fp);
}

void loadPop2()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/fkey2.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(fkey2, pop2_Xsize * pop_Ysize * 3, 1, fp);
	fclose(fp);
}

void loadPop3()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/rkey.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(rkey, pop2_Xsize * pop_Ysize * 3, 1, fp);
	fclose(fp);
}

void loadscenario1()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/scenario1.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(scenario1, BXsize * BYsize * 3, 1, fp);
	fclose(fp);
}

void loadscenario2()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/scenario2.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(scenario2, BXsize * BYsize * 3, 1, fp);
	fclose(fp);
}

void loadscenario3()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/scenario3.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(scenario3, BXsize * BYsize * 3, 1, fp);
	fclose(fp);
}

void loadgameover()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/GOscreen.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(gameover, BXsize * BYsize * 3, 1, fp);
	fclose(fp);
}

void loadgameclear()
{
	FILE *fp;
	char  buf[100];
	int   i, j;
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./img/GCscreen.ppm");
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(0);
	}
	for (j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(gameclear, BXsize * BYsize * 3, 1, fp);
	fclose(fp);
}
