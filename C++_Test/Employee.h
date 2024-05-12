#pragma once
#include <iostream>

namespace Js
{
	using namespace std;

	enum class ePositionType
	{
		None = 0,
		���,
		�븮,
		����,
		����,
		�̻�,
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
			case Js::ePositionType::���:
				p = "���";
				break;
			case Js::ePositionType::�븮:
				p = "�븮";
				break;
			case Js::ePositionType::����:
				p = "����";
				break;
			case Js::ePositionType::����:
				p = "����";
				break;
			case Js::ePositionType::�̻�:
				p = "�̻�";
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
