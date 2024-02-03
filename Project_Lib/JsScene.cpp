//#include "Scene.h"
//
//
//namespace J
//{
//    Scene::Scene()
//        :m_GameObjects{}
//    {
//
//    }
//
//    Scene::~Scene()
//    {
//
//    }
//
//    bool Scene::Init()
//    {
//        return true;
//    }
//
//    bool Scene::Update()
//    {
//        for (auto gameObj : m_GameObjects)
//        {
//            gameObj->Update();
//        }
//
//        return true;
//    }
//
//    bool Scene::LateUpdate()
//    {
//        return true;
//    }
//
//    bool Scene::Render(HDC _hdc)
//    {
//        for (auto gameObj : m_GameObjects)
//        {
//            gameObj->Render(_hdc);
//        }
//
//        return true;
//    }
//
//    bool Scene::Release()
//    {
//        return true;
//    }
//
//    void Scene::AddGameObject(GameObject* _gameObject)
//    {
//        m_GameObjects.push_back(_gameObject);
//    }
//}