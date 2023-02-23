#include "./common.h"
#include <math.h>
#define DIS     3
#define mis_DIS 4
#define bom_DIS 5

void collision_judge()
{
	int   i, j;
	float d_miss, d_myChara, d_tekimiss, d_bom;
	for (j = 0; j < misnum; j++)
	{
		for (i = 0; i < tekinum; i++)
		{
			//自機ミサイルと隕石
			d_miss = sqrt((teki[i].posx - miss[j].posx) * (teki[i].posx - miss[j].posx) + (teki[i].posy - miss[j].posy) * (teki[i].posy - miss[j].posy));

			//敵ミサイルと自機の距離
			d_tekimiss = sqrt((myChara.posx - tekimiss[j].posx) * (myChara.posx - tekimiss[j].posx) + (myChara.posy - tekimiss[j].posy) * (myChara.posy - tekimiss[j].posy));

			//ボムと敵の距離
			d_bom = sqrt((teki[i].posx - Bom.posx) * (teki[i].posx - Bom.posx) + (teki[i].posy - Bom.posy) * (teki[i].posy - Bom.posy));

			//隕石と自機の距離
			d_myChara = sqrt((myChara.posx - teki[i].posx) * (myChara.posx - teki[i].posx) + (myChara.posy - teki[i].posy) * (myChara.posy - teki[i].posy));

			//自機ミサイルが敵にあたったとき
			if (d_miss < mis_DIS)
			{
				// printf("c\n");    //checksum
				teki[i].durability -= 1;        //耐久値を減らす
				if (teki[i].durability <= 0)    //耐久値が0以下
					teki[i].tflag = 0;          //表示を消す
				miss[j].tflag = 0;
				miss[j].posy  = myChara.posy - 150;    //当たり判定の重複回避
				miss[j].posx  = myChara.posx - 150;    //当たり判定の重複回避
				break;
			}

			//敵ミサイルが自機にあたったとき
			if (d_tekimiss < DIS)
			{
				// printf("b\n");    //checksum
				if (Lunatic_flag != 1)
					myChara.durability -= 1;    //耐久値を減らす
				else
					myChara.durability -= 2;    //耐久値を減らす
				if (myChara.durability <= 0)    //耐久値が0以下
					myChara.tflag = 0;          //表示を消す
				tekimiss[j].tflag = 0;
				tekimiss[j].posy  = teki[0].posy + 150;
				tekimiss[j].posx  = teki[0].posx + 150;
				break;
			}

			// bomが敵にあたったとき
			if (d_bom < bom_DIS)
			{
				// printf("a\n");    //checksum
				teki[i].durability -= 20;    //耐久値を減らす
				Bom.tflag = 0;
				Bom.posy  = myChara.posy - 150;    //当たり判定の重複回避
				Bom.posx  = myChara.posx - 150;    //当たり判定の重複回避
				if (teki[i].durability <= 0)       //耐久値が0以下
					teki[i].tflag = 0;             //表示を消す
				break;
			}

			//隕石が自機にあたったとき
			if (d_myChara < DIS)
			{
				// printf("d\n");    //checksum
				teki[i].tflag = 0;
				teki[i].posx  = +150;    //当たり判定の重複回避
				teki[i].posy  = +150;    //当たり判定の重複回避
				if (Lunatic_flag != 1)
					myChara.durability -= 1;
				else
					myChara.durability -= 2;
				if (myChara.durability <= 0)
					myChara.tflag = 0;

				break;
			}
		}
	}
}
