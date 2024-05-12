#pragma once
#include "std.h"

namespace Js
{
	class Student
	{
	public:
		Student();
		Student(string _name, string _address, int _kor, int _eng, int _math);
		virtual ~Student();

		void Set(string _name, string _address, int _kor, int _eng, int _math);
		string GetName() { return m_Name; }
		void print();

		void save(FILE* _fp);
		void load(FILE* _fp);

	private:
		string m_Name;
		string m_Address;
		int    m_Kor;
		int    m_Eng;
		int    m_Math;
		int    m_Total;
		float  m_Average;
	};
}
