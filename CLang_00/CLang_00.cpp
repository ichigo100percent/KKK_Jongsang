#include "Stack.h"
#include "Queue.h"

int main()
{
	int n;
	cout << "높이를 입력하시오 : ";
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
