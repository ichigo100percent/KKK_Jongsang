#include "GameMgr.h"
#include "Player.h"
namespace Js
{
	GameMgr::GameMgr()
		: m_Player(nullptr)
	{
		
	}

	void GameMgr::Init()
	{

	}

	void GameMgr::Update()
	{
		enterRobby();
	}

	void GameMgr::enterRobby()
	{

		int n;

		while (true)
		{
			printRobby();

			std::cout << "                    �޴��� �������ּ��� !                 " << std::endl << std::endl;
			std::cout << " 1. ĳ���� �����ϱ�                     2. �����ϱ�       " << std::endl << std::endl;

			std::cin >> n;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


			switch (n)
			{
			case 1:
				createPlayer();
				break;
			case 2:
				return;
			default:
				break;
			}
		}
	}
	
	void GameMgr::createPlayer()
	{
		std::string name;

		while (true)
		{
			system("cls");
			std::cout << "***************************************************************" << std::endl << std::endl;
			std::cout << "                      �÷��̾� ����â                          " << std::endl << std::endl;
			std::cout << "***************************************************************" << std::endl << std::endl;


			std::cout << "�÷��̾� �̸��� �Է����ּ��� ! " << std::endl;
			std::getline(std::cin, name);

			m_Player = std::make_shared<Knight>(name);

			if (m_Player != nullptr)
			{
				system("cls");
				m_Player->PrintSTATE();
				std::cout << "ĳ���� ������ �����Ͽ����ϴ�!" << std::endl << std::endl;
				std::cin.get();
			}
			else
			{
				system("cls");
				std::cout << "ĳ���� ������ �����Ͽ����ϴ�.." << std::endl;
				std::cout << "��ư�� ������ �κ�� ���ư��ϴ�.." << std::endl;
					
				std::cin.get();
				return;
			}		
		}
	}

	void GameMgr::printRobby()
	{
		system("cls");
		std::cout << "***************************************************************" << std::endl << std::endl;
		std::cout << "                   WELCOME TO TEXT RPG WORLD!                  " << std::endl << std::endl;
		std::cout << "***************************************************************" << std::endl << std::endl;
	}

}