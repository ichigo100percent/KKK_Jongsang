#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

/*
move():

����: �־��� ������ �� ���Ҹ� �ٸ� ������ �̵���Ų��.
��� ����: ���� �̵� ������ (��: ������ �������� ����) Ÿ�Կ��� ���ȴ�.
Ư�� ����: �̵��� ���� �����̳��� ���¸� �����ϸ�, ���Ŀ� �ش� ���ҿ� �����ϴ� ������ ���ǵ��� �ʴ´�.
*/

using namespace std;

class MyClass
{
public:
	MyClass() = default;
	MyClass(const MyClass& src) = default;
	MyClass(string_view str) : mStr(str) {}
	virtual ~MyClass() = default;

	//�̵� ���Կ�����
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