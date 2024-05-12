#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;
int N, E;
int Graph[10][10], Dist[10];

int INF = 100000; //numeric_limits<int>::max();

int dijkstra(int _src, int _dst)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<bool> visited(10, false);

	for (size_t i = 0; i < N; ++i)
	{
		Dist[i] = INF;
	}

	Dist[_src] = 0;
	pq.push(make_pair(0, _src));

	while (!pq.empty())
	{
		int u = pq.top().second;

		if (u == _dst)
			return pq.top().first;

		pq.pop();
		if (visited[u])
			continue;

		visited[u] = true;
		for (size_t v = 0; v < N; ++v)
		{
			if (Dist[v] > Dist[u] + Graph[u][v])
			{
				Dist[v] = Dist[u] + Graph[u][v];
				pq.push(make_pair(Dist[v], v));
			}
		}
	}

	return INF;
}

int main()
{
	//n 노드 e 간선
	cin >> N >> E;

	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			if (i == j)
				Graph[i][j] = 0;
			else
			{
				Graph[i][j] = INF;
			}
		}
	}

	for (size_t i = 0; i < E; ++i)
	{
		//출발, 도착, 비용
		int u, v, cost;

		//무방향그래프 
		cin >> u >> v >> cost;
		Graph[u][v] = Graph[v][u] = cost;
	}

	for (size_t i = 0; i < N; i++)
	{
		cout << dijkstra(0, i) << endl;
	}

	return 0;
}

