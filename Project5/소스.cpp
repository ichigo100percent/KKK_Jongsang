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


// RECT 구조체 정의
struct RECT {
	int left;
	int top;
	int right;
	int bottom;
};

// 겹치는 영역을 계산하는 함수
bool IntersectRect(RECT* result, const RECT* r1, const RECT* r2) {
	// x축과 y축에 대해 겹치는 영역을 찾습니다.
	int maxLeft = std::max(r1->left, r2->left);
	int minRight = std::min(r1->right, r2->right);
	int maxTop = std::max(r1->top, r2->top);
	int minBottom = std::min(r1->bottom, r2->bottom);

	// 겹치는 영역이 없는 경우
	if (maxLeft >= minRight || maxTop >= minBottom) {
		result->left = result->top = result->right = result->bottom = 0;
		return false;
	}

	// 겹치는 영역이 있는 경우
	result->left = maxLeft;
	result->top = maxTop;
	result->right = minRight;
	result->bottom = minBottom;
	return true;
}
//int main() 
//{
//	// 예제 RECT 구조체 생성
//	RECT r1 = { 0, 0, 100, 100 };
//	RECT r2 = { 90, 100, 150, 150 };
//	RECT intersect = {};
//
//	// 겹치는 영역 계산
//	bool isIntersected = IntersectRect(&intersect, &r1, &r2);
//
//	// 결과 출력
//	if (isIntersected) {
//		std::cout << "겹치는 영역: (" << intersect.left << ", " << intersect.top << ") - (" << intersect.right << ", " << intersect.bottom << ")" << std::endl;
//	}
//	else {
//		std::cout << "겹치는 영역이 없습니다." << std::endl;
//	}
//
//	return 0;
//}

using namespace std;

//행렬
int g[4][4] =
{
	{0,4,2,0},
	{4,0,1,8},
	{2,1,0,5},
	{0,8,5,0},
};

int dist[4];

bool v[4];

int INF = numeric_limits<int>::max();

void dijkstra(int _start)
{
	fill_n(dist, 4, INF);
	fill_n(v, 4, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	//거리, 노드
	pq.push(make_pair(0, _start));
	dist[_start] = 0;

	while (!pq.empty())
	{
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (v[cur_node])
			continue;

		v[cur_node] = true;

		for (int next_node = 0; next_node < 4; ++next_node)
		{
			int next_dist = g[cur_node][next_node];

			if (dist[next_node] > cur_dist + next_dist && g[cur_node][next_node] != 0)
			{
				dist[next_node] = cur_dist + next_dist;
				pq.push(make_pair(dist[next_node], next_node));
;			}
		}
	}
}

int main()
{
	dijkstra(0);

	for (auto& e : dist)
	{
		cout << e << " ";
	}

	return 0;

}