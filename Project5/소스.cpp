#include <iostream>
#include <functional>
#include <vector>
#include <bitset>
#include <memory>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string_view>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <sstream>
using namespace std;


int getCountWord(const string& str)
{
	int count = 0;
	istringstream iss(str);
	string word = " ";

	while (iss >> word)
	{
		count++;
	}

	return count;
}

int main() {
    std::string data = "42 3.14 Hello";

    // 문자열을 스트림으로 변환
    std::istringstream iss(data);

    int num;
    double pi;
    std::string text;

    // 스트림에서 데이터를 읽음
    iss >> pi >> num >> text;

    // 읽어온 데이터 출력
    std::cout << "Integer: " << num << std::endl;
    std::cout << "Double: " << pi << std::endl;
    std::cout << "String: " << text << std::endl;

    return 0;
}
