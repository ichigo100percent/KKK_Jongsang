#pragma once
#include "Resource.h"

namespace J
{
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& _key)
		{
			auto iter = m_Resources.find(_key);
			if (iter == m_Resources.end())
				return nullptr;

			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& _key, const std::wstring _path)
		{
			T* resource = Resources::Find<T>(_key);
			if (resource != nullptr)
				return resource;

			resource = new T();
			if (FAILED(resource->Load(_path)))
				assert(false);

			resource->SetName(_key);
			resource->SetPath(_path);
			m_Resources.insert(std::make_pair(_key, resource));

			return resource;
		}

		static void Insert(const std::wstring& _key, Resource* _resource)
		{
			if (_key == L"")
				return;
			if (_resource == nullptr)
				return;

			m_Resources.insert(std::make_pair(_key, _resource));
		}

		static void Release()
		{
			for (auto& iter : m_Resources)
			{
				delete iter.second;
				iter.second = nullptr;
			}
		}
	private:
		static std::map<std::wstring, Resource*> m_Resources;
	};
}
