#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <time.h>
#include <unordered_set>
#include <set>

using namespace std;

//******************************
//		인접행렬.ver
//******************************
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

//******************************
//		인접리스트.ver
//******************************

void dfs(vector<vector<int>>& _matrix, unordered_set<int>& _visited, int _src)
{
    if (_visited.find(_src) == _visited.end())
    {
        _visited.insert(_src);
        cout << _src << " ";
        for (auto& n : _matrix[_src])
        {
            dfs(_matrix, _visited, n);
        }
    }
}
void bfs(vector<vector<int>>& _matrix, unordered_set<int>& _visited, int _src)
{
    queue<int> q;
    q.push(_src);
    _visited.insert(_src);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (auto& n : _matrix[cur])
        {
            if (_visited.find(n) == _visited.end())
            {
                q.push(n);
                _visited.insert(n);
            }
        }
    }
}

/*
int main()
{

    vector<vector<int>> adjList(6);
    unordered_set<int> visited;

    adjList[0] = { 1,2 };
    adjList[1] = { 0,3,4 };
    adjList[2] = { 0,5 };
    adjList[3] = { 1 };
    adjList[4] = { 1 };
    adjList[5] = { 2 };

    dfs(adjList, visited, 0);
    visited.clear();
    cout << endl;
    bfs(adjList, visited, 0);
    return 0;

    return 0;
}
*/

/*
class adjList
{
public:
    adjList(int _size)
        : m_vertices(_size)
    {
        m_adjList.resize(m_vertices);
    }

    void addEdge(int _src, int _dest)
    {
        if (m_vertices <= _src || m_vertices <= _dest)
            return;

        m_adjList[_src].push_back(_dest);
    }

    void show()
    {
        int n = 0;
        for (auto& i : m_adjList)
        {
            cout << n << "행 ";
            for (auto& j : i)
            {
                cout << j << " ";
            }
            n++;
            cout << "\n";
        }
    }

    vector<vector<int>> GetAdjList() { return m_adjList; }
    int					GetVertices() { return m_vertices; }

private:
    vector<vector<int>> m_adjList;
    int					m_vertices;
};


void dfsList(vector<vector<int>>& _graph, set<int>& _visited, int _src)
{
    if (_visited.find(_src) == _visited.end())
    {
        _visited.insert(_src);
        cout << _src << " ";
        for (size_t i = 0; i < _graph[_src].size(); i++)
        {
            dfsList(_graph, _visited, _graph[_src][i]);
        }
    }
}

void bfsList(vector<vector<int>>& _graph, set<int> _visited, int _src)
{
    queue<int> q;
    q.push(_src);
    _visited.insert(_src);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (auto& i : _graph[cur])
        {
            if (_visited.find(i) == _visited.end())
            {
                q.push(i);
                _visited.insert(i);
            }
        }

        //for (size_t i = 0; i < _graph[cur].size(); i++)
        //{
        //	int n = _graph[cur][i];

        //	if (_visited.find(n) == _visited.end())
        //	{
        //		q.push(n);
        //		_visited.insert(n);
        //	}
        //}
    }
}

int main()
{
    adjList l(6);

    l.addEdge(0, 1);
    l.addEdge(0, 2);
    l.addEdge(1, 0);
    l.addEdge(1, 3);
    l.addEdge(1, 4);
    l.addEdge(2, 0);
    l.addEdge(2, 5);
    l.addEdge(3, 1);
    l.addEdge(4, 1);
    l.addEdge(5, 2);

    l.show();

    set<int> s;

    auto graph = l.GetAdjList();

    cout << "DFS 탐색 순서: ";
    dfsList(graph, s, 0);
    cout << "\n";
    s.clear();

    cout << "BFS 탐색 순서: ";
    bfsList(graph, s, 0);

    return 0;
}
*/



