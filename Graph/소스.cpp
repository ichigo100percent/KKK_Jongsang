#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> vec(4, vector<int>(4, 0));


	vec[0] = { 0,0,1,1 };
	vec[1] = { 1,0,1,1 };
	vec[2] = { 0,1,0,0 };
	vec[3] = { 0,0,0,0 };

	int target = 1;

	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[target][i] != 0)
		{
			cout << i << "¹ø ";
		}
	}

	return 0;
}