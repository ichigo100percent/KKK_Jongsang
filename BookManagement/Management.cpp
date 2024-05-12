#include "Management.h"
#include "Student.h"
#include "FileIO.h"

namespace Js
{
	vector<unique_ptr<Student>> Management::m_Students = {};

	Management::Management()
	{
	}
	Management::~Management()
	{
	}
	void Management::Init()
	{
		m_Students.clear();
	}
	void Management::Update()
	{
		bool running = true;
		int menu = 0;
		string findName = {};

		while (running)
		{
			title();
			cout << "1. �л� �߰�  2. �л� ���  3. �л� ã��  4. �л� ����  5. ����  6. �ε�  9.����" << endl;
			cout << "�޴��� �������ּ���. " << endl;
			cout << ">  ";

			cin >> menu;

			if (cinCheck())
			{
				system("pause");
				continue;
			}

			if (menu == (int)eMenu::Exit)
			{
				end();
				return;
			}

			switch (static_cast<eMenu>(menu))
			{
			case Js::eMenu::Add:
				add();
				break;
			case Js::eMenu::Show:
				print();
				break;
			case Js::eMenu::Find:
				find();
				break;
			case Js::eMenu::Delete:
				remove();
				break;
			case Js::eMenu::Save:
				saveData("t1.dat");
				break;
			case Js::eMenu::Load:
				loadData("t1.dat");
				break;
			default:
				break;
			}
		}
		//system("pause");
	}
	void Management::release()
	{
		for (auto& e : m_Students)
		{
			e.reset();
			e = nullptr;
		}
	}
	void Management::saveData(const char* _fileName)
	{
		cin.ignore(1024, '\n');
		
		if (m_Students.empty())
		{
			cout << "��ϵ� �л��� �����ϴ�! " << endl;
			getchar();
			return;
		}

		FileIO fileOpen;

		FILE* fp = fileOpen.CreateFile(_fileName, "wb");
		if (fp != nullptr)
		{
			for (const auto& e : m_Students)
			{
				e->save(fp);
			}
			fileOpen.CloseFile();

			cout << "���� ���� ����! " << endl;
			getchar();
		}
		else
		{
			cout << "���� ���忡 �����߽��ϴ�. " << endl;
			getchar();
		}

	}
	void Management::loadData(const char* _fileName)
	{
		cin.ignore(1024, '\n');

		if (!m_Students.empty())
		{
			for (auto& e : m_Students)
			{
				e.reset();
				e = nullptr;
			}

			m_Students.clear();
		}

		FileIO fileOpne;
		FILE* fp = fileOpne.CreateFile(_fileName, "rb");

		if (fp == nullptr)
		{
			cout << "���� �ε尡 �����߽��ϴ�. " << endl;
			getchar();
			return;
		}

		while (1)
		{
			unique_ptr<Student> s = make_unique<Student>();
			s->load(fp);

			if (feof(fp))
			{
				//s.reset();
				//s = nullptr;
				break;
			}
			m_Students.push_back(move(s));
		}
		fileOpne.CloseFile();
		cout << "���� �ε� ����! " << endl;
		getchar();
	}
	void Management::add()
	{
		string name = {};
		string address = {};
		int kor = 0;
		int eng = 0;
		int math = 0;
		while (1)
		{
			system("cls");
			cin.ignore(1024, '\n');
			cout << "***********************************************************" << endl;
			cout << "                     �л������� �Է��ϼ���                 " << endl;
			cout << "***********************************************************" << endl << endl;
			cout << "�̸��� �Է��ϼ���." << endl;
			getline(cin, name);

			if (cinCheck())
				continue;

			cout << "�ּҸ� �Է��ϼ���. " << endl;
			getline(cin, address);
			if (cinCheck())
				continue;

			cout << "���� ������ �Է����ּ���" << endl;
			cin >> kor;
			while (cinCheck())
			{
				cin >> kor;
			}			
			cout << "���� ������ �Է����ּ���" << endl;
			cin >> eng;
			while (cinCheck())
			{
				cin >> eng;
			}
			cout << "���� ������ �Է����ּ���" << endl;
			cin >> math;
			while (cinCheck())
			{
				cin >> math;
			}
			m_Students.push_back(make_unique<Student>(name, address, kor, eng, math));

			cout << "�л� �߰� �Ϸ�! " << endl;
			system("pause");
			break;
		}
	}
	void Management::print()
	{
		system("cls");
		cin.ignore(1024, '\n');
		cout << "***********************************************************" << endl;
		cout << "                     �л����� ���                         " << endl;
		cout << "***********************************************************" << endl << endl;

		if (m_Students.empty())
		{
			cout << "��ϵ� �л��� �����ϴ�. " << endl;
			getchar();
			return;
		}

		for (auto& e : m_Students)
		{
			e->print();
		}

		getchar();
	}
	void Management::find()
	{
		system("cls");
		cin.ignore(1024, '\n');
		cout << "***********************************************************" << endl;
		cout << "                     �л����� ã��                         " << endl;
		cout << "***********************************************************" << endl << endl;
		
		string findName = {};

		cout << "�л��̸��� �Է����ּ���. " << endl;
		getline(cin, findName);

		auto it = find_if(m_Students.begin(), m_Students.end(),
			[&](const unique_ptr<Student>& ptr)
			{
				return ptr->GetName() == findName;
			});

		if (it == m_Students.end())
		{
			cout << "�л� ������ ã�� �� �����ϴ�. " << endl;
			getchar();
			return;
		}

		(*it)->print();
		cout << "�л� ã�� ����! " << endl;
		getchar();
	}
	void Management::remove()
	{
		system("cls");
		cin.ignore(1024, '\n');
		cout << "***********************************************************" << endl;
		cout << "                     �л����� ����                         " << endl;
		cout << "***********************************************************" << endl << endl;

		string findName = {};

		cout << "�л��̸��� �Է����ּ���. " << endl;
		getline(cin, findName);

		//if (erase_if(m_Students,
		//	[&](const unique_ptr<Student>& ptr)
		//	{
		//		return ptr->GetName() == findName;
		//	}))
		//{
		//	cout << "�л� ���� ����! " << endl;
		//	getchar();
		//}
		//else
		//{
		//	cout << "�л� ������ �����ϴ�. " << endl;
		//	getchar();
		//}

		auto it = find_if(m_Students.begin(), m_Students.end(),
			[&](unique_ptr<Student>& _e)
			{
				return _e->GetName() == findName;
			});

		if (it != m_Students.end())
		{
			m_Students.erase(it);
			cout << "�л� ���� ����" << endl;
			getchar();
		}
		else
		{
			cout << "�л� ������ �����ϴ�" << endl;
			getchar();
		}
	}
	void Management::end()
	{
		cout << "���α׷��� ����˴ϴ�." << endl;
		getchar();
	}
	void Management::title()
	{
		system("cls");
		cout << "***********************************************************" << endl;
		cout << "                     �л��������α׷�                      " << endl;
		cout << "***********************************************************" << endl << endl;
	}
	bool Management::cinCheck()
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�߸� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���. " << endl;
			return true;
		}
		return false;
	}
}