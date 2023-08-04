#pragma once
#include "Object.h"

class Node
{
public:
	int m_iIndex;
	Rect m_rt;
	int m_iDepth = 0;
	Node* m_pParent = nullptr;

	std::vector<Node*> m_pChild;
	std::vector<Object*> m_StaticObjectList;
	std::vector<Object*> m_DynamicObjectList;

public:
	void SetParent(Node* pParent)
	{
		if (pParent == nullptr)
		{
			return;
		}
		m_pParent = pParent;
		m_iDepth = pParent->m_iDepth + 1;
	}
	Node(Node* pParent,
		float x,
		float y,
		float fWidth,
		float fHeight) :m_pParent(pParent)
	{
		m_rt.Set(x, y, fWidth, fHeight);
		SetParent(pParent);
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