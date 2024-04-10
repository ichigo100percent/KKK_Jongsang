#pragma once
#include <vector>
#include <iostream>
#include <memory>

class Item;

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();
	
	bool AddItem(std::unique_ptr<Item> _item);
	void RemoveItem(const Item* _item);
	void Clear();

	static Inventory* Getinstance();

private:
	int findEmptySlot();
	int findItemSlot(const Item* _item);

private:
	std::vector<std::unique_ptr<Item>> m_Items;
	static Inventory* s_Instance;
	
};

