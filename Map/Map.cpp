#include <map>
#include <iostream>
#include <string>

using namespace std;

class Data final
{
public:
	explicit Data(int value = 0) : mValue(value) {};
	int getValue() const { return mValue; }
	void setValue(int value) { mValue = value; }

private:
	int mValue;
};

int main()
{
	map<string, Data> dataMap;
	dataMap["a"] = Data(4);
	dataMap["b"] = Data(6); // 키가 1인 원소의 값을 바꾼다.


}
