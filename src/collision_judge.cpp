#include <common.hpp>
void collisionJudge(property *enemy, property *missile)
{
	for (int j = 0; j < MISSILE_NUMBER; j++)
	{
		for (int i = 0; i < ENEMY_NUMBER; i++)
		{
			double d = std::hypot(enemy[i].posx - missile[j].posx, enemy[i].posy - missile[j].posy);
			if (d < DIS)
			{
				if (enemy[i].durability-- <= 0)
					enemy[i].tflag = 0;
				missile[j].tflag = 0;
				missile[j].posy  = 0.0;
				break;
			}
		}
	}
}
