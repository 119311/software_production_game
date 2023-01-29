#include <common.hpp>
void loadBackground(uint8_t background[])
{
	FILE *fp;
	char  buf[MAX_FILENAME_LENGTH];
	int   header_lines = 3;
	char  name[500];
	sprintf(name, "./assets/img/bg.ppm");
	if (!(fp = fopen(name, "r")))
	{
		fprintf(stderr, "Cannot open texture file %s\n", name);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < header_lines; i++)
	{
		fgets(buf, MAX_FILENAME_LENGTH, fp);
		if (*buf == '#')
			i--;
	}
	fread(background, WINDOW_HEIGHT * WINDOW_HEIGHT * 3, 1, fp);
	fclose(fp);
}
