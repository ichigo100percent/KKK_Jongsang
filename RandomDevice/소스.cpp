#include <iostream>
#include <random>
using namespace std;

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 99);

	for (size_t i = 0; i < 100; i++)
	{
		int randValue = dist(gen);
		cout << randValue << endl;
	}
	return 0;
}