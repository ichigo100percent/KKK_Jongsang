#include "Test1.h"


vector<component*> vec;



//template <typename T>
//T* AddComponent()
//{
//	T* comp = new T();
//
//	vec[(UINT)comp->GetType()] = comp;
//
//	return comp;
//}


int main()
{
	vec.resize((UINT)Type::end);
	auto s1 = new script();
	auto s2 = new script();

	vec[(UINT)s1->GetType()] = s1;
	vec[(UINT)s2->GetType()] = s2;
}