#include "QuadTree.h"

bool QuadTree::Init()
{
	return true;
}

bool QuadTree::PreFrame()
{
	for (auto node : g_DynamicObjectNodeList)
	{
		node->m_DynamicObjectList.clear();
	}

	g_DynamicObjectNodeList.clear();
	return true;
}

bool QuadTree::Frame()
{
	return true;
}

bool QuadTree::PostFrame()
{
	return true;
}

bool QuadTree::Render()
{
	return true;
}

bool QuadTree::Release()
{
	return true;
}

Node* QuadTree::FindNode(Node* pNode, Object* obj)
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

Node* QuadTree::StaticAddObject(Object* obj)
{
	Node* pFindNode = FindNode(g_pRootNode, obj);

	if (pFindNode != nullptr)
	{
		pFindNode->m_StaticObjectList.push_back(obj);
		return pFindNode;
	}
	return nullptr;
}

Node* QuadTree::DynamicAddObject(Object* obj)
{
	Node* pFindNode = FindNode(g_pRootNode, obj);
	if (pFindNode != nullptr)
	{
		pFindNode->m_DynamicObjectList.push_back(obj);
		g_DynamicObjectNodeList.insert(pFindNode);
		return pFindNode;
	}

	return nullptr;
}

Node* QuadTree::GetRootNode()
{
	return g_pRootNode;
}

Node* QuadTree::CreateNode(Node* pParent, float x,
	float y, float fWidth, float fHight)
{
	Node* pNode = new Node(pParent, x, y, fWidth, fHight);
	pNode->m_iIndex = m_iNumNodeCounter++;
	g_DynamicNodeList.push_back(pNode);

	return pNode;
}

void QuadTree::Buildtree(Node* pNode)
{
	if (pNode->m_iDepth > 1)
		return;

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
		<< pNode->m_rt.m_fHight << std::endl;

	for (int i = 0; i < pNode->m_pChild.size(); i++)
	{
		Buildtree(pNode->m_pChild[i]);
	}
}

void QuadTree::BuildQuadtree()
{
	g_pRootNode = new Node(nullptr, 0, 0, 800, 600);
	Buildtree(g_pRootNode);
}

void QuadTree::LevelOrder(Node* pNode)
{
	if (pNode == nullptr)
		return;

	//std::wcout << L"[" << pNode->m_iDepth << L"]"
	//	<< pNode->m_rt.m_fx << L","
	//	<< pNode->m_rt.m_fy << L","
	//	<< pNode->m_rt.m_fWidth << L","
	//	<< pNode->m_rt.m_fHight << L","
	//	<< pNode->m_DynamicObjectList.size() << std::endl;

	for (int iobj = 0; iobj < pNode->m_DynamicObjectList.size(); iobj++)
	{
		std::wcout << L"      " << L"<" << iobj << L">"
			<< pNode->m_DynamicObjectList[iobj]->m_csName << L","
			<< pNode->m_DynamicObjectList[iobj]->m_Position.x << L","
			<< pNode->m_DynamicObjectList[iobj]->m_Position.y
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