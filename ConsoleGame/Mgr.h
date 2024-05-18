#pragma once
#include <vector>
#include <memory>


namespace Js
{
	class Mgr
	{
	public:
		Mgr();

		void Init();
		void Update();

	private:
		void start();
		void play();
		void end();

	private:
		std::shared_ptr<class Player> m_Player;
		std::vector<std::shared_ptr<class Bullet>> m_Bullets;
		std::vector<std::shared_ptr<class Enemy>> m_Enemys;
	};
}
