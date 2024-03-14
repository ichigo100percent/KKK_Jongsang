#include <iostream>
#include <time.h>

using namespace std;

#define NAME_SIZE 25

enum class Menu
{
	Map = 1,
	Shop,
	Inventory,
	Exit,
};

enum MapType
{
	Easy = 1,
	Nomal,
	Hard,
	Exit,
};

enum class Job
{
	Warrior,
	Magician,
	Archer,
};

struct Player
{
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];
	Job		eJob;
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHp;
	int		iHpMax;
	int		iMp;
	int		iMpMax;
	int		iExp;
	int		iLevel;
};


int main()
{
	Menu eMenu;

	while (true)
	{
		system("cls");
		cout << "1. ��" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����" << endl;
		int iMenu;

		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == static_cast<int>(Menu::Exit))
			break;
		
		switch (eMenu = static_cast<Menu>(iMenu))
		{
		case Menu::Map:
			while (true)
			{
				system("cls");
				cout << "1. ����" << endl;
				cout << "2. ����" << endl;
				cout << "3. �����" << endl;
				cout << "4. �ڷ� ����" << endl;
				cout << "���� �����ϼ���. : ";

				cin >> iMenu;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMenu == MapType::Exit)
					break;
			}
		case Menu::Shop:
				break;

		case Menu::Inventory:
			break;
		default:
			break;
		}
	}
}