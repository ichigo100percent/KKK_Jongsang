#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main()
{
    char str1[100];
    char str2[100];
    scanf("%[^\n]", &str1);
    printf("%s\n", str1);

    while (getchar() != '\n');

    scanf("%[^\n]", &str2);
    printf("%s", str2);
    return 0;
}


