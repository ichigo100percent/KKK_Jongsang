#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
	const char* cc = "���ڿ��� �Է��մϴ�. This is a string";
	char cb[17]; //���ڿ��� ���� �� 16�� ���ڿ� ������ ���ڷ� null�� ����Ѵ�.
	char* str; //���ڿ� �����ʹ�

	memcpy(cb, cc, 17);

	str = (char*)malloc(strlen(cc) + 1);
	strcpy(str, cc);

	std::cout << "cc = " << cc << "   ���ڿ��� ũ��� " << strlen(cc) << std::endl;
	std::cout << "cb = " << cb << ", ���ڿ��� ũ��� " << strlen(cb) << std::endl;
	std::cout << "str= " << str << ", ���ڿ��� ũ��� " << strlen(str) << std::endl;

	free(str);
}