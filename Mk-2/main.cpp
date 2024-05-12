#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <set>
using namespace std;


//무한값 
int INF = 100000; //numeric_limits<int>::max();

//인접행렬 초기화
vector<vector<int>> g
{
	{INF,4,2,INF},
	{4,INF,1,8},
	{2,1,INF,5},
	{INF,8,5,INF},
};


void dijkstra(int _s)
{
	int size = g.size();
	vector<int> dist(4, INF);
	dist[_s] = 0;
	vector<bool> v(size, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, _s));

	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (v[curNode])
			continue;
		v[curNode] = true;

		for (int nextNode = 0; nextNode < size; nextNode++)
		{
			int nextDist = g[curNode][nextNode];

			if (dist[nextNode] > curDist + nextDist)
			{
				dist[nextNode] = curDist + nextDist;
				pq.push(make_pair(dist[nextNode], nextNode));
			}
		}
	}
	
	cout << _s << "번 노드의 각 노드 사이의 최단거리는 ";

	for (auto& e : dist)
	{
		cout << e << " ";
	}
	cout << "입니다" << endl;
}

int main()
{
	dijkstra(1);

	return 0;
}