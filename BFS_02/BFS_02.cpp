#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#pragma region DFS 모든 여행경로 탐색
char value[10] = "ZADCEB";
int visitied[10] = {};
int map[6][6] =
{
	{0,1,1,1,0,0},
	{1,0,0,1,0,1},
	{1,0,0,1,0,0},
	{1,1,1,0,1,1},
	{0,0,0,1,0,1},
	{0,1,0,1,1,0}
};

int cnt = 0;
char path[10] = {};
bool flag = false;

void dfs(int now, int level)
{
	if (now == 5)
	{
		flag = true;
		cnt++;
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 6; i++)
	{
		if (map[now][i] == 1 && visitied[i] == 0)
		{
			visitied[i] = 1;
			path[level + 1] = value[i];
			dfs(i, level + 1);
			path[level + 1] = 0;
			visitied[i] = 0;
		}
	}
}

int main()
{
	visitied[0] = 1;
	path[0] = value[0];
	dfs(0, 0);

	return 0;
}
#pragma endregion

#pragma region BFS 모든 여행경로 탐색
struct Node
{
	int data;
	int level;
	int path[10] = {};
};

int map[5][5] =
{
	{0,1,0,1,0},
	{0,0,1,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,0},
};

queue<Node> q;
char value[10] = "BQWER";

int main()
{
	q.push({ 0,0,{1,0,0,0,0,0,0} });

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		if (value[now.data] == 'R')
		{
			for (int i = 0; i < 5; i++)
			{
				cout << now.path[i];
			}
			cout << endl;
		}

		for (int i = 0; i < 5; i++)
		{
			if (map[now.data][i] == 0)
				continue;
			if (now.path[i] == 1)
				continue;

			Node next = now;
			next.data = i;
			next.level = now.level + 1;
			next.path[i] = 1;

			q.push(next);
		}
	}

	return 0;
}
#pragma endregion


#pragma region DFS 최소 여행비용 찾기
vector<vector<int>> map
{
	{0,1,1,0,0,0,0},
	{0,0,0,1,0,1,0},
	{0,0,0,0,1,1,0},
	{0,0,0,0,0,1,0},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0},
};

vector<int> value{ 5,1,35,1,10,70,20 };
int visited[7] = { 1, };
int minValue = 987654321;
int path = { value[0], };

void dfs(int now, int sum, int level)
{
	if (now == 6)
	{
		if (minValue > sum)
		{
			minValue = sum;
		}
		return;
	}

	for (int i = 0; i < 7; i++)
	{
		if (map[now][i] == 0) continue;
		if (visited[i] == 1) continue;

		visited[i] = 1;
		dfs(i, sum + value[i], level + 1);
		visited[i] = 0;
	}
}


int main()
{
	dfs(0, value[0], 0);
	cout << minValue << endl;

	return 0;
}
#pragma endregion 

#pragma region BFS 최소 여행비용 찾기
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> map
{
	{0,1,1,0,0,0,0},
	{0,0,0,1,0,1,0},
	{0,0,0,0,1,1,0},
	{0,0,0,0,0,1,0},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0},
};

vector<int> value{ 5,1,35,1,10,70,20 };
int minValue = 987654321;
int path = { value[0], };

struct Node
{
	int num;
	int sum;
	int used[7];
};

std::queue<Node> q;

int main()
{
	q.push({ 0,value[0],{1,0,0,0,0,0,0} });

	while (!q.empty())
	{
		auto now = q.front();

		if (now.num == 6 && minValue > now.sum)
		{
			minValue = now.sum;
		}

		for (int i = 0; i < 7; i++)
		{
			if (map[now.num][i] == 0) continue;
			if (now.used[i] == 1) continue;

			Node next = now;
			next.num = i;
			next.sum += value[i];
			next.used[i] = 1;

			q.push(next);
		}
		q.pop();
	}

	cout << minValue << '\n';

	return 0;
}
#pragma endregion