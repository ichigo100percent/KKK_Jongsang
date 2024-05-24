#pragma once
#include "std.h"

namespace Js
{
	class Player
	{
	public:
		Player(const std::string& _name)
			: m_Name(_name), m_HP(0), m_MP(0), m_Level(1), m_Exp(0), m_Offensive_Power(0), m_Defensive_Power(0)
		{
		}

		virtual void PrintSTATE() = 0;
		virtual void save(FILE* _file) const;
		virtual void load(FILE* _file);

	protected:
		std::string m_Name;
		int m_HP;
		int m_MP;
		int m_Level;
		int m_Exp;
		int m_Offensive_Power;
		int m_Defensive_Power;
	
	};

	class Knight : public Player
	{
	public:
		Knight(const std::string& _name);

		virtual void PrintSTATE() override;
		virtual void save(FILE* _file) const override;
		virtual void load(FILE* _file) override;

		void KnightAttack();
	private:
	};

	class Archor : public Player
	{
	public:
		Archor(const std::string& _name);

		virtual void PrintSTATE() override;
		virtual void save(FILE* _file) const override;
		virtual void load(FILE* _file) override;

		void ArchorAttack();

	private:
	};

}
