#include "Scene.h"


namespace J
{
    Scene::Scene()
        :m_Layer{}
    {
        CreateLayers();
    }

    Scene::~Scene()
    {

    }

    bool Scene::Init()
    {
        for (auto layer : m_Layer)
        {
            if (layer == nullptr)
                continue;

            layer->Init();
        }

        return true;
    }

    bool Scene::Update()
    {
        for (auto layer : m_Layer)
        {
            if (layer == nullptr)
                continue;

            layer->Update();
        }

        return true;
    }

    bool Scene::LateUpdate()
    {
        for (auto layer : m_Layer)
        {
            if (layer == nullptr)
                continue;

            layer->LateUpdate();
        }
        return true;
    }

    bool Scene::Render(HDC _hdc)
    {
        for (auto layer : m_Layer)
        {
            if (layer == nullptr)
                continue;

            layer->Render(_hdc);
        }

        return true;
    }

    bool Scene::Release()
    {

        for (auto layer : m_Layer)
        {
            if (layer == nullptr)
                continue;

            layer->Release();
        }

        return true;
    }

    void Scene::OnEnter()
    {
    }

    void Scene::OnExit()
    {
    }

    void Scene::AddGameObject(GameObject* _gameObject, const eLayerType _type)
    {
        m_Layer[(UINT)_type]->AddGameObject(_gameObject);
    }
    void Scene::CreateLayers()
    {
        m_Layer.resize((UINT)eLayerType::Max);

        for (int i = 0; i < (UINT)eLayerType::Max; i++)
        {
            m_Layer[i] = new Layer();
        }
    }
}
