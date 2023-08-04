#include <iostream>
#include <queue>
#include <vector>

using namespace std;


/*
  쿼드 트리
  전위 순회 
  후위 순회
  레벨 순회
 */

       
struct Node
{
	int m_value = -1;
	int m_depth = 0;

	Node* m_parent = nullptr;
	vector<Node*> m_childe;

	void SetParent(Node* pNode)
	{
		m_parent = pNode;
		m_depth = pNode->m_depth + 1;
	}
	Node(int i)
		:m_value(i)
	{

	}
};

int g_Counter = 0;
Node* g_RootNode = nullptr;

void AddNode(Node* pNode)
{
	if (pNode->m_depth > 2)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		Node* newNode = new Node(g_Counter++);
		newNode->SetParent(pNode);
		pNode->m_childe.push_back(newNode);
		cout << newNode->m_value << " ";
	}

	for (int i = 0; i < pNode->m_childe.size(); i++)
	{
		cout << "-";
		AddNode(pNode->m_childe[i]);
	}
}

void BuildQuadTree()
{
	g_RootNode = new Node(g_Counter++);
	AddNode(g_RootNode);
}

void PreOrder(Node* pNode)
{
	if (pNode == nullptr)
		return;
	
	cout << pNode->m_value << " ";
	for (Node* data : pNode->m_childe)
	{
		PreOrder(data);
	}
}

void PostOrder(Node* pNode)
{
	if (pNode == nullptr)
		return;

	for (Node* data : pNode->m_childe)
	{
		PostOrder(data);
	}
	cout << pNode->m_value << " ";
}

queue<Node*> g_Queue;
void LevelOrder(Node* pNode)
{
	if (pNode == nullptr)
		return;

	cout << pNode->m_value << " ";
	for (int i = 0; i < pNode->m_childe.size(); i++)
	{
		if (pNode->m_childe[i] != nullptr)
		{
			g_Queue.push(pNode->m_childe[i]);
		}
	}
	if (!g_Queue.empty())
	{
		Node* pNode = g_Queue.front();
		g_Queue.pop();
		LevelOrder(pNode);
	}
}

int main()
{
	BuildQuadTree();
	std::cout << std::endl;
	
	PreOrder(g_RootNode); std::cout << std::endl;
	PostOrder(g_RootNode); std::cout << std::endl;
	LevelOrder(g_RootNode);
}