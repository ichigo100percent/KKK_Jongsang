#include <iostream>
#include <vector>
#include <queue>
#include <Windows.h>

using namespace std;

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