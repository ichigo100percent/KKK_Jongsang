#pragma once
#include "Node.h"

class Octree
{
public:
	Node*		 m_pRootNode = nullptr;
	int			 m_iNumNodeCounter = 0;
    std::set<Node*>    m_DynamicObjectNodeList;
    std::vector<Node*> m_NodeArrayList;
    /// <summary>
    /// ������ ���� �۾� 
    /// </summary>
public:
    void            BuildOctTree(SpaceData data);
    void            BuildTree(Node* pParent);
    Node* CreateNode(Node* pParent, SpaceData data);
    Node* CreateNode(Node* pParent,
        float x, float y, float z,
        float w, float h, float d);
    /// <summary>
    /// ��ü�� ������ �߰��ϴ� �۾�
    /// </summary>
public:
    Node* StaticAddObject(Object3D* obj);
    Node* DynamicAddObject(Object3D* obj);
    Node* FindNode(Node* pNode, Object3D* obj);
    /// <summary>
    /// ���� �� Ʈ���� ��ȸ�ϴ� �۾�
    /// </summary>
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