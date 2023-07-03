#pragma once

#include "Linkedlist.h"
#include "student.h"
#include "test.h"


class StudentManager
{

public:

	student* newStudent()
	{
		student* newStudent = new student;

		std::string m_name;

		int _kor, _mat, _eng;

		std::cin.ignore();

		std::cout << "이름을 입력하십시오. " << std::endl;
		std::getline(std::cin, m_name);

		std::cout << "수학 점수를 입력하시오. " << std::endl;
		_mat = getIntegerInput();
		//std::cin >> _mat;

		std::cout << "국어 점수를 입력하시오. " << std::endl;
		_kor= getIntegerInput();
		//std::cin >> _kor;
		
		std::cout << "영어 점수를 입력하시오. " << std::endl;
		_eng = getIntegerInput();
		//std::cin >> _eng;
		
		newStudent->setName(m_name);
		newStudent->setSubject(_kor, _mat, _eng);

		return newStudent;

	}

	void add()
	{
		student* st = newStudent();
		m_List.push_back(st);
	}
	void print_list()
	{
		m_List.Print_list();
	}

	void find(const std::string& _name)
	{
		std::string name;

		std::cout << "이름을 입력하시오: ";

		std::getline(std::cin, name);

		m_List.find_Node(name);
	}

	void delet(const std::string& _name)
	{
		std::string name;

		std::cout << "이름을 입력하시오: ";

		std::getline(std::cin, name);

		m_List.delete_node(name);
	}

	void run()
	{
		std::string nameValue;
		int choice;
		while (1)
		{
			system("cls");

			std::cout << "1. 학생 삽입" << std::endl;
			std::cout << "2. 학생 출력" << std::endl;
			std::cout << "3. 학생 찾기" << std::endl;
			std::cout << "4. 학생 삭제" << std::endl;
			std::cout << "5. 종료" << std::endl;
			std::cout << "메뉴 선택 : [ ]\b\b";
			std::cin >> choice;
			

			switch (choice)
			{
			case 1:
				add();
				break;
			case 2:
				print_list();
				break;
			case 3:		
				std::getline(std::cin, nameValue);
				find(nameValue);
				break;
			case 4:
				std::getline(std::cin, nameValue);
				delet(nameValue);
				break;
			case 0:
				//unInitList();
				exit(0);
			}

			system("pause"); //일시대기
		}
	}


public:

	List<student> m_List;
};