#include "Enemy.h"
#include "Console.h"

namespace Js
{
	Enemy::Enemy() 
		: x(0)
		, y(0)
		, isActive(false)
	{
	}

	void Enemy::Spawn()
	{
		if (!isActive)
		{
			x = (rand() % 15) * 2;
			y = 0;

			isActive = true;
		}
	}

	void Enemy::Move()
	{
		if (isActive)
		{
			Js::GotoXY(x, y);
			Js::SetColor(8, 14);
			printf("¡Ú");
			y++;

			if (y > 28) isActive = false;
		}
	}
}
