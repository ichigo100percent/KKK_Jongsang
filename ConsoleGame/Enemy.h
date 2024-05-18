#pragma once

namespace Js
{
	class Enemy
	{
	public:
		Enemy();

		void Spawn();
		void Move();
		bool GetActive() { return isActive; }

	private:
		int x;
		int y;
		bool isActive;
	};
}
