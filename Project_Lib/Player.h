#pragma once
#include "JSGameObject.h"

namespace J
{
	class Player : public GameObject
	{
	public:
		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
		bool Release() override;

	private:

	};
}