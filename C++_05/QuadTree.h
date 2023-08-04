#pragma once
#include "Node.h"

class QuadTree
{
public:
	std::queue<Node*> g_Queue;
	Node* g_pRootNode = nullptr;
	int m_iNumNodeCounter = 0;
	std::set<Node*> g_DynamicObjectNodeList;
	std::vector<Node*> g_DynamicNodeList;

public:
	Node* GetRootNode();

public:
	void Buildtree(Node* pNode);
	void BuildQuadtree();
	Node* CreateNode(Node* pParent, float x,
		float y,
		float fWidth,
		float fHeight);
	Node* StaticAddObject(Object* obj);
	Node* DynamicAddObject(Object* obj);
	Node* FindNode(Node* pNode, Object* obj);

public:
	void PreOrder(Node* pNode);
	void PostOrder(Node* pNode);
	void LevelOrder(Node* pNode);

public:
	bool	Init();		// �ʱ�ȭ �۾�
	bool	PreFrame();	// �ǽð� ���
	bool	Frame();	// �ǽð� ���
	bool	PostFrame();	// �ǽð� ���
	bool	Render();	// �ǽð� ������, ��ο�
	bool	Release();	// ��ü�� �Ҹ� �۾�
public:
	~QuadTree()
	{
		delete g_pRootNode;
	}
};