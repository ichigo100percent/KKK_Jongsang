#include "Bullet.h"
#include "Console.h"
#include "Player.h"

namespace Js
{
	Bullet::Bullet(std::weak_ptr<class Player> _set)
		: myPlayer(_set)
		, x(0)
		, y(0)
		, isActive(false)
	{
	}

	void Bullet::Shot()
	{
		if (auto locked = myPlayer.lock())
		{
			x = locked->GetX();
			y = locked->GetY() - 1;
			isActive = true;
		}
	}

	void Bullet::Move()
	{
		if (GetActive())
		{
			Js::GotoXY(x, y);
			Js::SetColor(8, 0);
			printf("ก่");
			y--;
			if (y < 0) isActive = false;
		}
	}

}
