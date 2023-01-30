#include <common.hpp>

void collisionJudge(property *enemy, property *missile, property *enemyMissile)
{
	for (int j = 0; j < MISSILE_NUMBER; j++)
	{
		for (int i = 0; i < ENEMY_NUMBER; i++)
		{
			const float distanceMissile      = std::hypot(enemy[i].posX - missile[j].posX, enemy[i].posY - missile[j].posY);
			const float distanceEnemyMissile = std::hypot(player.posX - enemyMissile[j].posX, player.posY - enemyMissile[j].posY);
			if (distanceMissile < DIS)
			{
				enemy[i].durability -= 1;
				if (enemy[i].durability <= 0)
					enemy[i].tflag = 0;
				missile[j].tflag = 0;
				missile[j].posY  = player.posY;
				break;
			}
			if (distanceEnemyMissile < DIS)
			{
				player.durability -= 1;
				if (player.durability <= 0)
					player.tflag = 0;
				enemyMissile[j].tflag = 0;
				enemyMissile[j].posY  = enemy[0].posY;
				break;
			}
		}
	}
	for (int i = 0; i < ENEMY_NUMBER; i++)
	{
		const float distancePlayer = std::hypot(enemy[i].posX - player.posX, enemy[i].posY - player.posY);
		if (distancePlayer < DIS)
		{
			enemy[i].tflag = 0;
			player.durability -= 1;
			if (player.durability <= 0)
				player.tflag = 0;
			break;
		}
	}
}
