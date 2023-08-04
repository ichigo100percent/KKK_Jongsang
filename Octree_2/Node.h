#pragma once
#include "Object.h"

class Node
{
public:
	int						m_iIndex = -1;
	int						m_iDepth = 0;
	Rect					m_rt;
	Node*					m_pParent = nullptr;
	std::vector<Node*>		m_pChild;
	std::vector<Object*>    m_StaticObjectList;
	std::vector<Object*>	m_DynamicObjectList;

public:
	void SetParent(Node* pParent);
public:
	Node(int id);
	Node();
	virtual ~Node();
};