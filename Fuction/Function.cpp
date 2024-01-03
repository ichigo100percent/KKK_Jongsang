#include <iostream>
#include <string>
#include <functional>

using namespace std;

void func(int num, const string& str)
{
	cout << "func(" << num << ", " << str << ")" << endl;
}

//int main()
//{
//	function<void(int, const string&)> f1 = func;
//
//	f1(1, "test");
//
//	cout << 4 / 2 << endl;
//}