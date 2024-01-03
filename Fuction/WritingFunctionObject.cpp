#include <functional>
#include <algorithm>
#include <cctype>
#include <string_view>
#include <iostream>

using namespace std;

class myIsDigit
{
public:
	bool operator()(char c)const { return ::isdigit(c) != 0; }
};

