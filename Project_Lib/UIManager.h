#pragma once
#include "Std.h"
#include "UIBase.h"

namespace J
{
	using namespace enums;

	class UIManager
	{
	public:
		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC _hdc);
		static void OnLoad();
		static void OnComplete(UIBase* addUI);
		static void OnFail();

		static void Push(eUIType _type);
		static void Pop(eUIType _type);

	private:
		static std::unordered_map<eUIType, UIBase*> m_UIs;
		static std::stack<UIBase*> m_UIBases;
		static std::queue<eUIType> m_RequestUIQueue;
		static UIBase*			m_ActiveUI;
	};
}
