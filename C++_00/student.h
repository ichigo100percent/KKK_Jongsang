#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "subject.h"

#define SIZE 30

class student
{
public:
	std::string name;
	subject subj;

	int m_Total;
	float m_Average;

public:
	void setName(const std::string& _name);
	void setSubject(int _kor, int _mat, int _eng);
	
	void getsubject();
	std::string getName();
	int getTotal();
	float getAverage();
};