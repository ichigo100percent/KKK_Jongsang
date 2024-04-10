#include <iostream>
#include <functional>
#include <string>
#include <conio.h>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

int partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (size_t j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);

	return i + 1;
}

void quicksort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);

		quicksort(arr, pivot + 1, high);
		quicksort(arr, low, pivot - 1);
	}
}

void sort(vector<int>& arr)
{
	quicksort(arr, 0, arr.size() - 1);
}

void print(vector<int>& arr)
{
	for (auto& n : arr)
	{
		cout << n << " ";
	}
}

int main()
{
	vector<int> vec = { 10,9,1,2,3,4,5,6,7,8 };

	sort(vec);

	print(vec);
}