#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;


//2024. 05. 11j
/*
class Graph
{
public:
    Graph(int _size)
        : m_graph{}
    {
        m_graph.resize(_size);
    }

    void AddEdge(int _src, int _des, int _weight)
    {
        m_graph[_src].push_back(make_pair(_des, _weight));
    }

    vector<vector<pair<int, int>>>& GetGraph() { return m_graph; }

private:
    vector<vector<pair<int, int>>> m_graph;
};
vector<int> dijkstra(vector<vector<pair<int, int>>>& _g, int _s)
{
    int n = _g.size(); //그래프 정점 개수
    vector<int> dist(n, numeric_limits<int>::max()); //시작점으로 부터의 최단 거리를 저장할 배열
    dist[_s] = 0; //시작점의 최단 거리는 0

    //우선 순위 큐를 이용하여 정점할 점을 선택
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0,_s });

    while (!pq.empty())
    {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        for (size_t i = 0; i < _g[cur_node].size(); i++)
        {
            int next_node = _g[cur_node][i].first;
            int next_dist = _g[cur_node][i].second;

            if (dist[next_node] > cur_dist + next_dist)
            {
                dist[next_node] = cur_dist + next_dist;
                pq.push({ dist[next_node], next_node });
            }
        }
    }

    return dist;
};
//int main() {
//    //// 그래프 생성
//    //vector<vector<Edge>> graph = {
//    //    {{1, 4}, {2, 2}}, // 정점 1에서 정점 2와 정점 3로의 간선
//    //    {{0, 4}, {2, 1}, {3, 8}}, // 정점 2에서 정점 1, 3, 4로의 간선
//    //    {{0, 2}, {1, 1}, {3, 5}}, // 정점 3에서 정점 1, 2, 4로의 간선
//    //    {{1, 8}, {2, 5}} // 정점 4에서 정점 2와 정점 3으로의 간선
//    //};
//
//    int start = 1; // 시작점
//
//    Graph g(4);
//
//    g.AddEdge(0, 1, 4);
//    g.AddEdge(0, 2, 2);
//    g.AddEdge(1, 0, 4);
//    g.AddEdge(1, 2, 1);
//    g.AddEdge(1, 3, 8);
//    g.AddEdge(2, 0, 2);
//    g.AddEdge(2, 1, 1);
//    g.AddEdge(2, 3, 5);
//    g.AddEdge(3, 1, 8);
//    g.AddEdge(3, 2, 5);
//
//    vector<int> shortest_distances = dijkstra(g.GetGraph(), 3);
//
//    cout << "Shortest distances from vertex " << 3 << ":\n";
//    for (int i = 0; i < shortest_distances.size(); ++i) {
//        cout << "Vertex " << i << ": " << shortest_distances[i] << '\n';
//    }
//
//
//    //vector<int> shortest_distances = dijkstra(graph, start);
//
//    //cout << "Shortest distances from vertex " << start << ":\n";
//    //for (int i = 0; i < shortest_distances.size(); ++i) {
//    //    cout << "Vertex " << i << ": " << shortest_distances[i] << '\n';
//    //}
//
//    return 0;
//}
//




//다익스트라 행렬버전
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
				;
			}
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
*/


//인접리스트 다익스트라

//인접리스트그래프
vector<vector<pair<int, int>>> graph(4);
//최단거리를 저장할 배열
vector<int> dist(graph.size(), numeric_limits<int>::max());

void dijkstra(int _start)
{
	//시작점의 최단거리는 0이다.
	dist[_start] = 0;
	vector<bool> v(4, false);

	//우선순위 큐를 이용하여 정점할 점을 선택
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, _start });

	while (!pq.empty())
	{
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (v[cur_node])
			continue;

		v[cur_node] = true;

		for (auto& i : graph[cur_node])
		{
			int next_node = i.first;
			int next_dist = i.second;

			if (dist[next_node] > cur_dist + next_dist)
			{
				dist[next_node] = cur_dist + next_dist;
				pq.push({ dist[next_node], next_node });
			}
		}
	}
}



int main()
{
	graph =
	{
		{{1,4},{2,2}},
		{{0,4},{2,1},{3,8}},
		{{0,2},{1,1},{3,5}},
		{{1,8},{2,5}}
	};

	dijkstra(0);

	for (auto& i : dist)
	{
		cout << i << " ";
	}

	return 0;
}


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
	int n = g.size();
	vector<bool> v(n, false);
	vector<int> dist(n, INF);
	dist[_s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, _s));

	while (!pq.empty())
	{
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (v[cur_node])
			continue;

		v[cur_node] = true;

		for (int next_node = 0; next_node < n; ++next_node)
		{
			int next_dist = g[cur_node][next_node];

			if (dist[next_node] > cur_dist + next_dist)
			{
				dist[next_node] = cur_dist + next_dist;
				pq.push(make_pair(dist[next_node], next_node));
			}
		}
	}
	for (auto& e : dist)
	{
		cout << e << " ";
	}
}

int main()
{
	dijkstra(0);

	return 0;
}

