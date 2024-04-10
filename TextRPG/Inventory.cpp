#include "Inventory.h"
#include "Item.h"

Inventory* Inventory::s_Instance = nullptr;

Inventory::Inventory()
{
	m_Items.resize(MAX_SLOT);

	for (size_t i = 0; i < MAX_SLOT; i++)
	{
		m_Items[i] = nullptr;
	}
}

Inventory::~Inventory()
{
}

bool Inventory::AddItem(std::unique_ptr<Item> _item)
{
	if (_item == nullptr)
		return false;

	int emptySlot = findEmptySlot();
	if (emptySlot < 0)
		return false;

	m_Items[emptySlot] = std::move(_item);
	return true;
}


void Inventory::RemoveItem(const Item* _item)
{
	auto it = std::find_if(m_Items.begin(), m_Items.end(),
		[&](std::unique_ptr<Item>& _data)
		{
			return _data.get() == _item;
		}
	);

	if (it == m_Items.end())
		return;

	*it = nullptr;
}

void Inventory::Clear()
{
	for (int i = 0; i < MAX_SLOT; i++)
	{
		m_Items[i].reset();
	}
}

Inventory* Inventory::Getinstance()
{
	if (s_Instance == nullptr)
		s_Instance = new Inventory();

	return s_Instance;
}

int Inventory::findEmptySlot()
{
	for (size_t i = 0; i < MAX_SLOT; i++)
	{
		if (!m_Items[i])
			return i;
	}

	return -1;
}

int Inventory::findItemSlot(const Item* _item)
{
	return 0;
}
