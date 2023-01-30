#include <common.hpp>

void loadGameClear(int gameClear[])
{
	FILE *fp;
	char  buf[100];
	int   headerLines = 3;

	const char name[] = "./assets/img/GCscreen.ppm";

	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(EXIT_FAILURE);
	}
	for (int j = 0; j < headerLines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(gameClear, WINDOW_WIDTH * WINDOW_HEIGHT * 3, 1, fp);
	fclose(fp);
}
