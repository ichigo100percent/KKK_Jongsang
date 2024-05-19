#include <vector>
#include <queue>
#include <iostream>
using namespace std;


int main()
{
	int** n = new int*[5]();


	for (size_t i = 0; i < 5; i++)
	{
		n[i] = new int[5]();
		for (size_t j = 0; j < 5; j++)
		{
			cout << n[i][j] << " ";
		}
		cout << endl;
	}

	int* n1 = new int();

	cout << n1[0] << " " << *n1 << endl;

	int** n2 = new int* ();
	n2[0] = new int();

	cout << n2[0][0] << endl;

	return 0;
}


int main()
{
	int** a = new int* [5]();

	for (int i = 0; i < 5; i++)
	{
		a[i] = new int[5];
		for (int j = 0; j < 5; j++)
		{
			a[i][j] = j + 1;
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

int main()
{
	int n = 20;

	for (int i = 0; i < n; i++)
	{
		for (int j = n - i - 1; j > 0; j--)
		{
			cout << "  ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << "★";
		}
		for (int j = 0; j < i; j++)
		{
			cout << "★";
		}
		cout << endl;
	}

	return 0;
}