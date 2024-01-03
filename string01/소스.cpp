#include <iostream>
#include <string>

/*
int main()
{
	const char* cc = "문자열을 입력합니다. This is a string";
	std::string str = "";   // 문자열 포인터이다.

	str = cc;
	std::cout << "str= " << str.data() << ", 문자열의 크기는 " << str.length() << std::endl;

	str = "클래스 내부에서 공간을 잡는다.";
	str += " 따라서 별도 메모리 공간을 잡지 않아도 사용이 가능하다.";
	std::cout << "str= " << str.data() << ", 문자열의 크기는 " << str.length() << std::endl;
}
*/

int main()
{
	std::string s0("Initial string");
	std::string s1;
	std::string s2(s0);
	std::string s3(s0, 8, 3);
	std::string s4(s0, 6);
	std::string s5(10, 'x');

	std::cout << "s1 : " << s1 << std::endl;
	std::cout << "s2 : " << s2 << std::endl;
	std::cout << "s3 : " << s3 << std::endl;
	std::cout << "s4 : " << s4 << std::endl;
	std::cout << "s5 : " << s5 << std::endl;
	return 0;
}