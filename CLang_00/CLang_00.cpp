#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
     포인터 배열
*/

int main()
{
	printf("\n==========포인터 배열========\n");

	system("cls");

	char* pArray[6];

	for (int i = 0; i < 6; i++)
	{
		pArray[i] = (char*)malloc(sizeof(char) * 4);

	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pArray[i][j] = 65 + i * 3 + j;
		}
		//문자열 마지막은 null로 한다.
		
		pArray[i][3] = 0;
	}

	for (int i = 0; i < 6; i++)
	{
		printf("\n");
		printf("[%d]=%s", i, pArray[i]);
	}
	for (int i = 0; i < 6; i++)
	{
		free(pArray[i]);
	}

	_getch();
}
