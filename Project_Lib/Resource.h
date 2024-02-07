#pragma once
#include "Entity.h"

namespace J
{
	//�߻� Ŭ���� �޸� �Ҵ�X ��ӹ޾Ƽ��� ����ؾ��Ѵ�.
	class Resource : public Entity
	{
	public:
		Resource(enums::eResourceType _type);
		virtual ~Resource();

		//���������Լ� �����޸� �Ҵ��� �Ұ��������� ����
		virtual HRESULT Load(const std::wstring& _path) = 0;
		const std::wstring& GetPath() { return m_Path; }
		void SetPath(const std::wstring& _path) { m_Path = _path; }

	private:
		const enums::eResourceType m_Type;
		std::wstring			   m_Path;
	};
}