//리스트, 행렬 구현
//2024-05-02
/*
//013524 matrix
void dfsM(vector<vector<int>>& _g, vector<bool>& _b, int _s)
{
    if (!_b[_s])
    {
        _b[_s] = true;

        cout << _s << " ";

        for (size_t i = 0; i < _g[_s].size(); i++)
        {
            if (_g[_s][i])
            {
                dfsM(_g, _b, i);
            }
        }
    }
}
//list
void dfsL(vector<vector<int>>& _g, vector<bool>& _b, int _s)
{
    if (!_b[_s])
    {
        _b[_s] = true;
        cout << _s << " ";
        for (size_t i = 0; i < _g[_s].size(); i++)
        {
            dfsL(_g, _b, _g[_s][i]);
        }
    }
}


//012435 matrix
void bfsM(vector<vector<int>>& _g, vector<bool>& _b, int _s)
{
    queue<int> q;
    q.push(_s);
    _b[_s] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        cout << cur << " ";

        for (size_t i = 0; i < _g[cur].size(); i++)
        {
            if (!_b[i] && _g[cur][i] == 1)
            {
                q.push(i);
                _b[i] = true;
            }
        }
    }
}

//list
void bfsL(vector<vector<int>>& _g, vector<bool>& _b, int _s)
{
    queue<int> q;
    q.push(_s);
    _b[_s] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (size_t i = 0; i < _g[cur].size(); i++)
        {
            int find = _g[cur][i];
            if (!_b[find])
            {
                q.push(find);
                _b[find] = true;
            }
        }
    }
}


int main()
{
    //vector<vector<int>> g =
    //{
    //    {1,2,4},
    //    {0,3},
    //    {0},
    //    {1,5},
    //    {0},
    //    {3}
    //};

    vector<vector<int>> g =
    {
        {0,1,1,0,1,0},
        {1,0,0,1,0,0},
        {1,0,0,0,0,0},
        {0,1,0,0,0,1},
        {1,0,0,0,0,0},
        {0,0,0,1,0,0},
    };

    vector<bool> b(6, false);

    bfsM(g, b, 0);

    return 0;
}
*/


//2024-05-04
vector<vector<int>> graph = {};
set<int> visited = {};

void dfs1(int _start)
{
    if (visited.find(_start) == visited.end())
    {
        visited.insert(_start);
        cout << _start << " ";

        //for (auto& i : graph[_start])
        //{
        //    dfs1(i);
        //}

        for (size_t i = 0; i < graph[_start].size(); i++)
        {
            dfs1(graph[_start][i]);
        }
    }
}
void dfs2(int _start)
{
    if (visited.find(_start) == visited.end())
    {
        visited.insert(_start);
        cout << _start << " ";
        //int count = 0;
        //for (auto& i : graph[_start])
        //{
        //    if (i == 1)
        //    {
        //        dfs2(count);
        //    }
        //    count++;
        //}

        for (size_t i = 0; i < graph[_start].size(); i++)
        {
            if (graph[_start][i] == 1)
            {
                dfs2(i);
            }
        }
    }
}
void bfs1(int _start)
{
    queue<int> q;
    q.push(_start);
    visited.insert(_start);

    while (q.empty() == false)
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (auto& i : graph[cur])
        {
            if (visited.find(i) == visited.end())
            {
                q.push(i);
                visited.insert(i);
            }
        }
    }

}
void bfs2(int _start)
{
    queue<int> q;
    q.push(_start);
    visited.insert(_start);

    while (q.empty() == false)
    {
        int cur = q.front();
        q.pop();

        cout << cur << " ";

        //for (size_t i = 0; i < graph[cur].size(); i++)
        //{
        //    if (visited.find(i) == visited.end() && graph[cur][i])
        //    {
        //        q.push(i);
        //        visited.insert(i);
        //    }
        //}

        int count = 0;
        for (auto& i : graph[cur])
        {

            if (visited.find(count) == visited.end() && i == 1)
            {
                visited.insert(count);
                q.push(count);
            }
            count++;
        }
    }
}
int main()
{
    //graph =
    //{
    //    {1,2,4,},
    //    {0,3},
    //    {0},
    //    {1,5},
    //    {0},
    //    {3},
    //};

    graph =
    {
        {0,1,1,0,1,0},
        {1,0,0,1,0,0},
        {1,0,0,0,0,0},
        {0,1,0,0,0,1},
        {1,0,0,0,0,0},
        {0,0,0,1,0,0},
    };

    //dfs2(0);

    bfs2(0);

    return 0;
}