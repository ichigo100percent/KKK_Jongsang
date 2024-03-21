#include "Scene.h"


namespace J
{
    Scene::Scene()
        :m_Layers{}
    {
        createLayers();
    }

    Scene::~Scene()
    {
        for (Layer* layer : m_Layers)
        {
            delete layer;
            layer = nullptr;
        }
    }

    bool Scene::Init()
    {
        for (auto layer : m_Layers)
        {
            if (layer == nullptr)
                continue;

            layer->Init();
        }

        return true;
    }

    bool Scene::Update()
    {
        for (auto layer : m_Layers)
        {
            if (layer == nullptr)
                continue;

            layer->Update();
        }

        return true;
    }

    bool Scene::LateUpdate()
    {
        for (auto layer : m_Layers)
        {
            if (layer == nullptr)
                continue;

            layer->LateUpdate();
        }
        return true;
    }

    bool Scene::Render(HDC _hdc)
    {
        for (auto layer : m_Layers)
        {
            if (layer == nullptr)
                continue;

            layer->Render(_hdc);
        }

        return true;
    }

    void Scene::Destroy()
    {
        for (auto layer : m_Layers)
        {
            if (layer == nullptr)
                continue;

            layer->Destroy();
        }
    }

    void Scene::OnEnter()
    {
    }

    void Scene::OnExit()
    {
    }

    void Scene::AddGameObject(GameObject* _gameObject, const enums::eLayerType _type)
    {
        m_Layers[(UINT)_type]->AddGameObject(_gameObject);
    }
    void Scene::EraseGameObejct(GameObject* _gameObject)
    {
        eLayerType layerType = _gameObject->GetLayerType();
        m_Layers[(UINT)layerType]->EraseGameObject(_gameObject);
    }
    void Scene::createLayers()
    {
        m_Layers.resize((UINT)enums::eLayerType::Max);

        for (int i = 0; i < (UINT)enums::eLayerType::Max; i++)
        {
            m_Layers[i] = new Layer();
        }
    }
}
