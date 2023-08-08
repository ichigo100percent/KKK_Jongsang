#include "Octree.h"
#include "Timer.h"
#include <map> // key+value   bst
#include <unordered_map> 
#include <queue>
using MyList = std::unordered_map<int, Object3D*>;
MyList StaticObjectList;
MyList DynamicObjectList;


void SetStaticObject(Octree& tree)
{
    if (tree.m_pRootNode == nullptr) return;

    int iMaxWidth = (int)tree.m_pRootNode->m_tBox.m_fWidth;
    int iMaxHeight = (int)tree.m_pRootNode->m_tBox.m_fHeight;
    int iMaxDepth = (int)tree.m_pRootNode->m_tBox.m_fDepth;
    for (int i = 0; i < 1000; i++)
    {
        Object3D* obj = new StaticObject3D();
        obj->m_csName = L"StaticObj";
        obj->m_csName += std::to_wstring(i);
        obj->m_Position = { (float)(rand() % iMaxWidth),
                            (float)(rand() % iMaxHeight),
                            (float)(rand() % iMaxDepth) };
        obj->SetBox(obj->m_Position,
            (float)((rand() % 10) + 1.0f),
            (float)((rand() % 10) + 1.0f),
            (float)((rand() % 10) + 1.0f));

        tree.StaticAddObject(obj);
        StaticObjectList.insert(std::make_pair(i, obj));
    }
}
void SetDynamicObject(Octree& tree)
{
    if (tree.m_pRootNode == nullptr) return;
    int iMaxWidth = (int)tree.m_pRootNode->m_tBox.m_fWidth;
    int iMaxHeight = (int)tree.m_pRootNode->m_tBox.m_fHeight;
    int iMaxDepth = (int)tree.m_pRootNode->m_tBox.m_fDepth;

    for (int i = 0; i < 10; i++)
    {
        Object3D* obj = new DynamicObject3D();

        obj->m_csName = L"DynamicObj";
        obj->m_csName += std::to_wstring(i);
        obj->m_Position = {
            (float)(rand() % iMaxWidth),
            (float)(rand() % iMaxHeight),
            (float)(rand() % iMaxDepth) };
        obj->SetBox(obj->m_Position,
            (float)((rand() % 10) + 1.0f),
            (float)((rand() % 10) + 1.0f),
            (float)((rand() % 10) + 1.0f));

        Vector3 d =   { (float)randstep(0, iMaxWidth),
                        (float)randstep(0, iMaxHeight),
                        (float)randstep(0, iMaxDepth) };
        obj->SetTarget(d);
        tree.DynamicAddObject(obj);
        DynamicObjectList.insert(std::make_pair(i, obj));
    }
}

int main()
{
    Octree tree;
    TSpaceData data;
    data.p3 = { 0,0,0 };
    data.w = 800;
    data.h = 600;
    data.z = 600;

    tree.BuildOctTree(data);

    SetStaticObject(tree);
    SetDynamicObject(tree);

    Timer  timer;
    timer.Init();

    while (1)
    {
        timer.Frame();
        tree.PreFrame();

        for (int i = 0; i < DynamicObjectList.size(); i++)
        {
            Object3D* obj = DynamicObjectList[i];
            obj->Move(timer.m_fSecondPerFrame);
            tree.DynamicAddObject(obj);
        }

        tree.Frame();
        tree.Render();

       // system("cls");
        std::cout << std::endl;
        std::cout << "Object inform!\n";
        for (int iObj = 0; iObj < DynamicObjectList.size(); iObj++)
        {
            std::cout << "Object[" << iObj << "]" <<
                    DynamicObjectList[iObj]->m_iNodeIndex << "   " <<
                (int)DynamicObjectList[iObj]->m_tBox.v.x <<  "   " <<
                (int)DynamicObjectList[iObj]->m_tBox.v.y <<  "   " <<
                (int)DynamicObjectList[iObj]->m_tBox.v.z
                << std::endl;
        }
        //tree.LevelOrder(tree.m_pRootNode);
        timer.Render();
        Sleep(1000);
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