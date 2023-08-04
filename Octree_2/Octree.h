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
	/// ����Ʈ���� ���μ���
	/// </summary>
public:
	bool	        Init();		// �ʱ�ȭ �۾�
	bool	        PreFrame();	// �ǽð� ���
	bool	        Frame();	// �ǽð� ���
	bool	        PostFrame();	// �ǽð� ���
	bool	        Render();	// �ǽð� ������, ��ο�
	bool	        Release();	// ��ü�� �Ҹ� �۾�
public:
	Octree();
	virtual ~Octree();
};