#include "QuadTree.h"

std::vector<Object*> StaticObjectList;
std::vector<Object*> DynamicObjectList;

void SetStaticObject(QuadTree& quadtree)
{
	for (int i = 0; i < 3; i++)
	{
		Object* obj = new StaticObject();
		obj->m_csName = L"StaticObj";
		obj->m_csName += std::to_wstring(i);
		obj->m_Position = { (float)(rand() % 800),(float)(rand() % 600) };
		quadtree.AddObject(obj);
		StaticObjectList.push_back(obj);
	}
}

void SetDynamicObject(QuadTree& quadtree)
{
	for (int i = 0; i < 3; i++)
	{
		Object* obj = new DynamicObject();

		obj->m_csName = L"DynamicObj";
		obj->m_csName += std::to_wstring(i);
		obj->m_Position = { (float)(rand() % 800), (float)(rand() % 600) };
		Point d = { (float)randstep(0, 0),
		(float)randstep(0, 0) };
		obj->SetTarget(d);
		quadtree.AddObject(obj);
		DynamicObjectList.push_back(obj);
	}
}

int main()
{
	QuadTree quadtree;
	quadtree.BuildQuadTree();
	SetStaticObject(quadtree);
	SetDynamicObject(quadtree);

	int iMaxFrame = 30;
	while (--iMaxFrame > 0)
	{
		for (int i = 0; i < DynamicObjectList.size(); i++)
		{
			Object* obj = DynamicObjectList[i];
			obj->Move();
		}
		system("cls");
		std::cout << std::endl;
		std::cout << "[" << iMaxFrame << "]" << "Object inform!\n";
		quadtree.LevelOrder(quadtree.GetRootNode());
		std::cout << "Hello World!\n";
		Sleep(2000);
	}

	for (int i = 0; i < StaticObjectList.size(); i++)
	{
		delete StaticObjectList[i];
	}

	StaticObjectList.clear();

	for (int i = 0; i < DynamicObjectList.size(); i++)
	{
		delete StaticObjectList[i];
	}

	DynamicObjectList.clear();
}