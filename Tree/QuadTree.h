#pragma once
#include "Node.h"

class QuadTree
{
	std::queue<Node*> g_Queue;
	Node* g_pRootNode = nullptr;

public:
	Node* GetRootNode();

public:
	void Buildtree(Node* pNode);
	void BuildQuadtree();
	Node* CreateNode(Node* pParent, float _x, float _y, float _w, float _h);
	Node* AddObject(Object* obj);
	Node* FindNode(Node* pNode, Object* obj);

public:
	void PreOrder(Node* pNode);
	void PostOrder(Node* pNode);
	void LevelOrder(Node* pNode);

	~QuadTree()
	{
		delete g_pRootNode;
	}
};