#include "Player.h"

namespace Js
{
	void Player::save(FILE* _file) const
	{
		size_t nameLength = m_Name.size();
		fwrite(&nameLength, sizeof(nameLength), 1, _file);
		fwrite(m_Name.c_str(), sizeof(char), nameLength, _file);

	
		fwrite(&m_HP, sizeof(m_HP), 1, _file);
		fwrite(&m_MP, sizeof(m_MP), 1, _file);
		fwrite(&m_Level, sizeof(m_Level), 1, _file);
		fwrite(&m_Exp, sizeof(m_Exp), 1, _file);
		fwrite(&m_Offensive_Power, sizeof(m_Offensive_Power), 1, _file);
		fwrite(&m_Defensive_Power, sizeof(m_Defensive_Power), 1, _file);
	}

	void Player::load(FILE* _file)
	{
		size_t nameLength;
		fread(&nameLength, sizeof(nameLength), 1, _file);
		m_Name.resize(nameLength);
		fread(&m_Name[0], sizeof(char), nameLength, _file);

		fread(&m_HP, sizeof(m_HP), 1, _file);
		fread(&m_MP, sizeof(m_MP), 1, _file);
		fread(&m_Level, sizeof(m_Level), 1, _file);
		fread(&m_Exp, sizeof(m_Exp), 1, _file);
		fread(&m_Offensive_Power, sizeof(m_Offensive_Power), 1, _file);
		fread(&m_Defensive_Power, sizeof(m_Defensive_Power), 1, _file);
	}
	

	Knight::Knight(const std::string& _name)
		: Player(_name)
	{
		m_HP = 100; m_MP = 100; m_Offensive_Power = 10; m_Defensive_Power = 5;
	}

	void Knight::PrintSTATE()
	{
		std::cout << "***************************************************************" << std::endl << std::endl;
		std::cout << "                          플레이어 정보                        " << std::endl << std::endl;
		std::cout << "***************************************************************" << std::endl << std::endl;

		std::cout << " 직업    : " << "기사 " << std::endl;
		std::cout << " 이름    : " << m_Name << std::endl;
		std::cout << " Lv      : " << m_Level << std::endl;
		std::cout << " 경험치  : " << m_Exp << std::endl;
		std::cout << " HP      : " << m_HP << std::endl;
		std::cout << " MP      : " << m_MP << std::endl;
		std::cout << " 공격력  : " << m_Offensive_Power << std::endl;
		std::cout << " 방어력  : " << m_Defensive_Power << std::endl << std::endl;

	}

	void Knight::save(FILE* _file) const
	{
		Player::save(_file);
	}
}