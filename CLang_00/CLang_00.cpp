#include "Stack.h"
#include "Queue.h"

int main()
{
	int n;
	cout << "���̸� �Է��Ͻÿ� : ";
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for(int j = 1; j<=n-i; ++j)
		{
			cout << " ";
		}
		for (int j = 1; j <= i * 2 - 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = n - 1; i >= 1; --i)
	{
		for (int j = 1; j <= n - i; ++j)
		{
			cout << " ";
		}
		for (int j = 1; j <= i * 2 - 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
}
