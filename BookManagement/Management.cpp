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
			cout << "1. 학생 추가  2. 학생 출력  3. 학생 찾기  4. 학생 삭제  5. 저장  6. 로드  9.종료" << endl;
			cout << "메뉴를 선택해주세요. " << endl;
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
			cout << "등록된 학생이 없습니다! " << endl;
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

			cout << "파일 저장 성공! " << endl;
			getchar();
		}
		else
		{
			cout << "파일 저장에 실패했습니다. " << endl;
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
			cout << "파일 로드가 실패했습니다. " << endl;
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
		cout << "파일 로드 성공! " << endl;
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
			cout << "                     학생정보를 입력하세요                 " << endl;
			cout << "***********************************************************" << endl << endl;
			cout << "이름을 입력하세요." << endl;
			getline(cin, name);

			if (cinCheck())
				continue;

			cout << "주소를 입력하세요. " << endl;
			getline(cin, address);
			if (cinCheck())
				continue;

			cout << "국어 점수를 입력해주세요" << endl;
			cin >> kor;
			while (cinCheck())
			{
				cin >> kor;
			}			
			cout << "영어 점수를 입력해주세요" << endl;
			cin >> eng;
			while (cinCheck())
			{
				cin >> eng;
			}
			cout << "수학 점수를 입력해주세요" << endl;
			cin >> math;
			while (cinCheck())
			{
				cin >> math;
			}
			m_Students.push_back(make_unique<Student>(name, address, kor, eng, math));

			cout << "학생 추가 완료! " << endl;
			system("pause");
			break;
		}
	}
	void Management::print()
	{
		system("cls");
		cin.ignore(1024, '\n');
		cout << "***********************************************************" << endl;
		cout << "                     학생정보 출력                         " << endl;
		cout << "***********************************************************" << endl << endl;

		if (m_Students.empty())
		{
			cout << "등록된 학생이 없습니다. " << endl;
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
		cout << "                     학생정보 찾기                         " << endl;
		cout << "***********************************************************" << endl << endl;
		
		string findName = {};

		cout << "학생이름을 입력해주세요. " << endl;
		getline(cin, findName);

		auto it = find_if(m_Students.begin(), m_Students.end(),
			[&](const unique_ptr<Student>& ptr)
			{
				return ptr->GetName() == findName;
			});

		if (it == m_Students.end())
		{
			cout << "학생 정보를 찾을 수 없습니다. " << endl;
			getchar();
			return;
		}

		(*it)->print();
		cout << "학생 찾기 성공! " << endl;
		getchar();
	}
	void Management::remove()
	{
		system("cls");
		cin.ignore(1024, '\n');
		cout << "***********************************************************" << endl;
		cout << "                     학생정보 삭제                         " << endl;
		cout << "***********************************************************" << endl << endl;

		string findName = {};

		cout << "학생이름을 입력해주세요. " << endl;
		getline(cin, findName);

		//if (erase_if(m_Students,
		//	[&](const unique_ptr<Student>& ptr)
		//	{
		//		return ptr->GetName() == findName;
		//	}))
		//{
		//	cout << "학생 삭제 성공! " << endl;
		//	getchar();
		//}
		//else
		//{
		//	cout << "학생 정보가 없습니다. " << endl;
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
			cout << "학생 삭제 성공" << endl;
			getchar();
		}
		else
		{
			cout << "학생 정보가 없습니다" << endl;
			getchar();
		}
	}
	void Management::end()
	{
		cout << "프로그램이 종료됩니다." << endl;
		getchar();
	}
	void Management::title()
	{
		system("cls");
		cout << "***********************************************************" << endl;
		cout << "                     학생관리프로그램                      " << endl;
		cout << "***********************************************************" << endl << endl;
	}
	bool Management::cinCheck()
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "잘못 입력하였습니다. 다시 입력해주세요. " << endl;
			return true;
		}
		return false;
	}
}