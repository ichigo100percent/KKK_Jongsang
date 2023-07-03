#include "CLang_01.h"
//#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

char name[100];

void getchar(char* ch)
{
	strcpy(name, ch);
}

int main()
{
	char cc[100];

	cin >> cc;

	getchar(cc);

	cout << name;
}