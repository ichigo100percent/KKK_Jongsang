#include "Test1.h"


int main()
{
	

	for (size_t i = 0; i < 100; i++)
	{
		int a = rand() % 2;

		if (a)
		{
			cout << "is true" << endl;
		}
		else
		{
			cout << "is false" << endl;
		}
	}

}
