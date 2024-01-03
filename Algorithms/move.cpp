#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

/*
move():

목적: 주어진 범위의 각 원소를 다른 범위로 이동시킨다.
사용 예제: 값이 이동 가능한 (예: 유일한 소유권을 갖는) 타입에서 사용된다.
특이 사항: 이동은 원래 컨테이너의 상태를 변경하며, 이후에 해당 원소에 접근하는 행위는 정의되지 않는다.
*/

using namespace std;

class MyClass
{
public:
	MyClass() = default;
	MyClass(const MyClass& src) = default;
	MyClass(string_view str) : mStr(str) {}
	virtual ~MyClass() = default;

	//이동 대입연산자
	MyClass& operator=(MyClass&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}
		mStr = std::move(rhs.mStr);
		cout << "Move operator= (mStr=" << mStr << ")" << endl;
		return *this;
	}

	void setString(string_view str) { mStr = str; }
	string_view getString() const { return mStr; }

private:
	string mStr;
};


int main()
{
	vector<MyClass> vecSrc{ MyClass("a"), MyClass("b"), MyClass("c") };
	vector<MyClass> vecDst(vecSrc.size());

	move(begin(vecSrc), end(vecSrc), begin(vecDst));

	for (const auto& c : vecDst)
	{
		cout << c.getString() << " ";
	}

	return 0;
}