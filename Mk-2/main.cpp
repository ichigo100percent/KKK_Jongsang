#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
using namespace std;


int solution(vector<vector<int>> map) {
    int n = map.size();
    int m = map[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<tuple<int, int, int>> q;
    int dX[4] = { -1, 1, 0, 0 };
    int dY[4] = { 0, 0, -1, 1 };

    auto check = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && map[x][y] == 1;
        };

    visited[0][0] = true;
    q.push(make_tuple(0, 0, 1));

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int dist = get<2>(cur);

        if (x == n - 1 && y == m - 1) {
            return dist;
        }

        for (int i = 0; i < 4; ++i) {
            int nX = x + dX[i];
            int nY = y + dY[i];

            if (check(nX, nY) && !visited[nX][nY]) {
                q.push(make_tuple(nX, nY, dist + 1));
                visited[nX][nY] = true;
            }
        }
    }
    return -1;
}