#include "Player.h"
#include "Console.h"

namespace Js
{
	Player::Player(int _x, int _y)
		: x(_x)
		, y(_y)
	{
	}
	void Player::move()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			x--;
			if (x < 0) x = 0;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			x++;
			if (x > 28) x = 28;
		}
		Js::GotoXY(x, y);
		Js::SetColor(8, 4);
		printf("бу");
	}
}