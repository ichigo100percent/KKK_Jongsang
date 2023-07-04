#include "student.h"

void student::setName(const std::string& _name)
{
	name = _name;
}

void student::setSubject(int _kor, int _mat, int _eng)
{
	subj.set_subject(_kor, _mat, _eng);
	m_Total = _kor + _mat + _eng;
	m_Average = m_Total / 3.0f;
}

void student::getsubject()
{
	std::cout << getName() << "의 점수는 " << subj.kor << ' '
		<< subj.mat << ' ' << subj.eng << "이고 총합과 평균은 " << getTotal() << " " << getAverage() << "입니다. " << std::endl;
}

std::string student::getName()
{
	return name;
}

int student::getTotal()
{
	return m_Total;
}

float student::getAverage()
{
	return m_Average;
}

void student::save(FILE* fp)
{
	fprintf(fp, "%s %d %d %d %d %f\n",
		name, iKor, iEng, iMat, m_Total, m_Average );
}

void student::read(FILE* fp)
{
	fscanf(fp, "%s %d %d %d %d %f\n",
		name, iKor, iEng, iMat, m_Total, m_Average );
}
