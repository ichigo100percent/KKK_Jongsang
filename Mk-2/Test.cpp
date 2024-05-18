//#include "Test.h"
//
//
//
//namespace J
//{
//	void Manager::Destroy()
//	{
//		vector<Person*> delPerson = {};
//		findPerson(delPerson);
//		erasePeople();
//		deletePerson(delPerson);
//	}
//	void Manager::findPerson(vector<Person*>& _p)
//	{
//		for (auto n : People)
//		{
//			if (n->GetAge() > 20)
//			{
//				_p.push_back(n);
//			}
//		}
//	}
//	void Manager::erasePeople()
//	{
//		erase_if(People,
//			[](Person* n)
//			{
//				return n->GetAge() > 20;
//			});
//	}
//	void Manager::deletePerson(vector<Person*> _p)
//	{
//		for (auto n : _p)
//		{
//			delete n;
//			n = nullptr;
//		}
//	}
//
//	int Test::a = 10;
//}