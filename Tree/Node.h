#pragma once
#include "Object.h"

class Node
{
public:
	Rect m_rt;
	int m_Depth = 0;
	Node* m_parent = nullptr;
	std::vector<Node*> m_child;
	std::vector<Object*> m_objectList;

public:
	void setParent(Node* pParent);
	Node(Node* pParent, float x, float y, float _w, float _h)
		:m_parent(pParent)
	{
		m_rt.Set(x, y, _w, _h);
		setParent(pParent);
	}
	~Node()
	{
		if (m_child.size() != 0)
		{
			delete m_child[0];
			delete m_child[1];
			delete m_child[2];
			delete m_child[3];
		}
	}
};