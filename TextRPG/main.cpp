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
		cout << "입장을 환영합니다! " << endl;
		cout << "-----------------------" << endl;
		cout << "메뉴를 선택해주세요." << endl;
		cout << "1. 플레이어 생성 2. 나가기" << endl;
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
			cout << "플레이어 생성 중..." << endl;
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
		cout << "직업을 선택해주세요! " << endl;
		cout << "-----------------------" << endl;
		cout << "1. 전사 2. 궁수 3. 법사" << endl;
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
			cout << "전사가 생성되었습니다! " << endl;
			EnterField();
			return;
		case PlayerType::Archer:
			pl->SetType(static_cast<PlayerType>(input));
			cout << "궁수가 생성되었습니다! " << endl;
			EnterField();
			return;
		case PlayerType::Magician:
			pl->SetType(static_cast<PlayerType>(input));
			cout << "법사가 생성되었습니다! " << endl;
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
		cout << "필드로 입장하시겠습니까? " << endl;
		cout << "-----------------------" << endl;
		cout << "1. 필드입장  2. 로비로 돌아가기" << endl;
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
		cout << "슬라임이 나타났습니다! " << endl;
		cout << "-----------------------" << endl;
		cout << "슬라임의 체력은 " << monster->GetHp() << "이고 공격력은 "
			<< monster->GetDamage() << "이며 " << "방어력은 "
			<< monster->GetDefense() << "입니다. " << endl;
		break;
	case MonsterType::Troll:
		cout << "트롤이 나타났습니다! " << endl;
		cout << "-----------------------" << endl;
		cout << "트롤의 체력은 " << monster->GetHp() << "이고 공격력은 "
			<< monster->GetDamage() << "이며 " << "방어력은 "
			<< monster->GetDefense() << "입니다. " << endl;
		break;
	case MonsterType::Demon:
		cout << "데몬이 나타났습니다! " << endl;
		cout << "-----------------------" << endl;
		cout << "데몬의 체력은 " << monster->GetHp() << "이고 공격력은 "
			<< monster->GetDamage() << "이며 " << "방어력은 "
			<< monster->GetDefense() << "입니다. " << endl;
		break;
	default:
		break;
	}
}
void MeetMonster()
{
	cout << "1. 싸운다.    2. 도망간다." << endl;
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

		cout << "몬스터의 남은 hp: " << monster->currentHp << endl;

		if (monster->currentHp == 0)
		{
			cout << "몬스터를 처치했습니다! " << endl;
			BattleEnd();
			return;
		}

		damege = monster->GetDamage() - pl->defense;

		pl->hp -= damege;

		if (pl->hp < 0)
			pl->hp = 0;

		cout << "플레이어의 남은 hp: " << pl->hp << endl;

		if (pl->hp == 0)
		{
			cout << "플레이어가 사망헀습니다." << endl;
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