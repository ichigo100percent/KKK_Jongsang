#include "Test1.h"


class Test
{
public:
	Test() {}
	virtual ~Test() {}

	virtual void T1() = 0;
};


class Test2 : public Test
{
public:
	Test2() {}
	~Test2() {}


};

extern int a = 100;

vector<shared_ptr<int>> vec1;
vector<unique_ptr<int>> vec2;

int main()
{
	shared_ptr<int> t1 = fun2(50);
	shared_ptr<int> t2 = fun2(50);
	shared_ptr<int> t3 = fun2(50);

	vec1.push_back(t1);
	vec1.push_back(t2);
	vec1.push_back(t3);

	unique_ptr<int> t4 = fun3(10);

	vec2.push_back(move(t4));

	for (auto& t : vec2)
	{
		cout << *t << endl;
	}
	int x = 5;
	int y = 10;

	// x�� y�� ���� ��쿡�� ���α׷��� ��ӵ�
	assert(true);

	// �� ���� assert ���� �� ������� ����
	// ���� �� ���� ������� ����
	std::cout << "�� ���� ������� ����" << std::endl;
}