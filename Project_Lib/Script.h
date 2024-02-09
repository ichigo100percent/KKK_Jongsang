#pragma once
#include "Component.h"

namespace J
{
	class Script : public Component
	{
	public:
		Script();
		~Script();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
		bool Release() override;
	private:

	};
}
