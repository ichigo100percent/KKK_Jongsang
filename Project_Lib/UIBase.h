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

		//ui가 로드 되었을때 초기화
		void Init();
		//ui가 활성화되면 호출되는 함수
		void Active();
		//ui가 비활성화되면 호출되는 함수
		void InActive();
		void Update();
		void LateUpdate();
		void Render(HDC _hdc);
		//ui가 사라질경우 호출되는 함수
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
