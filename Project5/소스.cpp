#include <iostream>
#include <functional>
#include <vector>
#include <bitset>
#include <memory>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string_view>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
#pragma warning(disable: 4996)

int partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (size_t j = low; j < high; j++)
	{
		if (arr[j] > pivot)
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

		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}

void sort(vector<int>& arr)
{
	quicksort(arr, 0, arr.size() - 1);
}

void print(vector<int>& arr)
{
	for (auto num : arr)
	{
		cout << num << ' ';
	}
}

int main()
{
	vector<int> vec = { 1,4,3,2,5 };

	sort(vec);

	print(vec);
}