#include <iostream>
#include <functional>
#include <vector>
#include <bitset>
#include <memory>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string_view>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
#pragma warning(disable: 4996)

void BFS(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < graph.size(); ++i) {
            if (graph[current][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0}
    };

    cout << "BFS traversal starting from node 0: ";
    BFS(graph, 0);
    cout << endl;

    return 0;
}