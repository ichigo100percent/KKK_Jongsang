#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


#pragma region BFS를 이용해서 맵길찾기(기본)
//vector<vector<int>> map(5, vector<int>(5, 0));
vector<string> map
{
	{"....."},
	{".###."},
	{".#..."},
	{".###."},
	{".#..."},
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n = map.size();

bool Check(int _x, int _y)
{
	return _x >= 0 && _x < n && _y >= 0 && _y < n && map[_x][_y] != '#';
}

void bfs(int _x, int _y)
{
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pair<int, int>> q;
	q.push(make_pair(_x, _y));
	visited[_x][_y] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int cX = cur.first;
		int cY = cur.second;

		if (cX == n - 1 && cY == n - 1)
		{
			cout << "목표지점 도착" << endl;
			return;
		}

		for (size_t i = 0; i < 4; i++)
		{
			int nX = cX + dx[i];
			int nY = cY + dy[i];

			if (Check(nY, nX) && !visited[nY][nX])
			{
				visited[nY][nX] = true;
				q.push(make_pair(nX, nY));
			}
		}
	}
	cout << "목표지점 도착하지 못하였습니다" << endl;
}

int main()
{

	bfs(0, 0);

	return 0;
}
#pragma endregion


#pragma region 거리비용 추가
vector<string> map
{
	{"....."},
	{"####."},
	{".###."},
	{".###."},
	{".###."},
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n = map.size();

bool Check(int _x, int _y)
{
	return _x >= 0 && _x < n && _y >= 0 && _y < n && map[_x][_y] != '#';
}

void bfs(int _x, int _y)
{
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(_x, _y, 1));
	visited[_x][_y] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int cX = get<0>(cur);
		int cY = get<1>(cur);
		int dist = get<2>(cur);
		if (cX == n - 1 && cY == n - 1)
		{
			cout << "목표지점 도착" << endl;
			cout << "비용 : " << dist << endl;
			return;
		}

		for (size_t i = 0; i < 4; i++)
		{
			int nX = cX + dx[i];
			int nY = cY + dy[i];

			if (Check(nY, nX) && !visited[nY][nX])
			{
				visited[nY][nX] = true;
				q.push(make_tuple(nX, nY, dist + 1));
			}
		}
	}
	cout << "목표지점 도착하지 못하였습니다" << endl;
}

int main()
{

	bfs(0, 0);
	return 0;
}
#pragma endregion


#pragma region 프로그래머스 게임 맵 최단거리 찾기
struct vec
{
	int x, y;
	vec(int _y, int _x) : y(_y), x(_x) {};
};

int solution(vector<vector<int> > maps)
{
	const int n = maps.size();
	const int m = maps[0].size();
	int dX[4] = { -1, 0, 1, 0 };
	int dY[4] = { 0, 1, 0, -1 };
	queue<vec> q;
	vector<vector<bool>> v(n, vector<bool>(m));
	vector<vector<int>> dist(n, vector<int>(m));
	auto check = [&](int _x, int _y)
		{ return _x >= 0 && _x < m && _y >= 0 && _y < n && maps[_y][_x] == 1 && !v[_y][_x]; };

	v[0][0] = true;
	q.push(vec(0, 0));
	dist[0][0] = 1;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int x = cur.x;
		int y = cur.y;


		for (int i = 0; i < 4; ++i)
		{
			int nX = x + dX[i];
			int nY = y + dY[i];

			// 조건체크
			//if (nX < 0 || nX >= m || nY < 0 || nY >= n)
			//	continue;
			//if (v[nY][nX])
			//	continue;
			//if (maps[nY][nX] == 0)
			//	continue;

			if (check(nX, nY))
			{
				q.push(vec(nY, nX));
				v[nY][nX] = true;
				dist[nY][nX] = dist[y][x] + 1;
			}
		}
	}

	if (!v[n - 1][m - 1])
		return -1;
	else
		return dist[n - 1][m - 1];
}

// 튜플사용
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>

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
#pragma endregion


#pragma region 백준 토마토

int m, n, h;
vector<vector<vector<int>>> map;

int dx[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { -1, 1, 0, 0, 0, 0 };

struct Pos
{
	int x, y, z;
	Pos(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

int bfs()
{
	int days = 0;
	queue<Pos> q;

	// 익은 토마토의 좌표를 큐에 추가
	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[k][i][j] == 1) {
					q.push(Pos(j, i, k));
				}
			}
		}
	}

	while (!q.empty())
	{
		int size = q.size();

		for (int i = 0; i < size; ++i)
		{
			Pos cur = q.front();
			q.pop();

			int x = cur.x;
			int y = cur.y;
			int z = cur.z;

			for (int j = 0; j < 6; ++j)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				int nz = z + dz[j];

				if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h && map[nz][ny][nx] == 0)
				{
					map[nz][ny][nx] = 1; // 익은 토마토로 변경
					q.push(Pos(nx, ny, nz));
				}
			}
		}

		if (!q.empty()) {
			days++;
		}
	}

	// 모든 토마토가 익지 않은 경우 확인
	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[k][i][j] == 0) {
					return -1; // 모든 토마토가 익지 않은 경우
				}
			}
		}
	}

	return days;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> h;

	map.resize(h, vector<vector<int>>(n, vector<int>(m)));

	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> map[k][i][j];
			}
		}
	}

	cout << bfs() << endl;

	return 0;
}
#pragma endregion


#pragma region 백준 맥주걷기

struct pos
{
	int x, y;
};

vector<pos> store(100);
vector<bool> v(100);
pos home;
pos festival;

bool bfs(int _n)
{
	queue<pos> q;
	q.push(home);

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int x = cur.x;
		int y = cur.y;

		if (abs(festival.x - x) + abs(festival.y - y) <= 1000) return true;

		for (int i = 0; i < _n; ++i)
		{
			if (abs(store[i].x - x) + abs(store[i].y - y) <= 1000 && !v[i])
			{
				v[i] = true;
				q.push(store[i]);
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;

	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		cin >> home.x >> home.y;
		for (int i = 0; i < n; i++)
		{
			cin >> store[i].x >> store[i].y;
		}
		cin >> festival.x >> festival.y;

		if (bfs(n))
			cout << "happy" << '\n';
		else
			cout << "sad" << "\n";

		fill(v.begin(), v.end(), false);
	}

	return 0;
}
#pragma endregion
