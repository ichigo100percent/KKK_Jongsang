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

    int iMaxWidth = (int)tree.m_pRootNode->m_Box.m_fWidth;
    int iMaxHeight = (int)tree.m_pRootNode->m_Box.m_fHeight;
    int iMaxDepth = (int)tree.m_pRootNode->m_Box.m_fDepth;
    for (int i = 0; i < 10; i++)
    {
        Object3D* obj = new StaticObject3D();
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
void SetDynamicObject(Octree& tree)
{
    if (tree.m_pRootNode == nullptr) return;
    int iMaxWidth = (int)tree.m_pRootNode->m_Box.m_fWidth;
    int iMaxHeight = (int)tree.m_pRootNode->m_Box.m_fHeight;
    int iMaxDepth = (int)tree.m_pRootNode->m_Box.m_fDepth;

    for (int i = 0; i < 10; i++)
    {
        Object3D* obj = new DynamicObject3D();

        obj->m_csName = L"DynamicObj";
        obj->m_csName += std::to_wstring(i);
        obj->m_Position = { (float)(rand() % iMaxWidth) - (iMaxWidth / 2.0f),
                           (float)(rand() % iMaxHeight) - (iMaxHeight / 2.0f),
                           (float)(rand() % iMaxDepth) - (iMaxDepth / 2.0f) };

        obj->SetBox(obj->m_Position,
            (float)((rand() % 10) + 1.0f),
            (float)((rand() % 10) + 1.0f),
            (float)((rand() % 10) + 1.0f));

        Vector3 d = { (float)randstep(-iMaxWidth / 2.0f, iMaxWidth / 2.0f),
                        (float)randstep(-iMaxWidth / 2.0f, iMaxHeight / 2.0f),
                        (float)randstep(-iMaxWidth / 2.0f, iMaxDepth / 2.0f) };
        obj->SetTarget(d);
        tree.DynamicAddObject(obj);
        DynamicObjectList.insert(std::make_pair(i, obj));
    }
}

int main()
{
    Octree tree;
    SpaceData data;
    data.p3 = { 0.0f,0.0f, 0.0f };
    data.w = g_fMapSize;
    data.h = g_fMapSize;
    data.z = g_fMapSize;

    tree.BuildOctTree(data);

    SetStaticObject(tree);
    SetDynamicObject(tree);

    Timer  timer;
    timer.Init();
    // 프레임 고정 100프레임    float fStep = 1.0f / 50.0f;
    //while (timer.m_fGameTimer < 1000.0f)
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

        //system("cls");
        std::cout << std::endl;
        std::cout << "Object inform!\n";
        for (int iObj = 0; iObj < DynamicObjectList.size(); iObj++)
        {
            std::cout << "Object[" << iObj << "]" <<
                DynamicObjectList[iObj]->m_iNodeIndex << std::endl;
        }
        //tree.LevelOrder(tree.m_pRootNode);
        timer.Render();
        //Sleep(100); // tick 1000 => 1초
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
