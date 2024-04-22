#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Graph
{
public:
	Graph(int _vertices)
		: m_Vertices(_vertices)
	{
		m_adjMatrix.resize(_vertices, vector<int>(m_Vertices, 0));
	}

	void AddEdge(int _src, int _dest)
	{
		if (_src != _dest)
		{
			m_adjMatrix[_src][_dest] = 1;
			m_adjMatrix[_dest][_src] = 1;
		}
	}

	void Show()
	{
		for (auto& i : m_adjMatrix)
		{
			for (auto& j : i)
			{
				cout << j << " ";
			}
			cout << "\n";
		}
	}

	vector<vector<int>> GetMatrix() { return m_adjMatrix; }

private:
	int m_Vertices;
	vector<vector<int>> m_adjMatrix;
};

void dfs(vector<vector<int>> _matrix, vector<bool>& _visited, int _start)
{
	int size = _matrix[_start].size();
	_visited[_start] = true;

	cout << _start << " ";

	for (size_t i = 0; i < size; i++)
	{
		if (_matrix[_start][i] == 1 && !_visited[i])
		{
			dfs(_matrix, _visited, i);
		}
	}
}

void Dfstraversal(vector<vector<int>>& _matrix)
{
	int size = _matrix.size();
	vector<bool> visited(size, false);

	for (size_t i = 0; i < size; i++)
	{
		if (!visited[i])
			dfs(_matrix, visited, i);
	}
}

//int main()
//{
//	Graph g(6);
//
//	g.AddEdge(0, 1);
//	g.AddEdge(0, 2);
//	g.AddEdge(0, 5);
//	g.AddEdge(2, 4);
//	g.AddEdge(3, 0);
//	g.AddEdge(4, 1);
//	g.AddEdge(5, 5);
//
//	g.Show();
//
//	auto matrix = g.GetMatrix();
//
//	Dfstraversal(matrix);
//
//	return 0;
//}





void dfs(const vector<vector<int>>& graph, int start, unordered_set<int>& visited) {
	if (visited.find(start) == visited.end()) {
		cout << start << " ";
		visited.insert(start);
		for (int neighbor : graph[start]) {
			dfs(graph, neighbor, visited);
		}
	}
}

int main() {
	// 그래프 정의 (인접 리스트 활용)
	vector<vector<int>> graph = {
		{1},
		{0, 4, 2, 5},
		{1, 3},
		{2, 5},
		{1},
		{1, 3}
	};



	g.AddEdge(0, 1);
	g.AddEdge(0, 2);
	g.AddEdge(0, 5);
	g.AddEdge(2, 4);
	g.AddEdge(3, 0);
	g.AddEdge(4, 1);
	g.AddEdge(5, 5);

	// 방문한 정점을 저장하는 set
	unordered_set<int> visited;

	// DFS 탐색 시작
	dfs(graph, 0, visited);

	return 0;
}