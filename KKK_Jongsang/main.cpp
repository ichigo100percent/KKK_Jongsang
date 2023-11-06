#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <functional>
using namespace std;


template<typename T>
void printVector(const vector<T>& v)
{
	for (auto& element : v)
	{
		cout << element << " ";
	}
	cout << endl;
}

int main()
{

}


