#pragma once
#include <memory>

namespace Js
{
	class Bullet
	{
	public:
		Bullet(std::weak_ptr<class Player> _set);

		bool GetActive() const { return isActive; }
		void Shot();
		void Move();

	private:
		int x;
		int y;
		bool isActive;
		std::weak_ptr<class Player> myPlayer;
	};
}
