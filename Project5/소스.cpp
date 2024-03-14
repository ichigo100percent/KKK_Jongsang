#include <iostream>
#include <functional>
#include <vector>
#include <bitset>
#include <memory>
#include <vector>
#include <algorithm>
#include <time.h>


#pragma warning(disable: 4996)

using namespace std;

namespace Js
{
	class String
	{
	public:
		String(const char* _str)
			: m_cStr(nullptr)
		{
			auto len = strlen(_str);

			m_cStr = std::make_unique<char[]>(len + 1);
			strcpy(m_cStr.get(), _str);
		}

	private:
		std::unique_ptr<char[]> m_cStr;
	};
}

int main()
{
	int vec[3][3] =
	{
		1,2,3,
		4,5,6,
		7,8,9
	};
	int vect[3][3] =
	{
			3, 4, 1,
			5, 5, 7,
			8, 3, 2,
	};
}