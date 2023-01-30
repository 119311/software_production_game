#include <common.hpp>

void loadStoryImage1(int story1[])
{
	FILE      *fp;
	char       buf[100];
	const char name[]      = "./assets/img/okd.ppm";
	int        headerLines = 3;
	if (!(fp = fopen(name, "r")))
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
	fread(story1, WINDOW_HEIGHT * WINDOW_HEIGHT * 3, 1, fp);
	fclose(fp);
}
