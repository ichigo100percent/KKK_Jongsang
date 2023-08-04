#include <iostream>
#include <queue>
#include <vector>

int g_iCounter = 0;

class Node
{
public:
	int m_iIndex = -1;
	int m_iDepth = 0;
	Node* m_pParent = nullptr;
	std::vector<Node*> m_pChild;

	virtual Node* CreateNode()
	{
		return new Node(g_iCounter++);
	}
	virtual void CreateChildNode()
	{

	}
	virtual void SetParent(Node* pParent)
	{
		m_pParent = pParent;
		m_iDepth = pParent->m_iDepth + 1;
	}

	Node(int id)
		:m_iIndex(id)
	{

	}
	virtual ~Node(){}
};

class QuadTreeNode : public Node
{
public:
	virtual Node* CreateNode()
	{
		return new QuadTreeNode(g_iCounter++);
	}
	
	virtual void CreateChildNode()
	{
		for (int i = 0; i < 4; i++)
		{
			Node* pNewNode = CreateNode();
			pNewNode->SetParent(this);
			m_pChild.push_back(pNewNode);
			std::cout << pNewNode->m_iIndex << " ";
		}
	}

public:
	QuadTreeNode(int id)
		:Node(id)
	{

	}
	virtual ~QuadTreeNode()
	{
		for (int i = 0; i < m_pChild.size(); i++)
		{
			delete m_pChild[i];
		}
	}
};

class OctreeNode : public Node
{
public:
	virtual Node* CreateNode()
	{
		return new OctreeNode(g_iCounter++);
	}
	virtual void CreateChildNode()
	{
		for (int i = 0; i < 8; i++)
		{
			Node* pNewNode = CreateNode();
			pNewNode->SetParent(this);
			m_pChild.push_back(pNewNode);
			std::cout << pNewNode->m_iIndex << " ";
		}
	}

public:
	OctreeNode(int id)
		:Node(id)
	{

	}
	virtual ~OctreeNode()
	{
		for (int i = 0; i < m_pChild.size(); i++)
		{
			delete m_pChild[i];
		}
	}
};

Node* g_pRootNode = nullptr;

void AddNode(Node* pParent)
{
	if (pParent->m_iDepth > 1)
	{
		return;
	}
	pParent->CreateChildNode();
	
	for (int i = 0; i < pParent->m_pChild.size(); i++)
	{
		AddNode(pParent->m_pChild[i]);
	}
}

void BuildQuadTree()
{
	g_pRootNode = new QuadTreeNode(g_iCounter++);
	AddNode(g_pRootNode);
}

void BuildOcTree()
{
	g_pRootNode = new OctreeNode(g_iCounter++);
	AddNode(g_pRootNode);
}

std::queue<Node*> g_Queue;
void LevelOrder(Node* pNode)
{
	if (pNode == nullptr)
		return;

	std::cout << pNode->m_iIndex << " ";

	for (int i = 0; i < pNode->m_pChild.size(); i++)
	{
		if (pNode->m_pChild[i] != nullptr)
		{
			g_Queue.push(pNode->m_pChild[i]);
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
	BuildOcTree();

	std::cout << std::endl;

	LevelOrder(g_pRootNode);
}