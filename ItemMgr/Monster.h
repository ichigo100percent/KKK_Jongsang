#pragma once
#include "std.h"


namespace Js
{
	class Monster
	{
	public:
		Monster(const std::string& _name, int _health, std::set<class item> _dropItem)
			: m_Name(_name)
			, m_Health(_health)
			, m_DropItems(_dropItem)
		{
		
		}

	protected:
		std::string m_Name;
		int m_Health;
		std::set<class item> m_DropItems;
	};

	class Orc : public Monster
	{
	public:
	};
}
