#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

/*
	https://blog.naver.com/ndb796/221230967614
	대표적인 그래프 알고리즘.
	'합칩합 찾기' 라는 의미를 가진 알고리즘이다. 서로소 집합(Disjoint-set) 알고리즘이라고 부르기도 한다.
	구체적으로 여러 개의 노드개 존재할 때 두 개의 노드를 선택해서, 현재 이 두 노드가 서로 같은 그래프에 속하는지 판별하는 알고리즘이다.
*/

int getParent(vector<int>& _parent, int x)
{
	if (_parent[x] == x) return x;

	return _parent[x] = getParent(_parent, _parent[x]);
}

// 각 부모 노드를 합칩니다.
void unionParent(vector<int>& _parent, int _a, int _b)
{
	_a = getParent(_parent, _a);
	_b = getParent(_parent, _b);

	if (_a < _b)
		_parent[_b] = _a;
	else
		_parent[_a] = _b;
}

// 같은 부모 노드를 가지는지 확인합니다.
bool findParent(vector<int>& _parent, int _a, int _b)
{
	_a = getParent(_parent, _a);
	_b = getParent(_parent, _b);

	if (_a == _b)
		return true;
	else
		return false;
}

int main()
{
	vector<int> parent(11);

	for (int i = 0; i < parent.size(); i++)
	{
		parent[i] = i;
	}

	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));

	return 0;
}

class Edge
{
public:
	int node[2];
	int distance;
	Edge(int a, int b, int _distance)
	{
		node[0] = a;
		node[1] = b;
		distance = _distance;
	}

	bool operator<(Edge& edge)
	{
		return this->distance < edge.distance;
	}
};

int main()
{
	// 노드
	int n = 7;
	// 간선
	int m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));
	sort(v.begin(), v.end());


	int set[7];
	for (int i = 0; i < n; i++)
	{
		set[i] = i;
	}


	return 0;
}