#pragma once
#include "Object.h"

class Node
{
public:
	Rect m_rt;
	int m_iDepth = 0;
	Node* m_pParent = nullptr;
	std::vector<Node*> m_pChild;
	std::vector<Object*> m_ObjectList;

public:
	void setParent(Node* pParent);
	Node(Node* pParent, float _x, float _y, float _w, float _h)
		:m_pParent(pParent)
	{
		m_rt.Set(_x, _y, _w, _h);
		setParent(pParent);
	}
	~Node()
	{
		if (m_pChild.size() != 0)
		{
			delete m_pChild[0];
			delete m_pChild[1];
			delete m_pChild[2];
			delete m_pChild[3];
		}
	}
};