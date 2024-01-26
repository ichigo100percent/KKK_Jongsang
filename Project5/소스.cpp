#include <iostream>
#include <vector>

using namespace std;



int main()
{
	int a = 100;

	auto mylamda = [&a](int _a) { a += _a; return a; };


	auto c = mylamda(5);

	double data = 1.23;
	auto capturingVLambda = [data] {cout << "Data = " << data << endl; };
	capturingVLambda();

};