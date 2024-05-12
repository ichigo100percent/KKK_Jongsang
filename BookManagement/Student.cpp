#include "Student.h"


namespace Js
{
	Student::Student()
		: m_Name {}
		, m_Address {}
		, m_Kor(0)
		, m_Eng(0)
		, m_Math(0)
		, m_Total(0)
		, m_Average(0)
	{
	}
	Student::Student(string _name, string _address, int _kor, int _eng, int _math)
		: m_Name(_name)
		, m_Address(_address)
		, m_Kor(_kor)
		, m_Eng(_eng)
		, m_Math(_math)
	{
		m_Total = m_Kor + m_Eng + m_Kor;
		m_Average = m_Total / 3;
	}
	Student::~Student()
	{
	}
	void Student::Set(string _name, string _address, int _kor, int _eng, int _math)
	{
		m_Name = _name;
		m_Address = _address;
		m_Kor = _kor;
		m_Eng = _eng;
		m_Math = _math;

		m_Total = m_Kor + m_Eng + m_Kor;
		m_Average = m_Total / 3;
	}

	void Student::print()
	{
		cout << "학생 이름 : " << m_Name << endl;
		cout << "학생 주소 : " << m_Address << endl;
		cout << "국어 점수 : " << m_Kor << endl;
		cout << "영어 점수 : " << m_Eng << endl;
		cout << "수학 점수 : " << m_Math << endl;
		cout << "합계 : " << m_Total << endl;
		cout << "평균 : " << m_Average << endl << endl;
	}

	void Student::save(FILE* _fp)
	{
		fwrite(this, sizeof(Student), 1, _fp);
	}
	void Student::load(FILE* _fp)
	{
		fread(this, sizeof(Student), 1, _fp);
	}
}