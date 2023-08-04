#include "QuadTree.h"

int main()
{
	QuadTree quadtree;

	quadtree.BuildQuadTree();

	std::vector<Object*> objectlist;

	for (int i = 0; i < 100; i++)
	{
		Object* obj = new Object();

		obj->m_csName = L"obj";
 		obj->m_csName += std::to_wstring(i);
		obj->m_position = { (float)(rand() % 800), float(rand() % 600) };

		quadtree.AddObject(obj);

		objectlist.push_back(obj);
	}

	std::cout << std::endl;
	std::cout << "Object inform!\n";
	quadtree.LevelOrder(quadtree.GetRootNode());
	std::cout << "hellow world\n";
}