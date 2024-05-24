#pragma once
#include "std.h"

namespace Js
{

	class Item
	{
	public:
		Item(const std::string& _name) : m_Name(_name) {}

		std::string GetName() { return m_Name; }

	protected:
		std::string m_Name;
	};

	class EquipMent : public Item
	{
	public:
		EquipMent(const std::string& _name, int _power = 0, eRarity _rare = eRarity::None)
			: Item(_name)
			, m_OffensePower(_power)
			, m_eRare(_rare)
		{

		}


	private:
		int m_OffensePower;
		eRarity m_eRare;
	};
}
