# include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <time.h>


using namespace std;

void Bfs(vector<vector<int>>& matrix, vector<bool>& visited, int start)
{
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (size_t i = 0; i < matrix[cur].size(); i++)
        {
            if (matrix[cur][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void Bfstraversal(vector<vector<int>>& matrix)
{
    int size = matrix.size();
    vector<bool> visited(size, false);

    for (size_t i = 0; i < size; i++)
    {
        if (!visited[i])
        {
            Bfs(matrix, visited, i);
        }
    }
}

int main()
{
    //행렬 생성
    vector<vector<int>> matrix(4, vector<int>(4, 0));

    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[0][3] = 1;
    matrix[1][2] = 1;
    matrix[3][2] = 1;


    //출력
    for (auto& i : matrix)
    {
        for (auto& j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    Bfstraversal(matrix);

    return 0;
}