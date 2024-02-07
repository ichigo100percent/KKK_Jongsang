#pragma once
#include "Entity.h"

namespace J
{
	//추상 클래스 메모리 할당X 상속받아서만 사용해야한다.
	class Resource : public Entity
	{
	public:
		Resource(enums::eResourceType _type);
		virtual ~Resource();

		//순수가상함수 실제메모리 할당이 불가능해지는 문법
		virtual HRESULT Load(const std::wstring& _path) = 0;
		const std::wstring& GetPath() { return m_Path; }
		void SetPath(const std::wstring& _path) { m_Path = _path; }

	private:
		const enums::eResourceType m_Type;
		std::wstring			   m_Path;
	};
}
