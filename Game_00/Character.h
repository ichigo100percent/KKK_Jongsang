#pragma once
#include "std.h"


class Point
{
public:
	float m_x;
	float m_y;
};

struct Stat
{
	float m_fHealth = 10;
	float m_fMana = 10;
	float m_fAttackPower = 10;
	float m_fDefensivePower = 10;

	friend std::ostream& operator<<(std::ostream& os, const Stat& t)
	{
		os << " HP=" << t.m_fHealth
			<< " MP=" << t.m_fMana
			<< " AP=" << t.m_fAttackPower
			<< " DP=" << t.m_fDefensivePower
			<< std::endl;

		return os;
	}
};

class Character
{
private:
	Point m_Position;
	Stat  m_Stat;
public:
	std::wstring m_csName;
public:
	virtual void	 SetPos(Point p);
	Point			 GetPos();
	virtual void     SetHealth(float p);
	float			 GetHealth();
	virtual void	 SetMana(float p);
	float			 GetMana();
	virtual void     SetAttackPower(float p);
	float			 GetAttackPower();
	virtual void	 SetDefensivePower(float p);
	float			 GetDefensivePower();

	friend std::ostream& operator<<(std::ostream& os, const Character& t);
	friend std::ostream& operator<<(std::ostream& os, const Character* t);

	bool operator==(const Character& p)
	{
		return m_csName == p.m_csName;
	}

public:
	Character();
	Character(Point p);
	Character(const Character& c);
	virtual ~Character();
};