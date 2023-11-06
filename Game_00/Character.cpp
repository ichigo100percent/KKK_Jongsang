#include "Character.h"

std::ostream& operator<<(std::ostream& os, const Character& t)
{
	os << "PosX= " << t.m_Position.m_x
		<< "PosY= " << t.m_Position.m_y;
	os << t.m_Stat;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Character* t)
{
	os << "PosX= " << t->m_Position.m_x
		<< "PosY= " << t->m_Position.m_y;
	os << t->m_Stat;
	return os;
}

void Character::SetPos(Point p)
{
	m_Position = p;
}

Point Character::GetPos()
{
	return m_Position;
}

void Character::SetHealth(float p)
{
	m_Stat.m_fHealth = p;
}

float Character::GetHealth()
{
	return m_Stat.m_fHealth;
}

void Character::SetMana(float p)
{
	m_Stat.m_fMana = p;
}

float Character::GetMana()
{
	return m_Stat.m_fMana;
}

void Character::SetAttackPower(float p)
{
	m_Stat.m_fAttackPower = p;
}

float Character::GetAttackPower()
{
	return m_Stat.m_fAttackPower;
}

void Character::SetDefensivePower(float p)
{
	m_Stat.m_fDefensivePower = p;
}

float Character::GetDefensivePower()
{
	return m_Stat.m_fDefensivePower;
}

Character::Character()
{
	m_Position.m_x = 0;
	m_Position.m_y = 0;
	std::cout << "�θ� ������ ȣ��" << std::endl;
}

Character::Character(Point p)
{
	m_Position = p;
	std::cout << "�θ� ������ ȣ��" << std::endl;
}

Character::Character(const Character& c)
{
	m_csName = L"PC";
	m_Position = c.m_Position;
	m_Stat = c.m_Stat;
	std::cout << "���� ������ ȣ��" << std::endl;
}

Character::~Character()
{
	std::cout << "�θ� ������ ȣ��" << std::endl;
}
