#pragma once
#include "Node.h"

class QuadTree
{
	std::queue<Node*> g_Queue;
	Node* g_pRootNode = nullptr;

public:
	Node* GetRootNode();

public:
	void BuildTree(Node* pNode);
	void BuildQuadTree();
	Node* CreateNode(Node* pParent, float x, float y, float w, float h);
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