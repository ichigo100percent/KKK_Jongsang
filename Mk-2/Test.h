#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <string>
#include <queue>


namespace J
{
	using namespace std;

	static int gs_A = 100;

	class Person
	{
	public:
		Person(string _name, int _age)
			: Name(_name)
			, Age(_age)
		{
		}

		string GetName() { return Name; }
		int	   GetAge() { return Age; }
	private:
		string Name;
		int	   Age;
	};


	class Manager
	{
	public:
		Manager(){}

		void			AddPerson(Person* _p) { People.push_back(_p); }
		vector<Person*> GetPeople() { return People; }
		void			Destroy();

	private:
		void			findPerson(vector<Person*>& _p);
		void			erasePeople();
		void			deletePerson(vector<Person*> _p);

	private:
		vector<Person*> People;
	};

	class Test
	{
	public:
		Test() {}

		static int GetA() { return a; }
		static void SetA(int _val) { a = _val; }
		
	private:
		static int a;
	};
}