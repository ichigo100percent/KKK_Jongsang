#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <functional>
using namespace std;



int main()
{
	vector<int> a{ 1,10,100,1000 };

	a.insert(a.cend(), a.begin(), a.end());


}


