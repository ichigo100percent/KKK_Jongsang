#include "Octree.h"

Node* Octree::CreateNode(Node* pParent,
    float x, float y, float z,
    float w, float h, float d)
{
    Node* pNode = new Node(m_iNumNodeCounter++);
    pNode->SetParent(pParent);
    pNode->m_Box.Set(x, y, z, w, h, d);
    return pNode;
}
Node* Octree::CreateNode(Node* pParent, SpaceData data)
{
    Node* pNode = new Node(m_iNumNodeCounter++);
    pNode->SetParent(pParent);
    pNode->m_Box.Set(data.p3, data.w, data.h, data.z);
    return pNode;
}
void Octree::BuildTree(Node* pNode)
{
    if (pNode->m_iDepth > 1)
    {
        return;
    }
    // 0
    Vector3 vHalf = pNode->m_Box.m_Half;
    vHalf = vHalf * 0.5f;
    Node* pNewNode = CreateNode(pNode,
        pNode->m_Box.m_Center.x - vHalf.x,
        pNode->m_Box.m_Center.y + vHalf.y,
        pNode->m_Box.m_Center.z - vHalf.z,
        pNode->m_Box.m_Half.x,
        pNode->m_Box.m_Half.y,
        pNode->m_Box.m_Half.z);

    pNode->m_child.push_back(pNewNode);
    m_NodeArrayList.push_back(pNode);
    // 1
    pNewNode = CreateNode(pNode,
        pNode->m_Box.m_Center.x + vHalf.x,
        pNode->m_Box.m_Center.y + vHalf.y,
        pNode->m_Box.m_Center.z - vHalf.z,
        pNode->m_Box.m_Half.x,
        pNode->m_Box.m_Half.y,
        pNode->m_Box.m_Half.z);
    pNode->m_child.push_back(pNewNode);
    m_NodeArrayList.push_back(pNode);
    //2
    pNewNode = CreateNode(pNode,
        pNode->m_Box.m_Center.x + vHalf.x,
        pNode->m_Box.m_Center.y - vHalf.y,
        pNode->m_Box.m_Center.z - vHalf.z,
        pNode->m_Box.m_Half.x,
        pNode->m_Box.m_Half.y,
        pNode->m_Box.m_Half.z);
    pNode->m_child.push_back(pNewNode);
    m_NodeArrayList.push_back(pNode);
    //3
    pNewNode = CreateNode(pNode,
        pNode->m_Box.m_Center.x - vHalf.x,
        pNode->m_Box.m_Center.y - vHalf.y,
        pNode->m_Box.m_Center.z - vHalf.z,
        pNode->m_Box.m_Half.x, pNode->m_Box.m_Half.y, pNode->m_Box.m_Half.z);
    pNode->m_child.push_back(pNewNode);
    m_NodeArrayList.push_back(pNode);

    // 4
    pNewNode = CreateNode(pNode,
        pNode->m_Box.m_Center.x - vHalf.x,
        pNode->m_Box.m_Center.y + vHalf.y,
        pNode->m_Box.m_Center.z + vHalf.z,
        pNode->m_Box.m_Half.x, pNode->m_Box.m_Half.y, pNode->m_Box.m_Half.z);

    pNode->m_child.push_back(pNewNode);
    m_NodeArrayList.push_back(pNode);
    // 5
    pNewNode = CreateNode(pNode,
        pNode->m_Box.m_Center.x + vHalf.x,
        pNode->m_Box.m_Center.y + vHalf.y,
        pNode->m_Box.m_Center.z + vHalf.z,
        pNode->m_Box.m_Half.x, pNode->m_Box.m_Half.y, pNode->m_Box.m_Half.z);
    pNode->m_child.push_back(pNewNode);
    m_NodeArrayList.push_back(pNode);
    //6
    pNewNode = CreateNode(pNode,
        pNode->m_Box.m_Center.x + vHalf.x,
        pNode->m_Box.m_Center.y - vHalf.y,
        pNode->m_Box.m_Center.z + vHalf.z,
        pNode->m_Box.m_Half.x,
        pNode->m_Box.m_Half.y,
        pNode->m_Box.m_Half.z);
    pNode->m_child.push_back(pNewNode);
    m_NodeArrayList.push_back(pNode);
    //7
    pNewNode = CreateNode(pNode,
        pNode->m_Box.m_Center.x - vHalf.x,
        pNode->m_Box.m_Center.y - vHalf.y,
        pNode->m_Box.m_Center.z + vHalf.z,
        pNode->m_Box.m_Half.x, pNode->m_Box.m_Half.y, pNode->m_Box.m_Half.z);
    pNode->m_child.push_back(pNewNode);
    m_NodeArrayList.push_back(pNode);

 /*   std::wcout << L"[" << pNode->m_iDepth << L"]"
        << pNode->m_Box.v.x << L","
        << pNode->m_Box.v.y << L","
        << pNode->m_Box.v.z << L","
        << pNode->m_Box.m_fWidth << L","
        << pNode->m_Box.m_fHeight << L","
        << pNode->m_Box.m_fDepth << std::endl;*/

    for (int i = 0; i < pNode->m_child.size(); i++)
    {
        BuildTree(pNode->m_child[i]);
    }
}
void Octree::BuildOctTree(
    SpaceData data)
{
    m_pRootNode = CreateNode(nullptr, data);
    BuildTree(m_pRootNode);
}
