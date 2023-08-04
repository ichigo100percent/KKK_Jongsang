#include <iostream>
#include <queue>


//바이너리 서치 트리

struct Node
{
	int m_value = -1;
	Node* m_leftChild = nullptr;
	Node* m_rightChild = nullptr;
	Node(int i)
		:m_value(i)
	{

	}
};

Node* g_RootNode = nullptr;

int g_Data[] = { 50,76,21,4,32,64,15,100,83,2,3,70,87,80 };
int g_Index = 0;

void AddNode(Node* pParentNode, Node* pNewNode)
{
	if (pParentNode->m_value >= pNewNode->m_value)
	{
		if (pParentNode->m_leftChild != nullptr)
		{
			AddNode(pParentNode->m_leftChild, pNewNode);
		}
		else
		{
			pParentNode->m_leftChild = pNewNode;
		}
	}
	else
	{
		if (pParentNode->m_rightChild != nullptr)
		{
			AddNode(pParentNode->m_rightChild, pNewNode);
		}
		else
		{
			pParentNode->m_rightChild = pNewNode;
		}
	}
}

void PreOrder(Node* pNode)
{
	if (pNode == nullptr)
		return;
	std::cout << pNode->m_value << " ";
	PreOrder(pNode->m_leftChild);
	PreOrder(pNode->m_rightChild);
}

void InOrder(Node* pNode)
{
	if (pNode == nullptr)
		return;
	
	PreOrder(pNode->m_leftChild);
	std::cout << pNode->m_value << " ";
	PreOrder(pNode->m_rightChild);
}

void PostOrder(Node* pNode)
{
	if (pNode == nullptr)
		return;

	PreOrder(pNode->m_leftChild);
	PreOrder(pNode->m_rightChild);
	std::cout << pNode->m_value << " ";
}


int main()
{
	g_RootNode = new Node(g_Data[g_Index++]);

	int cnt = _countof(g_Data);

	for (int i = 1; i < cnt; i++)
	{
		AddNode(g_RootNode, new Node(g_Data[g_Index++]));
	}

	PreOrder(g_RootNode);

	std::cout << std::endl;

	InOrder(g_RootNode);

	std::cout << std::endl;

	PostOrder(g_RootNode);
}