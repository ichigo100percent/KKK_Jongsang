#include "QuadTree.h"

Node* QuadTree::FindNode(Node* pNode, Object* obj)
{
	if (pNode == nullptr) return nullptr;

	do
	{
		for (int i = 0; i < pNode->m_pChild.size(); i++)
		{
			if (pNode->m_pChild[i] != nullptr)
			{
				if (Collision::RectToPoint(pNode->m_pChild[i]->m_rt,
					obj->m_position))
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

	}while (pNode);

	return pNode;
}

Node* QuadTree::AddObject(Object* obj)
{
	Node* pFindNode = FindNode(g_pRootNode, obj);

	if (pFindNode != nullptr)
	{
		pFindNode->m_ObjectList.push_back(obj);
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

	/*
	0, 0,    800, 600


	v0--------vTc-------v1
	l                    l
	l                    l
	l                    l
   vLc        vC        vRc
	l                    l
	l                    l
	l                    l
	v3-------vBc---------v2
	*/

	Point vTc = { pNode->m_rt.m_Center.x, pNode->m_rt.m_Point[0].y };
	Point vRc = { pNode->m_rt.m_Point[1].x, pNode->m_rt.m_Center.y };
	Point vBc = { pNode->m_rt.m_Center.x, pNode->m_rt.m_Point[3].y };
	Point vLc = { pNode->m_rt.m_Point[0].x,pNode->m_rt.m_Center.y };

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
		<< pNode->m_rt.m_fy << ","
		<< pNode->m_rt.m_fWidth << ","
		<< pNode->m_rt.m_fHeight << std::endl;

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

void QuadTree::PreOrder(Node* pNode)
{
	if (pNode == nullptr)
		return;

	for (Node* data : pNode->m_pChild)
	{
		PreOrder(data);
	}
}

void QuadTree::PostOrder(Node* pNode)
{
	if (pNode == nullptr)
		return;

	for (Node* data : pNode->m_pChild)
	{
		PostOrder(data);
	}
}

void QuadTree::LevelOrder(Node* pNode)
{
	if (pNode == nullptr)
		return;

	std::wcout << L"[" << pNode->m_iDepth << L"]"
		<< pNode->m_rt.m_fx << L","
		<< pNode->m_rt.m_fy << L","
		<< pNode->m_rt.m_fWidth << L","
		<< pNode->m_rt.m_fHeight << L","
		<< pNode->m_ObjectList.size() << std::endl;

	for (int iobj = 0; iobj < pNode->m_ObjectList.size(); iobj++)
	{
		std::wcout << L"              " << L"<" << iobj << L">"
			<< pNode->m_ObjectList[iobj]->m_csName << L","
			<< pNode->m_ObjectList[iobj]->m_position.x << L","
			<< pNode->m_ObjectList[iobj]->m_position.y
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