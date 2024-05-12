#pragma once
#include <iostream>

namespace Js
{
	using namespace std;

	enum class ePositionType
	{
		None = 0,
		사원,
		대리,
		과장,
		부장,
		이사,
	};


	class Employee
	{
	public:
		Employee(string _str, ePositionType _p)
			: m_Name(_str)
			, m_PositionType(_p)
		{
		}
		virtual ~Employee() {}

		string GetName() { return m_Name; }
		ePositionType GetPositionType() { return m_PositionType; }
		virtual int GetSalary() = 0;

		string GetPostion()
		{
			string p = {};

			switch (m_PositionType)
			{
			case Js::ePositionType::None:
				break;
			case Js::ePositionType::사원:
				p = "사원";
				break;
			case Js::ePositionType::대리:
				p = "대리";
				break;
			case Js::ePositionType::과장:
				p = "과장";
				break;
			case Js::ePositionType::부장:
				p = "부장";
				break;
			case Js::ePositionType::이사:
				p = "이사";
				break;
			default:
				break;
			}

			return p;
		}

	protected:
		string m_Name;
		ePositionType m_PositionType;
	};
}
