#include <common.hpp>

void loadTexture(int n, const char *fname[], int TexImage[][IMAGE_WIDTH * IMAGE_HEIGHT * 3])
{
	FILE *fp;
	char  buf[MAX_FILENAME_LENGTH];
	int   headerLines = 3;
	if (!(fp = fopen(fname[n], "r")))
	{
		fprintf(stderr, "Cannot open texture file %s\n", fname[n]);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < headerLines; i++)
	{
		fgets(buf, MAX_FILENAME_LENGTH, fp);
		if (*buf == '#')
			i--;
	}
	fread(TexImage[n], IMAGE_WIDTH * IMAGE_HEIGHT * 3, 1, fp);
	fclose(fp);
}
