#include "¼Ò½º.h"
#include <vector>
#include <map>
#include <string>
class test1
{
public:
	unique_ptr<int> t1()
	{
	    auto a = make_unique<int>(10);

		return a;
	}

};



int main()
{
	shared_ptr<int> a = make_shared<int>(10);

	auto b = a;
	
	//int* c = b;

	b.reset();

}