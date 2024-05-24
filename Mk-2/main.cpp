#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>

using namespace std;

class Item
{
public:
	Item(const string& _name)
		: Name(_name) 
		, Quantity(1)
		, ItemInfo{}
	{
	}

	virtual void PrintInfo() = 0;

	string GetName() const { return Name; }
	int GetQuantity() { return Quantity; }
	void IncreaseQuantity() { Quantity++; }

protected:
	string Name;
	string ItemInfo;
	int Quantity;
};

class EuipmentItem : public Item
{
public:
	EuipmentItem(const string& _name, const int& _attackPower, const string& _itemInfo)
		: Item(_name)
		, AttackPower(_attackPower)
	{
		ItemInfo = _itemInfo;
	}

	virtual void PrintInfo() override
	{

	}

private:
	int AttackPower;
	int DefensePower;
	int EuipmentLevel;

};

class ConsumptionItem : public Item
{
public:
	ConsumptionItem(const string& _name)
		: Item(_name)
	{
	}

	virtual void PrintInfo() override
	{

	}

private:

};

class Monster
{
public:
	Monster(const string& _name, const vector<Item*>& _items)
		: Name(_name)
		, dropItems(_items)
	{
	}
	
	Item* DorpItem()
	{
		auto seed = chrono::system_clock::now().time_since_epoch().count();
		mt19937 rng(seed);
		uniform_int_distribution<int> dist(0, dropItems.size() - 1);

		return dropItems[dist(rng)];
	}

	string GetName() const { return Name; }

protected:
	string Name;
	vector<Item*> dropItems;
};

class Knight
{
public:
	Knight(const string& _name)
		: Name(_name)
		, Inventory{}
	{

	}

	void Attack(shared_ptr<Monster> _target)
	{
		target = _target;
		
		if (auto t = target.lock())
		{
			auto item = t->DorpItem();
			Inventory.emplace_back(item);
			cout << t->GetName() << "를 쓰러뜨려 " << item->GetName() << "를 획득했습니다! " << endl;

			return;
		}

		cout << "대상 몬스터가 없습니다. " << endl;
	}

	void AddInventory(Item* _item)
	{
		if (_item != nullptr)
		{
			Inventory.push_back(_item);
			cout << "아이템 추가 성공! " << '\n';
			return;
		}

		cout << "아이템 추가에 실패하였습니다! " << '\n';
	}

	void UseItem(const string& Name)
	{
		auto iter = find_if(Inventory.begin(), Inventory.end(),
			[&](Item* item)
			{
				return item->GetName() == Name;
			});

		if (iter != Inventory.end())
		{
			cout << (*iter)->GetName() << "을 사용하였습니다! " << '\n';
			Inventory.erase(iter);
			return;
		}

		cout << "해당 아이템이 없습니다! " << '\n';
	}

	void ShowInventory()
	{
		cout << "현재 가지고 있는 아이템 : ";
		for (const auto& item : Inventory)
		{
			cout << item->GetName() << " ";
		}
		cout << '\n';
	}

private:
	string Name;
	vector<Item*> Inventory;
	weak_ptr<Monster> target;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Item* HPPotion = new Item("HP포션");
	Item* MPPotion = new Item("MP포션");
	Item* Sword = new Item("소드");
	Item* Scroll = new Item("주문서");

	auto knight = make_unique<Knight>("기사");
	//auto orc1 = new Monster("오크1", { HPPotion, MPPotion });
	{
		auto orc2 = make_shared<Monster>("오크2", vector<Item*>{ HPPotion });
		knight->Attack(orc2);
	}

	knight->UseItem("HP포션");
	knight->AddInventory(Sword);
	knight->AddInventory(Scroll);
	knight->AddInventory(MPPotion);
	knight->ShowInventory();
	knight->UseItem("주문서");
	knight->ShowInventory();

	if (Scroll == nullptr)
	{
		cout << "nullptr" << '\n';
	}

	return 0;
}