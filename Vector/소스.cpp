#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec = { 1,10,100,1000 };

	for (auto element : vec)
	{
		cout << element << " ";
	}

	auto it = std::find(vec.begin(), vec.end(), 100);

	if (it != vec.end())
	{
		vec.erase(it);
	}
	else
	{
		cout << "fail" << endl;
	}

	for (auto element : vec)
	{
		cout << element << " ";
	}
}