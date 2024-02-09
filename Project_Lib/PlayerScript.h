#pragma once
#include "Script.h"

namespace J
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
		bool Release() override;

	private:

	};
}
