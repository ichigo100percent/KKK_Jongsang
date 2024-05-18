#pragma once

namespace Js
{
	class Player
	{
	public:
		Player(int _x, int _y);
		
		void move();
		int GetX() { return x; }
		int GetY() { return y; }

	private:
		int x;
		int y;
	};
}