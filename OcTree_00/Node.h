#pragma once
#include "Object.h"

class Node
{
public:
    int                     m_iIndex = -1;
    int                     m_iDepth = 0;
    Rect                   m_tRT;
    Box                    m_tBox;
    Node* m_pParent = nullptr;
    std::vector<Node*>     m_pChild;
    std::vector<Object2D*>   m_StaticObjectList;
    std::vector<Object2D*>   m_DynamicObjectList;
    std::vector<Object3D*>   m_StaticObjectList3D;
    std::vector<Object3D*>   m_DynamicObjectList3D;
public:
    void   SetParent(Node* pParent);
public:
   Node(int id);
   Node();
    virtual ~Node();
};

struct TSpaceData
{
    Vector2 p2;
    Vector3 p3;
    float  w;
    float  h;
    float  z;
};