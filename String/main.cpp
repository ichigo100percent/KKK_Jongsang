#include <iostream>
#include <vector>

using namespace std;

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