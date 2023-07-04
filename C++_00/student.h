#pragma once
#include <iostream>
#include <conio.h>
#include <string>

#include "subject.h"
#include "fileIO.h"

#define SIZE 30

class student
{
public:
	std::string name;
	subject subj;

	int iKor = subj.get_kor();
	int iEng = subj.get_eng();
	int iMat = subj.get_mat();
	int m_Total;
	float m_Average;

public:
	void setName(const std::string& _name);
	void setSubject(int _kor, int _mat, int _eng);
	
	void getsubject();
	std::string getName();
	int getTotal();
	float getAverage();
	void save(FILE* fp);
	void read(FILE* fp);
	
};