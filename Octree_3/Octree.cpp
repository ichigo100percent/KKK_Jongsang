#include "Octree.h"

bool	Octree::Init()
{
    return true;
}
bool	Octree::PreFrame()
{
    // 力1规过(std::set)
    for (auto node : m_DynamicObjectNodeList)
    {
        node->m_DynamicObjectList3D.clear();
    }
    // 力2规过(犁蓖龋免 滚傈)
    //quadtree.PreOrder(m_pRootNode);

    // 力3规过( 硅凯 滚傈)
    /*for (int i=0; i < g_DynamicNodeList.size() ; i++)
    {
        m_NodeArrayList[i]->m_DynamicObjectList.clear();
    }*/

    m_DynamicObjectNodeList.clear();
    return true;
}
bool	Octree::Frame()
{
    return true;
}
bool	Octree::PostFrame()
{
    return true;
}
bool	Octree::Render()
{
    return true;
}
bool	Octree::Release()
{
    return true;
}




void Octree::PreOrder(Node* pNode)
{
    if (pNode == nullptr) return;
    pNode->m_DynamicObjectList3D.clear();
    for (Node* data : pNode->m_child)
    {
        PreOrder(data);
    }
}
void Octree::LevelOrder(Node* pNode)
{
    if (pNode == nullptr) return;
    std::wcout << L"[" << pNode->m_iDepth << L"]"
        << pNode->m_Box.v.x << L","
        << pNode->m_Box.v.y << L","
        << pNode->m_Box.v.z << L","
        << pNode->m_Box.m_fWidth << L","
        << pNode->m_Box.m_fHeight << L","
        << pNode->m_Box.m_fDepth << L","
        << pNode->m_StaticObjectList3D.size() << L","
        << pNode->m_DynamicObjectList3D.size() << std::endl;
    for (int iobj = 0; iobj < pNode->m_DynamicObjectList3D.size(); iobj++)
    {
        std::wcout << L"      " << L"<" << iobj << L">"
            << pNode->m_DynamicObjectList3D[iobj]->m_csName << L","
            << pNode->m_DynamicObjectList3D[iobj]->m_Position.x << L","
            << pNode->m_DynamicObjectList3D[iobj]->m_Position.y << L","
            << pNode->m_DynamicObjectList3D[iobj]->m_Position.z
            << std::endl;
    }
    for (int i = 0; i < pNode->m_child.size(); i++)
    {
        if (pNode->m_child[i] != nullptr)
        {
            g_Queue.push(pNode->m_child[i]);
        }
    }
    if (!g_Queue.empty())
    {
        Node* pNode = g_Queue.front();
        g_Queue.pop();
        LevelOrder(pNode);
    }
}

Octree::Octree()
{
}

Octree::~Octree()
{
    delete m_pRootNode;
}