#pragma once
#include "Std.h"

using namespace J::math;

namespace J
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();
		
		void SetName(const std::wstring& _name) { m_Name = _name; }
		std::wstring& GetNmae() { return m_Name; }

	private:
		std::wstring m_Name;
	};
}
