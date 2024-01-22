#pragma once
#include "Std.h"

namespace J
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const wstring& _name) { m_Name = _name; }
		wstring& GetNmae() { return m_Name; }

	private:
		wstring m_Name;
	};
}
