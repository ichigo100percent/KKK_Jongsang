#pragma once
#include "Script.h"
#include "Transform.h"

namespace J
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

	private:
	};
}
