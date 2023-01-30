#include <common.hpp>

void loadTitle(int title[])
{
	FILE *fp;
	char  buf[100];
	int   headerLines = 3;

	const char name[] = "./assets/img/title.ppm";

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
	fread(title, WINDOW_WIDTH * WINDOW_HEIGHT * 3, 1, fp);
	fclose(fp);
}
