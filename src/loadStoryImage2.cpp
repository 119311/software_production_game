#include <common.hpp>

void loadStoryImage2(void)
{
	FILE *fp;
	char  buf[100];
	int   headerLines = 3;

	const char name[] = "./assets/img/title.ppm";

	if (!(fp = fopen(name, "r")))
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < headerLines; i++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			i--;
	}
	fread(story2, WINDOW_WIDTH * WINDOW_HEIGHT * 3, 1, fp);
	fclose(fp);
}
