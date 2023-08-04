#include "Node.h"


void Node::setParent(Node* pParent)
{
	if (pParent == nullptr)
		return;

	m_parent = pParent;
	m_Depth = pParent->m_Depth + 1;
}