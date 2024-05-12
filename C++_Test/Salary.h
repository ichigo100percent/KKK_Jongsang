#pragma once
#include "Employee.h"

namespace Js
{
	class SalaryHourly : public Employee
	{
	public:
		SalaryHourly(string _n, ePositionType _p, int _workTime)
			: Employee(_n, _p)
			, m_WorkTime(_workTime)
		{

		}

		virtual int GetSalary() override
		{
			int SalayHour = m_WorkTime * 10000;

			switch (m_PositionType)
			{
			case Js::ePositionType::None:
				break;
			case Js::ePositionType::사원:
				SalayHour *= 1;
				break;
			case Js::ePositionType::대리:
				SalayHour *= 2;
				break;
			case Js::ePositionType::과장:
				SalayHour *= 4;
				break;
			case Js::ePositionType::부장:
				SalayHour *= 6;
				break;
			case Js::ePositionType::이사:
				SalayHour *= 8;
				break;
			default:
				break;
			}

			return SalayHour;
		}

	private:
		int m_WorkTime;
	};

	class SalaryMonthly : public Employee
	{
	public:
		SalaryMonthly(string _n, ePositionType _p, int _year)
			: Employee(_n, _p)
			, serviceyears(_year)
		{

		}

		virtual int GetSalary() override
		{
			int salary = 2000000;
			int position = 200000;
			int year = serviceyears * 50000;

			switch (m_PositionType)
			{
			case Js::ePositionType::None:
				break;
			case Js::ePositionType::사원:
				salary += position + year;
				break;
			case Js::ePositionType::대리:
				salary += (position * 2) + year;
				break;
			case Js::ePositionType::과장:
				salary += (position * 3) + year;
				break;
			case Js::ePositionType::부장:
				salary += (position * 4) + year;
				break;
			case Js::ePositionType::이사:
				salary += (position * 5) + year;
				break;
			default:
				break;
			}

			return salary;
		}

	private:
		int serviceyears;
	};

	class SalaryAnnualy : public Employee
	{
	public:
		SalaryAnnualy(string _n, ePositionType _p, int _g)
			: Employee(_n, _p)
			, greade(_g)
		{

		}
		virtual int GetSalary() override
		{
			int salary = 20000000;
			int position = 10000000;
			int capability = 5000000 * greade;

			switch (m_PositionType)
			{
			case Js::ePositionType::None:
				break;
			case Js::ePositionType::사원:
				salary += position + capability;
				break;
			case Js::ePositionType::대리:
				salary += (position * 2) + capability;
				break;
			case Js::ePositionType::과장:
				salary += (position * 3) + capability;
				break;
			case Js::ePositionType::부장:
				salary += (position * 4) + capability;
				break;
			case Js::ePositionType::이사:
				salary += (position * 5) + capability;
				break;
			default:
				break;
			}

			return salary / 12;
		}

	private:
		int greade;
	};
}
