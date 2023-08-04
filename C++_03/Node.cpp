#include "Node.h"

void Node::setParent(Node* pParent)
{
	if (pParent == nullptr) 
		return;
	m_pParent = pParent;
	m_iDepth = pParent->m_iDepth + 1;
}