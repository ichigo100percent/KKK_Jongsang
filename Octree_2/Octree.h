#pragma once
#include "Node.h"

class Octree
{
public:
	Node*				 m_pRootNode = nullptr;
	int					 m_iNumNodeCounter = 0;
	std::set<Node*>		 m_DynamicObjectNodeList;
	std::vector<Node*>	 m_NodeArrayList;

public:
	void BuildOctTree(float x, float y, float w, float h);
	void BuildTree(Node* pParent);
	Node* CreateNode(Node* pParent, float x,
		float y,
		float fWidth,
		float fHeight);

public:
	Node* StaticAddObject(Object* obj);
	Node* DynamicAddObject(Object* obj);
	Node* FindNode(Node* pNode, Object* obj);

public:
public:
	std::queue<Node*> g_Queue;
	void            PreOrder(Node* pNode);
	void            LevelOrder(Node* pNode);
	/// <summary>
	/// 쿼드트리의 프로세스
	/// </summary>
public:
	bool	        Init();		// 초기화 작업
	bool	        PreFrame();	// 실시간 계산
	bool	        Frame();	// 실시간 계산
	bool	        PostFrame();	// 실시간 계산
	bool	        Render();	// 실시간 랜더링, 드로우
	bool	        Release();	// 객체의 소멸 작업
public:
	Octree();
	virtual ~Octree();
};