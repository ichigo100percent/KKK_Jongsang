#include "Node.h"

void   Node::SetParent(Node* pParent)
{
    if (pParent == nullptr) return;
    m_pParent = pParent;
    m_iDepth = pParent->m_iDepth + 1;
}

Node::Node(int id) : m_iIndex(id) {}
Node::Node() {}
Node::~Node()
{
    for (int iChild = 0; iChild < m_pChild.size(); iChild++)
    {
        delete m_pChild[iChild];
        m_pChild[iChild] = nullptr;
    }
}