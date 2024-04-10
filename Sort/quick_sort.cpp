#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

int partition(std::vector<int>& _arr, int _low, int _high)
{
	int pivot = _arr[_high];
	int i = _low - 1;
	
	for (size_t j = _low; j < _high; j++)
	{
		if (_arr[j] < pivot)
		{
			i++;
			std::swap(_arr[i], _arr[j]);
		}
	}

	std::swap(_arr[i + 1], _arr[_high]);

	return i + 1;
}

void quick_sort(std::vector<int>& _arr, int _low, int _high)
{
	if (_low < _high)
	{
		int pivot = partition(_arr, _low, _high);

		quick_sort(_arr, pivot + 1, _high);
		quick_sort(_arr, _low, pivot - 1);
	}
}

void sort(std::vector<int>& _arr)
{
	quick_sort(_arr, 0, _arr.size() - 1);
}

void print(std::vector<int>& _arr)
{
	for (auto& n : _arr)
	{
		std::cout << n << ' ';
	}
}

int main()
{
	srand(time(0));

	std::vector<int> vec(10, 0);

	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] = 1 + (rand() % 100);
	}
	print(vec);

	std::cout << '\n';

	sort(vec);

	print(vec);

	return 0;
}