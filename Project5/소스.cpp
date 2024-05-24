#define NOMINMAX
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

//IntersectRect
/*
class Collider
{
public:
	RECT GetRect() {}

};

struct Vec2
{
	float x;
	float y;
};

Vec2 GetPos() {}

void AdjustCollisionPos(Collider* b1, Collider* b2)
{
	RECT r1 = b1->GetRect();
	RECT r2 = b2->GetRect();

	Vec2 pos = GetPos();

	RECT intersect = {};

	if (IntersectRect(&intersect, &r1, &r2))
	{
		INT32 w = intersect.right - intersect.left;
		INT32 h = intersect.bottom - intersect.top;

		if (w > h)
		{
			if (intersect.top == r2.top)
			{
				pos.y -= h;
			}
			else
			{
				pos.y += h;
			}
		}
		else
		{
			if (intersect.left == r2.left)
			{
				pos.x -= w;
			}
			else
			{
				pos.x += w;
			}
		}
	}
}
*/


// RECT ����ü ����
struct RECT {
	int left;
	int top;
	int right;
	int bottom;
};

// ��ġ�� ������ ����ϴ� �Լ�
bool IntersectRect(RECT* result, const RECT* r1, const RECT* r2) {
	// x��� y�࿡ ���� ��ġ�� ������ ã���ϴ�.
	int maxLeft = std::max(r1->left, r2->left);
	int minRight = std::min(r1->right, r2->right);
	int maxTop = std::max(r1->top, r2->top);
	int minBottom = std::min(r1->bottom, r2->bottom);

	// ��ġ�� ������ ���� ���
	if (maxLeft >= minRight || maxTop >= minBottom) {
		result->left = result->top = result->right = result->bottom = 0;
		return false;
	}

	// ��ġ�� ������ �ִ� ���
	result->left = maxLeft;
	result->top = maxTop;
	result->right = minRight;
	result->bottom = minBottom;
	return true;
}
//int main() 
//{
//	// ���� RECT ����ü ����
//	RECT r1 = { 0, 0, 100, 100 };
//	RECT r2 = { 90, 100, 150, 150 };
//	RECT intersect = {};
//
//	// ��ġ�� ���� ���
//	bool isIntersected = IntersectRect(&intersect, &r1, &r2);
//
//	// ��� ���
//	if (isIntersected) {
//		std::cout << "��ġ�� ����: (" << intersect.left << ", " << intersect.top << ") - (" << intersect.right << ", " << intersect.bottom << ")" << std::endl;
//	}
//	else {
//		std::cout << "��ġ�� ������ �����ϴ�." << std::endl;
//	}
//
//	return 0;
//}

using namespace std;

class Parent
{
public:
	Parent() {}

	virtual void Test1()
	{
		cout << "�θ� �Լ�1 ȣ��" << endl;
	}
};

class Child1 : public Parent
{
public:
	Child1() {}

	virtual void Test1() override
	{
		cout << "�ڽ� �Լ�1 ȣ��" << endl;
	}

	virtual void Test2()
	{
		cout << "�ڽ� �����Լ�2 ȣ��" << endl;
	}
};

int main()
{
	shared_ptr<Parent> p = make_shared<Child1>();

	// ȣ�� �Ұ�
	// p->Test2();

	auto p2 = dynamic_pointer_cast<Child1>(p);

	p2->Test2();

}