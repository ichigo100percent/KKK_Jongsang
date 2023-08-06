#include "Octree.h"

Node* Octree::FindNode(Node* pNode, Object3D* obj)
{
    if (pNode == nullptr) 
        return nullptr;

    do
    {
        for (int i = 0; i < pNode->m_child.size(); i++)
        {
            if (pNode->m_child[i] != nullptr)
            {
                //todo
                CollisionType ret = TCollision::BoxToBox(
                    pNode->m_child[i]->m_Box,
                    obj->m_Box);
                if (ret == A_DestBig)
                {
                    g_Queue.push(pNode->m_child[i]);
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
Node* Octree::StaticAddObject(Object3D* obj)
{
    Node* pFindNode = FindNode(m_pRootNode, obj);
    if (pFindNode != nullptr)
    {
        obj->m_iNodeIndex = pFindNode->m_iIndex;
        pFindNode->m_StaticObjectList3D.push_back(obj);
        return pFindNode;
    }
    return nullptr;
}
Node* Octree::DynamicAddObject(Object3D* obj)
{
    Node* pFindNode = FindNode(m_pRootNode, obj);
    if (pFindNode != nullptr)
    {
        obj->m_iNodeIndex = pFindNode->m_iIndex;
        pFindNode->m_DynamicObjectList3D.push_back(obj);
        m_DynamicObjectNodeList.insert(pFindNode);
        return pFindNode;
    }
    return nullptr;
}
