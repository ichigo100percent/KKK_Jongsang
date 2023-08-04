#include "QuadTree.h"

Node* QuadTree::FindNode(Node* pNode, Object* obj)
{
	if (pNode == nullptr)
		return nullptr;

	do
	{
		for (int i = 0; i < pNode->m_pChild.size(); i++)
		{
			if (pNode->m_pChild[i] != nullptr)
			{
				if (Collision::RectToPoint(pNode->m_pChild[i]->m_rt,
					obj->m_Position))
				{
					g_Queue.push(pNode->m_pChild[i]);
					break;
				}
			}
		}
		if (g_Queue.empty())
			break;
		pNode = g_Queue.front();
		g_Queue.pop();

	} while (pNode);

	return pNode;
}

Node* QuadTree::AddObject(Object* obj)
{
	Node* pFindNode = FindNode(g_pRootNode, obj);

	if (pFindNode != nullptr)
	{
		pFindNode->m_StaticObjectList.push_back(obj);
		return pFindNode;
	}

	return nullptr;
}

Node* QuadTree::GetRootNode()
{
	return g_pRootNode;
}

Node* QuadTree::CreateNode(Node* pParent, float x, float y, float w, float h)
{
	return new Node(pParent, x, y, w, h);
}

void QuadTree::BuildTree(Node* pNode)
{
	if (pNode->m_iDepth > 1)
	{
		return;
	}

	Point vTc = { pNode->m_rt.m_Center.x, pNode->m_rt.m_Point[0].y };
	Point vRc = { pNode->m_rt.m_Point[1].x, pNode->m_rt.m_Center.y };
	Point vBc = { pNode->m_rt.m_Center.x, pNode->m_rt.m_Point[3].y };
	Point vLc = { pNode->m_rt.m_Point[0].x , pNode->m_rt.m_Center.y };

	Node* pNewNode = CreateNode(pNode,
		pNode->m_rt.m_Point[0].x,
		pNode->m_rt.m_Point[0].y,
		pNode->m_rt.m_Half.x,
		pNode->m_rt.m_Half.y);
	pNode->m_pChild.push_back(pNewNode);

	pNewNode = CreateNode(pNode,
		vTc.x,
		vTc.y,
		pNode->m_rt.m_Half.x,
		pNode->m_rt.m_Half.y);
	pNode->m_pChild.push_back(pNewNode);

	pNewNode = CreateNode(pNode,
		pNode->m_rt.m_Center.x,
		pNode->m_rt.m_Center.y,
		pNode->m_rt.m_Half.x,
		pNode->m_rt.m_Half.y);
	pNode->m_pChild.push_back(pNewNode);

	pNewNode = CreateNode(pNode,
		vLc.x,
		vLc.y,
		pNode->m_rt.m_Half.x,
		pNode->m_rt.m_Half.y);
	pNode->m_pChild.push_back(pNewNode);

	std::cout << "[" << pNode->m_iDepth << "]"
		<< pNode->m_rt.m_fx << ","
		<< pNode->m_rt.m_fx << ","
		<< pNode->m_rt.m_w << ","
		<< pNode->m_rt.m_h << std::endl;

	for (int i = 0; i < pNode->m_pChild.size(); i++)
	{
		BuildTree(pNode->m_pChild[i]);
	}
}

void QuadTree::BuildQuadTree()
{
	g_pRootNode = new Node(nullptr, 0, 0, 800, 600);
	BuildTree(g_pRootNode);
}

void QuadTree::LevelOrder(Node* pNode)
{
	if (pNode == nullptr) return;

	std::wcout << L"[" << pNode->m_iDepth << L"]"
		<< pNode->m_rt.m_fx << L","
		<< pNode->m_rt.m_fx << L","
		<< pNode->m_rt.m_w << L","
		<< pNode->m_rt.m_h << L","
		<< pNode->m_StaticObjectList.size() << std::endl;

	for (int iobj = 0; iobj < pNode->m_StaticObjectList.size(); iobj++)
	{
		std::wcout << L"     " << L"<" << iobj << L">"
			<< pNode->m_StaticObjectList[iobj]->m_csName << L","
			<< pNode->m_StaticObjectList[iobj]->m_Position.x << L","
			<< pNode->m_StaticObjectList[iobj]->m_Position.y
			<< std::endl;
	}
	for (int i = 0; i < pNode->m_pChild.size(); i++)
	{
		if (pNode->m_pChild[i] != nullptr)
		{
			g_Queue.push(pNode->m_pChild[i]);
		}
	}
	if (!g_Queue.empty())
	{
		Node* pNode = g_Queue.front();
		g_Queue.pop();
		LevelOrder(pNode);
	}
}