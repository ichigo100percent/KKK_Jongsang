#include <iostream>
#include <vector>

using namespace std;

// **********************************
// https://sarah950716.tistory.com/12
// **********************************


//int main()
//{
//	vector<vector<int>> vec(4, vector<int>(4, 0));
//
//
//	vec[0] = { 0,0,1,1 };
//	vec[1] = { 1,0,1,1 };
//	vec[2] = { 0,1,0,0 };
//	vec[3] = { 0,0,0,0 };
//
//	int target = 1;
//
//	for (size_t i = 0; i < vec.size(); i++)
//	{
//		if (vec[target][i] != 0)
//		{
//			cout << i << "¹ø ";
//		}
//	}
//
//	return 0;
//}

/*
int main()
{
	vector<vector<pair<bool, int>>> matrix(5, vector<pair<bool, int>>(5, { false, 0 }));

	//matrix[1][0] = make_pair(true, 1);
	matrix[1][0] = { true, 1 };
	matrix[1][2] = { true, 1 };
	matrix[1][3] = { true, 2 };
	matrix[2][1] = { true, 2 };
	matrix[2][4] = { true, 4 };


	for (auto& i : matrix)
	{
		for (auto& j : i)
		{
			int n = j.first ? j.second : j.second;
			cout << n << " ";
		}
		cout << endl;
	}

	return 0;
}
*/


class Graph
{
public:
	Graph(int _vertices)
		: m_vertices(_vertices)
	{
		m_adjMatrix.resize(_vertices, vector<int>(_vertices, 0));
	}

	void addEdge(int _src, int _dest)
	{
		if (_dest > m_vertices - 1)
			return;

		if (_src > m_vertices - 1)
			return;

		m_adjMatrix[_src][_dest] = 1;
		//m_adjMatrix[_dest][_src] = 1;
	}

	void printAdjMatrix()
	{
		for (auto& i : m_adjMatrix)
		{
			for (auto& j : i)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}

private:
	int					m_vertices;
	vector<vector<int>> m_adjMatrix;
};

int main()
{
	Graph adjmatrix(4);

	adjmatrix.addEdge(1, 3);
	adjmatrix.addEdge(2, 1);
	adjmatrix.addEdge(6, 1);

	adjmatrix.printAdjMatrix();

}