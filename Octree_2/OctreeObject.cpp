#include "Octree.h"

Node* Octree::FindNode(Node* pNode, Object* obj)
{
	if (pNode == nullptr) return nullptr;

	do
	{
		for (int i = 0; i < pNode->m_pChild.size(); i++)
		{
			if (pNode->m_pChild[i] != nullptr)
			{
				if (Collision::RectToRect(
					pNode->m_pChild[i]->m_rt,
					obj->m_rt))
				{
					g_Queue.push(pNode->m_pChild[i]);
					break;
				}
			}
		}
		if (g_Queue.empty()) break;

		pNode = g_Queue.front();
		g_Queue.pop();

	} while (pNode);

	return pNode;
}

Node* Octree::StaticAddObject(Object* obj)
{
	Node* pFindNode = FindNode(m_pRootNode, obj);

	if (pFindNode != nullptr)
	{
		pFindNode->m_StaticObjectList.push_back(obj);
		return pFindNode;
	}

	return nullptr;
}

Node* Octree::DynamicAddObject(Object* obj)
{
	Node* pFindNode = FindNode(m_pRootNode, obj);
	if (pFindNode != nullptr)
	{
		pFindNode->m_DynamicObjectList.push_back(obj);
		m_DynamicObjectNodeList.insert(pFindNode);
		return pFindNode;
	}
	return nullptr;
}