#pragma once
#include "Entity.h"

namespace J
{
	using namespace enums;

	class UIBase : public Entity
	{
	public:
		UIBase();
		virtual ~UIBase();

		//ui�� �ε� �Ǿ����� �ʱ�ȭ
		void Init();
		//ui�� Ȱ��ȭ�Ǹ� ȣ��Ǵ� �Լ�
		void Active();
		//ui�� ��Ȱ��ȭ�Ǹ� ȣ��Ǵ� �Լ�
		void InActive();
		void Update();
		void LateUpdate();
		void Render(HDC _hdc);
		//ui�� �������� ȣ��Ǵ� �Լ�
		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate();
		virtual void OnClear();

	private:
		eUIType m_Type;
		bool m_bFullScreen;
		bool m_bEnabled;
	};
}
