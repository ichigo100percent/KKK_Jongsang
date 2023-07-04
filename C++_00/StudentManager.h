#pragma once

#include "Linkedlist.h"
#include "student.h"
#include "exception.h"


class StudentManager
{

public:

	student* newStudent()
	{
		student* newStudent = new student;

		std::string m_name;

		int _kor, _mat, _eng;

		std::cin.ignore();

		std::cout << "�̸��� �Է��Ͻʽÿ�. " << std::endl;
		std::getline(std::cin, m_name);

		std::cout << "���� ������ �Է��Ͻÿ�. " << std::endl;
		_mat = getIntegerInput();
		//std::cin >> _mat;

		std::cout << "���� ������ �Է��Ͻÿ�. " << std::endl;
		_kor= getIntegerInput();
		//std::cin >> _kor;
		
		std::cout << "���� ������ �Է��Ͻÿ�. " << std::endl;
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
		m_size++;
	}
	void print_list()
	{
		m_List.Print_list();
	}

	void find(const std::string& _name)
	{
		std::string name;

		std::cout << "�̸��� �Է��Ͻÿ�: ";

		std::getline(std::cin, name);

		m_List.find_Node(name);
	}

	void delet(const std::string& _name)
	{
		std::string name;

		std::cout << "�̸��� �Է��Ͻÿ�: ";

		std::getline(std::cin, name);

		m_List.delete_node(name);

		m_size--;
	}

	void sort()
	{
		m_List.bubble_sort();
	}

	void SaveFile(const char* filename)const
	{
		FileIO fileIO;
		FILE* fpWrite = fileIO.CreateFile(filename);
		if (fpWrite != NULL)
		{
			for (Node<student>* pNode = m_List.head;
				pNode != NULL;
				pNode = pNode->next)
			{
				pNode->data->save(fpWrite);
			}
			fileIO.CloseFile();
		}
	};

	void LoadFile(const char* filename)
	{
		m_List.all_delete();

		FileIO fileIO;
		FILE* fpRead = fileIO.CreateFile(filename, "r");
		if (fpRead != NULL)
		{
			while (1)
			{
				if (feof(fpRead))
				{
					break;
				}
				//Node<student>* pNewNode = m_LinkedList.NewNode();
				//// todo
				//pNewNode->m_pData = new TStudent;
				//_ASSERT(pNewNode->m_pData);
				//pNewNode->m_pData->Read(fpRead);
				//pNewNode->m_pData->Compute();
				//m_LinkedList.Push_Front(pNewNode);
			}
			fileIO.CloseFile();
		}
	}

	void run()
	{
		std::string nameValue;
		int choice;
		while (1)
		{
			std::system("cls");

			std::cout << "1. �л� ����" << std::endl;
			std::cout << "2. �л� ���" << std::endl;
			std::cout << "3. �л� ã��" << std::endl;
			std::cout << "4. �л� ����" << std::endl;
			std::cout << "5. ��ü ����" << std::endl;
			std::cout << "6. �л� ����" << std::endl;
			//std::cout << "5. �л� ����" << std::endl;
			std::cout << "0. ����" << std::endl;
			std::cout << "�޴� ���� : [ ]\b\b";
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
			case 5:
				m_List.all_delete();
				break;
			case 6:
				SaveFile("T1");
				break;
			case 0:
				exit(0);
			}

			std::system("pause"); //�Ͻô��
		}
	}


public:

	List<student> m_List;
	int m_size = 0;
};