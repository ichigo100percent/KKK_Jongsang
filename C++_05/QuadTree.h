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
	bool	Init();		// 초기화 작업
	bool	PreFrame();	// 실시간 계산
	bool	Frame();	// 실시간 계산
	bool	PostFrame();	// 실시간 계산
	bool	Render();	// 실시간 랜더링, 드로우
	bool	Release();	// 객체의 소멸 작업
public:
	~QuadTree()
	{
		delete g_pRootNode;
	}
};