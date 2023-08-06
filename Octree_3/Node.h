#pragma once
#include "Object.h"

class Node
{
public:
	int							m_iIndex = -1;
	int							m_iDepth = 0;
	Rect						m_Rt;
	Box							m_Box;
	Node*						m_pParent = nullptr;
	std::vector<Node*>			m_child;
	std::vector<Object3D*>		m_StaticObjectList3D;
	std::vector<Object3D*>		m_DynamicObjectList3D;

public:
	void SetParent(Node* pParent);

public:
	Node(int td);
	Node();
	virtual ~Node();
};

struct SpaceData
{
	Vector2 p2;
	Vector3 p3;
	float w;
	float h;
	float z;
};