#include "./common.h"
#include <stdio.h>

void read_stl_fighter()
{
	FILE        *fi;
	char         name[150];
	char         head[80];
	float        N[3], P[9];
	int          n, i, j, t;
	signed short c;

	sprintf(name, "./stl/fighter4826.stl");    //戦闘機のstlファイルを読み込み
	if ((fi = fopen(name, "r")) == NULL)
	{
		printf("Error \n");
		exit(1);
	}
	fread(head, 1, 80, fi);
	fread(&n, 4, 1, fi);
	trinum = n;
	for (i = 0; i < n; i++)
	{
		fread(N, 4, 3, fi);
		nv[i].x = N[0];
		nv[i].y = N[1];
		nv[i].z = N[2];
		fread(P, 4, 9, fi);
		po[i][0].x = P[0];
		po[i][0].y = P[1];
		po[i][0].z = P[2];
		po[i][1].x = P[3];
		po[i][1].y = P[4];
		po[i][1].z = P[5];
		po[i][2].x = P[6];
		po[i][2].y = P[7];
		po[i][2].z = P[8];
		fread(&c, 2, 1, fi);
	}
	fclose(fi);

	//重心を求め,オブジェクトの中心を原点とする
	float sumx, sumy, sumz;
	sumx = sumy = sumz = 0.;

	for (i = 0; i < trinum; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sumx += po[i][j].x;
			sumy += po[i][j].y;
			sumz += po[i][j].z;
		}
	}
	sumx /= (trinum * 3.);
	sumy /= (trinum * 3.);
	sumz /= (trinum * 3.);

	for (i = 0; i < trinum; i++)
	{
		for (j = 0; j < 3; j++)
		{
			po[i][j].x -= sumx;
			po[i][j].y -= sumy;
			po[i][j].z -= sumz;
		}
	}
}
