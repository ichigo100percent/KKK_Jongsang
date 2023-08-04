﻿#include "Math.h"

int g_counter = 0;

class Node 
{
public:
	int index = -1;
	int depth = 0;
	Node* parent = nullptr;
	std::vector<Node*> child;
	virtual Node* createNode()
	{
		return new Node(g_counter);
	}
	virtual void createChildNode()
	{

	}
	virtual void Setparent(Node* _parent)
	{
		parent = _parent;
		depth = _parent->depth + 1;
	}
	Node(int _index)
		:index(_index)
	{}
};

class Quadtree :public Node
{
public:
	virtual Node* createNode()
	{
		return new Quadtree(g_counter++);
	}

	virtual void createChildNode()
	{
		for (int i = 0; i < 4; i++)
		{
			Node* newNode = createNode();
			newNode->Setparent(this);
			child.push_back(newNode);
			std::cout << newNode->index << " ";
		}
	}
public:
	Quadtree(int _id)
		:Node(_id)	
	{

	}
		
};

Node* rootNode = nullptr;
void Add(Node* parent)
{
	if (parent->depth > 1)
	{
		return;
	}
	parent->createChildNode();

	for (int i = 0; i < parent->child.size(); i++)
	{
		Add(parent->child[i]);
	}
}

void build()
{
	rootNode = new Quadtree(g_counter++);
	Add(rootNode);
}

int main()
{
//#pragma region ->사이각 반환(180내의 작은값)
//	Vector3 x(1, 0, 0);
//	Vector3 z(0, 0, 1);
//	Vector3 y = (z ^ x); //up
//
//	float fDot1 = y | z;
//	float fDot2 = y | z;
//	float fDegree = z.Angle(x);
//#pragma endregion <-사이각 반환(180내의 작은값)
//#pragma region ->직선과 한점의 거리 반환
//	Ray ray;
//	ray.vPosition = { 0, 0, 0 };
//	ray.vDirection = { 10000, 0, 0 };
//	Vector3 p0(10, 0, -7);
//	float fDistance = ray.GetDistance(p0);
//#pragma endregion <-직선과 한점의 거리 반환
//#pragma region <-평면과 한점의 리
//	Plane plane1(Vector3(10, -10, 0), Vector3(1, 0, 0));
//	Plane plane2(Vector3(0, -10, 0), Vector3(0, -10, 10), Vector3(10, -10, 0));
//	Vector3 p1(20, 30, 40);
//
//	float f0 = plane1.GetDistance(p1);
//	float f1 = plane2.GetDistance(p1);
//#pragma endregion ->평면과 한점의 거리

	build();
}

/*
#include "TQuadtree.h"
#include "TOctree.h"
#include "TTimer.h"
#include <map> // key+value   bst
#include <unordered_map> 
#include <queue>
using MyList = std::unordered_map<int, TObject3D*>;
MyList StaticObjectList;
MyList DynamicObjectList;

void SetStaticObject(TOctree& tree)
{
    if (tree.m_pRootNode == nullptr) return;

    int iMaxWidth = tree.m_pRootNode->m_tBox.m_fWidth;
    int iMaxHeight = tree.m_pRootNode->m_tBox.m_fHeight;
    int iMaxDepth = tree.m_pRootNode->m_tBox.m_fDepth;
    for (int i = 0; i < 10; i++)
    {
        TObject3D* obj = new TStaticObject3D();
        obj->m_csName = L"StaticObj";
        obj->m_csName += std::to_wstring(i);
        obj->m_Position = { (float)(rand() % iMaxWidth) - (iMaxWidth / 2.0f),
                            (float)(rand() % iMaxHeight) - (iMaxHeight / 2.0f),
                            (float)(rand() % iMaxDepth) - (iMaxDepth / 2.0f) };
        obj->SetBox(obj->m_Position,
            (float)((rand() % 10) + 1.0f),
            (float)((rand() % 10) + 1.0f),
            (float)((rand() % 10) + 1.0f));

        tree.StaticAddObject(obj);
        StaticObjectList.insert(std::make_pair(i, obj));
    }
}
void SetDynamicObject(TOctree& tree)
{
    if (tree.m_pRootNode == nullptr) return;
    int iMaxWidth = tree.m_pRootNode->m_tBox.m_fWidth;
    int iMaxHeight = tree.m_pRootNode->m_tBox.m_fHeight;
    int iMaxDepth = tree.m_pRootNode->m_tBox.m_fDepth;

    for (int i = 0; i < 10; i++)
    {
        TObject3D* obj = new TDynamicObject3D();

        obj->m_csName = L"DynamicObj";
        obj->m_csName += std::to_wstring(i);
        obj->m_Position = { (float)(rand() % iMaxWidth) - (iMaxWidth / 2.0f),
                           (float)(rand() % iMaxHeight) - (iMaxHeight / 2.0f),
                           (float)(rand() % iMaxDepth) - (iMaxDepth / 2.0f) };

        obj->SetBox(obj->m_Position,
            (float)((rand() % 10) + 1.0f),
            (float)((rand() % 10) + 1.0f),
            (float)((rand() % 10) + 1.0f));

        TVector3 d = { (float)randstep(-iMaxWidth / 2.0f, iMaxWidth / 2.0f),
                        (float)randstep(-iMaxWidth / 2.0f, iMaxHeight / 2.0f),
                        (float)randstep(-iMaxWidth / 2.0f, iMaxDepth / 2.0f) };
        obj->SetTarget(d);
        tree.DynamicAddObject(obj);
        DynamicObjectList.insert(std::make_pair(i, obj));
    }
}

int main()
{
    TOctree tree;
    TSpaceData data;
    data.p3 = { 0.0f,0.0f, 0.0f };
    data.w = 1000;
    data.h = 1000;
    data.z = 1000;

    tree.BuildOctTree(data);

    SetStaticObject(tree);
    SetDynamicObject(tree);

    TTimer  timer;
    timer.Init();
    // 프레임 고정 100프레임    float fStep = 1.0f / 50.0f;
    //while (timer.m_fGameTimer < 1000.0f)
    while (timer.m_fGameTimer < 1000.0f)
    {
        timer.Frame();
        tree.PreFrame();

        for (int i = 0; i < DynamicObjectList.size(); i++)
        {
            TObject3D* obj = DynamicObjectList[i];
            obj->Move(timer.m_fSecondPerFrame);
            tree.DynamicAddObject(obj);
        }

        tree.Frame();
        tree.Render();

        system("cls");
        std::cout << std::endl;
        std::cout << "Object inform!\n";
        for (int iObj = 0; iObj < DynamicObjectList.size(); iObj++)
        {
            std::cout << "Object[" << iObj << "]" <<
                DynamicObjectList[iObj]->m_iNodeIndex << std::endl;
        }
        //tree.LevelOrder(tree.m_pRootNode);
        timer.Render();
        Sleep(100); // tick 1000 => 1초
    }
    timer.Release();

    for (int i = 0; i < StaticObjectList.size(); i++)
    {
        delete StaticObjectList[i];
    }
    StaticObjectList.clear();
    for (int i = 0; i < DynamicObjectList.size(); i++)
    {
        delete DynamicObjectList[i];
    }
    DynamicObjectList.clear();

    tree.Release();
}
*/