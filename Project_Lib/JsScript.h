#pragma once
#include "Script.h"

namespace J
{
	class JsScript : public Script
	{
	public:
		JsScript();
		~JsScript();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
		bool Release() override;

	private:

	};
}