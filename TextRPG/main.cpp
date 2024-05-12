#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include "Item.h"
#include "Inventory.h"

using namespace std;

enum class PlayerType
{
	None = 0,
	Knight = 1,
	Archer,
	Magician,
};
enum class MonsterType
{
	None = 0,
	Slime,
	Troll,
	Demon,
};
class Player
{
public:
	Player()
		: m_Type(PlayerType::None)
		, hp(0)
		, damage(0)
		, defense(0)
	{

	}
	~Player() {}

	void SetType(PlayerType _type)
	{
		m_Type = _type;

		switch (m_Type)
		{
		case PlayerType::Knight:
			hp = 100;
			damage = 10;
			defense = 10;
			break;
		case PlayerType::Archer:
			hp = 70;
			damage = 12;
			defense = 5;
			break;
		case PlayerType::Magician:
			hp = 50;
			damage = 15;
			defense = 2;
			break;
		}
	}

public:
	PlayerType m_Type;
	int hp;
	int damage;
	int defense;
};
class Monster
{
public:
	Monster()
		: m_Type(MonsterType::None)
		, hp(0)
		, damage(0)
		, defense(0)
		, currentHp(0)
	{
	}
	~Monster() {}

	void SetType(MonsterType _type)
	{
		m_Type = _type;

		switch (m_Type)
		{
		case MonsterType::Slime:
			hp = 5;
			damage = 10;
			defense = 0;
			currentHp = hp;
			break;
		case MonsterType::Troll:
			hp = 15;
			damage = 20;
			defense = 5;
			currentHp = hp;
			break;
		case MonsterType::Demon:
			hp = 50;
			damage = 50;
			defense = 10;
			currentHp = hp;
			break;
		}
	}
	MonsterType GetType() { return m_Type; }
	int GetHp() { return hp; }
	int GetDamage() { return damage; }
	int GetDefense() { return defense; }

public:
	int currentHp;

private:
	MonsterType m_Type;
	int hp;
	int damage;
	int defense;
};
void EnterLobby();
void CreatePlayer();
void EnterField();
void CrateRandomMonster();
void MeetMonster();
void BattleMonster();
void BattleEnd();
Player* pl = new Player();
Monster* monster = new Monster();
std::unique_ptr<Item> DropItem()
{
	if (rand() % 2 == 1)
	{
		return std::make_unique<Weapon>();
	}
	else
	{
		return std::make_unique<Armor>();
	}
}

int main()
{
	srand(time(0));
	for (int i = 0; i < 10; ++i)
	{
		std::unique_ptr<Item> item = DropItem();
		item->Print();;

		if (Inventory::Getinstance()->AddItem(std::move(item)))
		{
			cout<<"Added item to Inven"<<endl;
		}
		else
		{
			cout << "Failed item to Inven" << endl;
		}
	}
	srand(time(0));

	EnterLobby();


	return 0;
}

void EnterLobby()
{
	while (1)
	{
		system("cls");
		cout << "-----------------------" << endl;
		cout << "������ ȯ���մϴ�! " << endl;
		cout << "-----------------------" << endl;
		cout << "�޴��� �������ּ���." << endl;
		cout << "1. �÷��̾� ���� 2. ������" << endl;
		cout << "< ";

		int input;

		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		switch (input)
		{
		case 1:
			cout << "�÷��̾� ���� ��..." << endl;
			CreatePlayer();
			break;
		case 2:
			return;
			//exit(1);
		default:
			break;
		}
	}
}
void CreatePlayer()
{
	while (1)
	{
		system("cls");
		cout << "-----------------------" << endl;
		cout << "������ �������ּ���! " << endl;
		cout << "-----------------------" << endl;
		cout << "1. ���� 2. �ü� 3. ����" << endl;
		cout << "< ";
		int input;
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		switch (static_cast<PlayerType>(input))
		{
		case PlayerType::Knight:
			pl->SetType(static_cast<PlayerType>(input));
			cout << "���簡 �����Ǿ����ϴ�! " << endl;
			EnterField();
			return;
		case PlayerType::Archer:
			pl->SetType(static_cast<PlayerType>(input));
			cout << "�ü��� �����Ǿ����ϴ�! " << endl;
			EnterField();
			return;
		case PlayerType::Magician:
			pl->SetType(static_cast<PlayerType>(input));
			cout << "���簡 �����Ǿ����ϴ�! " << endl;
			EnterField();
			return;
		default:
			break;
		}
	}
}
void EnterField()
{
	while (1)
	{
		system("cls");
		cout << "-----------------------" << endl;
		cout << "�ʵ�� �����Ͻðڽ��ϱ�? " << endl;
		cout << "-----------------------" << endl;
		cout << "1. �ʵ�����  2. �κ�� ���ư���" << endl;
		cout << "< ";

		int input;
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		switch (input)
		{
		case 1:
			CrateRandomMonster();
			MeetMonster();
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}
void CrateRandomMonster()
{
	system("cls");

	int randomNumber = 1 + (rand() % 3);

	monster->SetType(static_cast<MonsterType>(randomNumber));

	switch (monster->GetType())
	{
	case MonsterType::Slime:
		cout << "�������� ��Ÿ�����ϴ�! " << endl;
		cout << "-----------------------" << endl;
		cout << "�������� ü���� " << monster->GetHp() << "�̰� ���ݷ��� "
			<< monster->GetDamage() << "�̸� " << "������ "
			<< monster->GetDefense() << "�Դϴ�. " << endl;
		break;
	case MonsterType::Troll:
		cout << "Ʈ���� ��Ÿ�����ϴ�! " << endl;
		cout << "-----------------------" << endl;
		cout << "Ʈ���� ü���� " << monster->GetHp() << "�̰� ���ݷ��� "
			<< monster->GetDamage() << "�̸� " << "������ "
			<< monster->GetDefense() << "�Դϴ�. " << endl;
		break;
	case MonsterType::Demon:
		cout << "������ ��Ÿ�����ϴ�! " << endl;
		cout << "-----------------------" << endl;
		cout << "������ ü���� " << monster->GetHp() << "�̰� ���ݷ��� "
			<< monster->GetDamage() << "�̸� " << "������ "
			<< monster->GetDefense() << "�Դϴ�. " << endl;
		break;
	default:
		break;
	}
}
void MeetMonster()
{
	cout << "1. �ο��.    2. ��������." << endl;
	cout << "< ";
	int input;
	cin >> input;

	switch (input)
	{
	case 1:
		BattleMonster();
		break;

	case 2:
		break;

	default:
		break;
	}
}
void BattleMonster()
{
	while (1)
	{
		int damege = pl->damage - monster->GetDefense();
		if (damege < 0)
			damege = 0;

		monster->currentHp -= damege;

		if (monster->currentHp < 0)
			monster->currentHp = 0;

		cout << "������ ���� hp: " << monster->currentHp << endl;

		if (monster->currentHp == 0)
		{
			cout << "���͸� óġ�߽��ϴ�! " << endl;
			BattleEnd();
			return;
		}

		damege = monster->GetDamage() - pl->defense;

		pl->hp -= damege;

		if (pl->hp < 0)
			pl->hp = 0;

		cout << "�÷��̾��� ���� hp: " << pl->hp << endl;

		if (pl->hp == 0)
		{
			cout << "�÷��̾ ��������ϴ�." << endl;
			cout << "--------------------------" << endl;
			cout << "---------GAME OVER-------- " << endl;
			cout << "--------------------------" << endl;
			exit(1);
		}
	}
}
void BattleEnd()
{
	system("pause");
}