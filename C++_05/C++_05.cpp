#include "Timer.h"
#include "QuadTree.h"

std::vector<Object*> StaticObjectList;
std::vector<Object*> DynamicObjectList;

void SetStaticObject(QuadTree& quadtree)
{
	for (int i = 0; i < 10; i++)
	{
		Object* obj = new StaticObject();
		obj->m_csName = L"StaticOjb";
		obj->m_csName += std::to_wstring(i);
		obj->m_Position = { (float)(rand() % 800), (float)(rand() % 600) };

		obj->SetRect(obj->m_Position,
			(float)((rand() % 10) + 1.0f),
			(float)((rand() % 10) + 1.0f));

		quadtree.StaticAddObject(obj);
		StaticObjectList.push_back(obj);
	}
}

void SetDynamicObject(QuadTree& quadtree)
{
	for (int i = 0; i < 10; i++)
	{
		Object* obj = new DynamicObject();

		obj->m_csName = L"DynamicObj";
		obj->m_csName += std::to_wstring(i);
		obj->m_Position = { (float)(rand() % 800), (float)(rand() % 600) };
		obj->SetRect(obj->m_Position,
			(float)((rand() % 10) + 1.0f),
			(float)((rand() % 10) + 1.0f));

		Point d = { (float)randstep(0, 800),
					 (float)randstep(0, 600) };
		obj->SetTarget(d);
		quadtree.DynamicAddObject(obj);
		DynamicObjectList.push_back(obj);
	}
}

int main()
{
	Rect rt1, rt2;
	rt1.Set(Point(20, 20), 100, 100);
	rt2.Set(Point(50, 50), 100, 100);

	if (Collision::RectToRect(rt1, rt2))
	{
		std::cout << "collision" << std::endl;
	}
	std::cout << "no collision" << std::endl;

	QuadTree quadtree;
	quadtree.BuildQuadtree();

	SetStaticObject(quadtree);
	SetDynamicObject(quadtree);
	
	
	Timer timer;
	timer.Init();
	//프레임 고정 100프레임 float fStep = 1.0f / 50.0f;
	while (timer.m_fGameTimer < 1000.0f)
	{
		timer.Frame();
		quadtree.PreFrame();

		for (int i = 0; i < DynamicObjectList.size(); i++)
		{
			Object* obj = DynamicObjectList[i];
			obj->Move(timer.m_fSecondPerFrame);
			quadtree.DynamicAddObject(obj);
		}

		quadtree.Frame();
		quadtree.Render();

		system("cls");
		std::cout << std::endl;
		std::cout << "Object inform!\n";
		quadtree.LevelOrder(quadtree.GetRootNode());
		timer.Render();
		Sleep(100);
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

	quadtree.Release();
}