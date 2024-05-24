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

			std::cout << "                    메뉴를 선택해주세요 !                 " << std::endl << std::endl;
			std::cout << " 1. 캐릭터 생성하기                     2. 종료하기       " << std::endl << std::endl;

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
			std::cout << "                      플레이어 생성창                          " << std::endl << std::endl;
			std::cout << "***************************************************************" << std::endl << std::endl;


			std::cout << "플레이어 이름을 입력해주세요 ! " << std::endl;
			std::getline(std::cin, name);

			m_Player = std::make_shared<Knight>(name);

			if (m_Player != nullptr)
			{
				system("cls");
				m_Player->PrintSTATE();
				std::cout << "캐릭터 생성에 성공하였습니다!" << std::endl << std::endl;
				std::cin.get();
			}
			else
			{
				system("cls");
				std::cout << "캐릭터 생성에 실패하였습니다.." << std::endl;
				std::cout << "버튼을 누르면 로비로 돌아갑니다.." << std::endl;
					
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