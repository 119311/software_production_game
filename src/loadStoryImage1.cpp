#include <common.hpp>

void loadStoryImage1(uint8_t story1[])
{
	FILE *fp;
	char  buf[100];
	char  name[500];
	int   header_lines = 3;
	sprintf(name, "./okd.ppm");
	if (!(fp = fopen(name, "r")))
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(EXIT_SUCCESS);
	}
	for (int j = 0; j < header_lines; j++)
	{
		fgets(buf, 100, fp);
		if (*buf == '#')
			j--;
	}
	fread(story1, WINDOW_HEIGHT * WINDOW_HEIGHT * 3, 1, fp);
	fclose(fp);
}
