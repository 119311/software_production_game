#include <common.hpp>

void initEnemyProperty(int i, property enemy[])

{
	if (i == 0)
	{
		enemy[0].shape      = 1;
		enemy[0].posY       = 45;
		enemy[0].vx         = 0.2;
		enemy[0].vy         = 0;
		enemy[0].rotY       = 0;
		enemy[0].tflag      = 1;
		enemy[0].durability = 100;
	} else if (i == 1)
	{
		enemy[1].shape      = 2;
		enemy[1].posY       = MAX_Y + 80;
		enemy[1].posX       = 10;
		enemy[1].vx         = 0.15;
		enemy[1].vy         = 0.6;
		enemy[1].rotY       = 0;
		enemy[1].tflag      = 1;
		enemy[1].durability = 1;
	} else if (i == 2)
	{
		enemy[2].shape      = 3;
		enemy[2].posY       = MAX_Y + 50;
		enemy[2].posX       = -10;
		enemy[2].vx         = -0.13;
		enemy[2].vy         = 0.4;
		enemy[2].rotY       = 0;
		enemy[2].tflag      = 1;
		enemy[2].durability = 2;
	} else if (i == 3)
	{
		enemy[3].shape      = 3;
		enemy[3].posY       = MAX_Y + 48;
		enemy[3].posX       = 15;
		enemy[3].vx         = 0.2;
		enemy[3].vy         = 0.3;
		enemy[3].rotY       = 0;
		enemy[3].tflag      = 1;
		enemy[3].durability = 3;
	} else if (i == 4)
	{
		enemy[4].shape      = 3;
		enemy[4].posY       = MAX_Y + 52;
		enemy[4].posX       = -25;
		enemy[4].vx         = 0.1;
		enemy[4].vy         = 0.5;
		enemy[4].rotY       = 0;
		enemy[4].tflag      = 1;
		enemy[4].durability = 4;
	} else if (i == 5)
	{
		enemy[5].shape      = 2;
		enemy[5].posY       = MAX_Y + 93;
		enemy[5].posX       = 25;
		enemy[5].vx         = 0.2;
		enemy[5].vy         = 0.7;
		enemy[5].rotY       = 0;
		enemy[5].tflag      = 1;
		enemy[5].durability = 2;
	} else if (i == 6)
	{
		enemy[6].shape      = 4;
		enemy[6].posY       = MAX_Y + 76;
		enemy[6].posX       = -15;
		enemy[6].vx         = -0.3;
		enemy[6].vy         = 0.5;
		enemy[6].rotY       = 0;
		enemy[6].tflag      = 1;
		enemy[6].durability = 6;
	}
}
