#pragma once
#include "Node.h"

class Octree
{
public:
    Node* m_pRootNode = nullptr;
    int                 m_iNumNodeCounter = 0;
    std::set<Node*>    m_DynamicObjectNodeList;
    std::vector<Node*> m_NodeArrayList;

    // 공간을 분할 작업 

public:
    void            BuildOctTree(TSpaceData data);
    void            BuildTree(Node* pParent);
    Node* CreateNode(Node* pParent, TSpaceData data);
    Node* CreateNode(Node* pParent,
        float x, float y, float z,
        float w, float h, float d);

    // 객체를 공간에 추가하는 작업

public:
    Node* StaticAddObject(Object3D* obj);
    Node* DynamicAddObject(Object3D* obj);
    Node* FindNode(Node* pNode, Object3D* obj);

    // 분할 된 트리를 순회하는 작업

public:
    std::queue<Node*> g_Queue;
    void            PreOrder(Node* pNode);
    void            LevelOrder(Node* pNode);

    // 쿼드트리의 프로세스
  
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
