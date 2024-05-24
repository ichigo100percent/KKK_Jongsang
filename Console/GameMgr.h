#pragma once
#include "std.h"
#include "Player.h"
#include "FileIO.h"

namespace Js
{
	class GameMgr
	{
	public:
		GameMgr();

		void Init();
		void Update();

	private:
		void enterRobby();
		void createPlayer();

	private:
		void printRobby();

	private:

		void saveData(const char* _fileName)
		{
			FileIO fileOpen;
			FILE* fp = fileOpen.CreateFile(_fileName, "wb");

			if (fp != nullptr)
			{
				m_Player->save(fp);
			}

			fileOpen.CloseFile();
		}
		void loadData(const char* _fileName)
		{

		}

	private:
		std::shared_ptr<class Knight> m_Player;
	};
}
