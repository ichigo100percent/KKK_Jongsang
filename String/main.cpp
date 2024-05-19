#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma region String Ŭ���� �����
namespace J
{
	class String
	{
	public:
		String()
			: m_cStr(nullptr)
		{

		}

		String(const char* _str)
			: m_cStr(nullptr)
		{
			int len = strlen(_str);

			m_cStr = new char[len + 1];

			for (size_t i = 0; i < len; i++)
			{
				m_cStr[i] = _str[i];
			}

			m_cStr[len] = '\0';
		}

		~String()
		{
			delete[] m_cStr;
		}

		friend ostream& operator<<(ostream& _output, const String& _str)
		{
			if (_str.m_cStr != nullptr)
			{
				_output << _str.m_cStr;
			}

			return _output;
		}

	private:
		char* m_cStr;
	};
}

int main()
{
	J::String str = "hello";

	cout << str;

	J::String str2;

	str2 = str;
}
#pragma endregion

#pragma region ��ҹ��� ��ȯ
// for�� ���
string solution(string myString)
{
	string answer = "";

	for (size_t i = 0; i < myString.length(); i++)
	{
		answer += tolower(myString[i]);
		//answer += toupper(myString[i]);
	}

	return answer;
}
// fransfrom �Լ����
string solution(string myString)
{
	transform(myString.begin(), myString.end(), myString.begin(), tolower);
	//transform(myString.begin(), myString.end(), myString.begin(), toupper);
	return myString;
}
#pragma endregion

#pragma region ���ϴ� ���ڿ� ã��
int solution(string myString, string pat)
{

	transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
	transform(pat.begin(), pat.end(), pat.begin(), ::tolower);

	if (myString.size() >= pat.size()) 
	{
		// string.find() ���ڿ� �� �ش� ���ڿ��� ã������ ���� ��ġ�� ��ȯ �׷��� ���� ��� String::npos ��ȯ
		if (myString.find(pat) != string::npos) return 1;
	}

	return 0;
}

int main()
{
	std::string myString1 = "AbCdEfG";
	std::string pat1 = "c";
	std::cout << solution(myString1, pat1) << std::endl; // should print 1

	std::string myString2 = "aaAA";
	std::string pat2 = "aaaaa";
	std::cout << solution(myString2, pat2) << std::endl; // should print 0

	return 0;
}
#pragma endregion