#include "Item.h"
#include <random>

Item::Item(eItemType _type)
	: m_iId(0)
	, m_iCount(0)
	, m_eType(eItemType::None)
	, m_eRarity(eItemRarity::None)
{
	//std::random_device rd;
	//std::mt19937 gen(rd());
	//std::uniform_int_distribution<int> dist(0, 99);

	//int randValue = dist(gen);

	int randValue = rand() % 100;

	if (randValue < 50)
		m_eRarity = eItemRarity::Normal;
	else if (randValue < 80)
		m_eRarity = eItemRarity::Rare;
	else
		m_eRarity = eItemRarity::Unique;
}

Item::~Item()
{
}

void Item::Print()
{
	switch (m_eRarity)
	{
	case eItemRarity::None:
		std::cout << "[Èñ±Íµµ] : ¾ø½À" << std::endl;
		break;
	case eItemRarity::Normal:
		std::cout << "[Èñ±Íµµ] : ÀÏ¹Ý" << std::endl;
		break;
	case eItemRarity::Rare:
		std::cout << "[Èñ±Íµµ] : ·¹¾î" << std::endl;
		break;
	case eItemRarity::Unique:
		std::cout << "[Èñ±Íµµ] : À¯´ÏÅ©" << std::endl;
		break;
	}
}

Weapon::Weapon()
	: Item(eItemType::Weapon)
	, m_iDamage(0)
{
	switch (m_eRarity)
	{
	case eItemRarity::None:
		m_iDamage = 0;
		break;
	case eItemRarity::Normal:
		m_iDamage = rand() % 5;
		break;
	case eItemRarity::Rare:
		m_iDamage = 10 + rand() % 7;
		break;
	case eItemRarity::Unique:
		m_iDamage = 20 + rand() % 10;
		break;
	}
}

Weapon::~Weapon()
{
}

void Weapon::Print()
{
	std::cout << "********************" << std::endl;
	std::cout << "[¾ÆÀÌÅÛ Å¸ÀÔ] : ¹«±â" << std::endl;
	std::cout << "°ø°Ý·Â : " << m_iDamage << std::endl;
	Item::Print();
	std::cout << "********************" << std::endl;
}

void Weapon::SetDamage(int _value)
{
	m_iDamage = _value;
}

int Weapon::GetDamage()
{
	return m_iDamage;
}

//  **********************
//           Amor	 
//  **********************

Armor::Armor()
	: Item(eItemType::Amor)
	, m_iDefense(0)
{
	switch (m_eRarity)
	{
	case eItemRarity::None:
		m_iDefense = 0;
		break;
	case eItemRarity::Normal:
		m_iDefense = rand() % 5;
		break;
	case eItemRarity::Rare:
		m_iDefense = 10 + rand() % 7;
		break;
	case eItemRarity::Unique:
		m_iDefense = 20 + rand() % 10;
		break;
	}
}

Armor::~Armor()
{
}

void Armor::Print()
{
	std::cout << "********************" << std::endl;
	std::cout << "[¾ÆÀÌÅÛ Å¸ÀÔ] : ¹æÆÐ" << std::endl;
	std::cout << "°ø°Ý·Â : " << m_iDefense << std::endl;
	Item::Print();
	std::cout << "********************" << std::endl;
}

void Armor::SetDefense(int _value)
{
	m_iDefense = _value;
}

int Armor::GetDefense()
{
	return m_iDefense;
}
