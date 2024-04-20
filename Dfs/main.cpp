#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <time.h>

using namespace std;

void dfs(vector<vector<int>>& _adjmatrix, vector<bool>& _visited, int _start)
{
    int size = _adjmatrix[_start].size();
    _visited[_start] = true;

    cout << _start << " ";

    for (size_t i = 0; i < size; ++i)
    {
        if (_adjmatrix[_start][i] == 1 && !_visited[i])
            dfs(_adjmatrix, _visited, i);
    }
}


void dfstraversal(vector<vector<int>>& _adjmatrix)
{
    int size = _adjmatrix.size();
    vector<bool> visited(size, false);

    for (size_t i = 0; i < size; i++)
    {
        if (!visited[i])
            dfs(_adjmatrix, visited, i);
    }
}

void bfs(vector<vector<int>>& _adjmatrix, vector<bool>& _visited, int _start)
{
    queue<int> q;
    q.push(_start);
    _visited[_start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        cout << cur << " ";

        for (size_t i = 0; i < _adjmatrix[cur].size(); i++)
        {
            if (_adjmatrix[cur][i] == 1 && !_visited[i])
            {
                _visited[i] = true;
                q.push(i);
            }
        }
    }
}

void bfstraversal(vector<vector<int>>& _adjmatrix)
{
    int size = _adjmatrix.size();
    vector<bool> visited(size, false);

    for (size_t i = 0; i < size; i++)
    {
        if (!visited[i])
            bfs(_adjmatrix, visited, i);
    }
}

class Graph
{
public:
    Graph(int _vertices)
        : m_vertices(_vertices)
    {
        m_adjmatrix.resize(_vertices, vector<int>(m_vertices, 0));
    }

    void addEdge(int _src, int _dest)
    {
        if (_src > m_adjmatrix.size() - 1)
            return;
        if (_dest > m_adjmatrix.size() - 1)
            return;

        m_adjmatrix[_src][_dest] = 1;
        m_adjmatrix[_dest][_src] = 1;
    }

    void printAdjmatrix()
    {
        for (auto& i : m_adjmatrix)
        {
            for (auto& j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    vector<vector<int>> GetAdjmatrix() { return m_adjmatrix; }
    int GetVertices() { return m_vertices; }

private:
    int m_vertices;
    vector<vector<int>> m_adjmatrix;
};
int main()
{
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4); 
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    graph.printAdjmatrix();

    cout << "\n";

    auto adjmatrix = graph.GetAdjmatrix();

    cout << "DFS : ";
    dfstraversal(adjmatrix);

    cout << "\n";

    cout << "BFS : ";
    bfstraversal(adjmatrix);

    return 0;
}