#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
	const char* cc = "문자열을 입력합니다. This is a string";
	char cb[17]; //문자열을 만들 떄 16개 문자와 마지막 문자로 null를 사용한다.
	char* str; //문자열 포인터다

	memcpy(cb, cc, 17);

	str = (char*)malloc(strlen(cc) + 1);
	strcpy(str, cc);

	std::cout << "cc = " << cc << "   문자열의 크기는 " << strlen(cc) << std::endl;
	std::cout << "cb = " << cb << ", 문자열의 크기는 " << strlen(cb) << std::endl;
	std::cout << "str= " << str << ", 문자열의 크기는 " << strlen(str) << std::endl;

	free(str);
}