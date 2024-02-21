#include <iostream>
#include <functional>
#include <vector>

enum class HEL
{
	viper,
	zeka,
	doran,
	delight,

};

struct T1
{
	HEL GetHEL() { return h; }

	HEL h;
};


int main()
{
	std::vector<T1*> test;

	for (size_t i = 0; i < 10; i++)
	{
		T1* t = new T1();
		test.push_back(t);
	}

	for (std::vector<T1*>::iterator iter = test.begin(); iter != test.end(); iter++)
	{
		(*iter)->GetHEL();
	}
}