#pragma once
#include "std.h"

namespace Js
{
	enum class eMenu
	{
		None = 0,
		Add,
		Show,
		Find,
		Delete,
		Save,
		Load,
		Exit = 9,
	};

	class Management
	{
	public:
		Management();
		~Management();

		void Init();
		void Update();
		void release();

	private:
		void saveData(const char* _fileName);
		void loadData(const char* _fileName);

		void add();
		void print();
		void find();
		void remove();
		void end();

		void title();
		bool cinCheck();

	private:
		static vector<unique_ptr<class Student>> m_Students;
	};
}
