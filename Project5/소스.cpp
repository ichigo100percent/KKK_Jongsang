#include <iostream>

int main()
{
	wchar_t str[50];
	int value = 42;

	swprintf_s(str, 50, L"The value is %d", value);

	wprintf(L"%s\n", str);
}