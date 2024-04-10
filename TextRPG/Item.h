#pragma once
#include <iostream>
#include <vector>

#define MAX_SLOT 10

enum class eItemRarity
{
	None,
	Normal,
	Rare,
	Unique,
};

enum class eItemType
{
	None,
	Weapon,
	Amor,
	Consumable,
};


class Item
{
public:
	Item(eItemType _type);
	virtual ~Item();

public:
	virtual void Print();
	eItemType	GetType() { return m_eType; }
	eItemRarity	GetRarity() { return m_eRarity; }

protected:
	int			m_iId;
	int			m_iCount;
	eItemType	m_eType;
	eItemRarity	m_eRarity;
};

class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon();

	void	Print() override;
	void	SetDamage(int _value);
	int		GetDamage();

private:
	int m_iDamage;
};

class Armor : public Item
{
public:
	Armor();
	virtual ~Armor();

	void	Print() override;
	void	SetDefense(int _value);
	int		GetDefense();

private:
	int m_iDefense;
};

