#include <common.hpp>

void loadTexture(int n, const char *fname[], uint8_t TexImage[][IMAGE_WIDTH * IMAGE_HEIGHT * 3])
{
	FILE *fp;
	char  buf[MAX_FILENAME_LENGTH];
	int   header_lines = 3;
	if (!(fp = fopen(fname[n], "r")))
	{
		fprintf(stderr, "Cannot open texture file %s\n", fname[n]);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < header_lines; i++)
	{
		fgets(buf, MAX_FILENAME_LENGTH, fp);
		if (*buf == '#')
			i--;
	}
	fread(TexImage[n], IMAGE_WIDTH * IMAGE_HEIGHT * 3, 1, fp);
	fclose(fp);
}
