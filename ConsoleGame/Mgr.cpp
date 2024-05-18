#include "Mgr.h"
#include "Console.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <conio.h>
namespace Js
{
    Mgr::Mgr()
        : m_Player(nullptr) 
        , m_Bullets() 
        , m_Enemys()  
    {
    }

    void Mgr::Init()
    {
        m_Player = std::make_shared<Player>(14, 28);
        m_Bullets.resize(30);
        m_Enemys.resize(30);

		for (int i = 0; i < m_Bullets.size(); ++i)
		{
			m_Bullets[i] = std::make_shared<Bullet>(m_Player);
		}

		for (int i = 0; i < m_Enemys.size(); ++i)
		{
			m_Enemys[i] = std::make_shared<Enemy>();
		}
    }

    void Mgr::Update()
    {
		while (1)
		{
			Clear();

			start();
			play();

			Sleep(50);
			SetColor(8, 0);
		}
    }
	void Mgr::start()
	{
		while (1)
		{
			Clear();

			Js::GotoXY(10, 14);
			Js::SetColor(8, 15);
			printf("Game Start! \n");
			Js::GotoXY(8, 15);
			printf("Press Any keys..\n");
			
			if (_kbhit() != 0)
				return;

			Sleep(50);
			SetColor(8, 0);
		}
	}
	void Mgr::play()
	{
		while (1)
		{
			Clear();

			for (auto& e : m_Enemys)
			{
				if (!e->GetActive())
				{
					e->Spawn();
					break;
				}
			}

			if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			{
				for (auto& e : m_Bullets)
				{
					if (!e->GetActive())
					{
						e->Shot();
						break;
					}
				}
			}

			for (auto& e : m_Bullets)
			{
				e->Move();
			}

			for (auto& e : m_Enemys)
			{
				e->Move();
			}
			m_Player->move();
			Sleep(50);
			SetColor(8, 0);
		}
	}
	void Mgr::end()
	{
	}
}