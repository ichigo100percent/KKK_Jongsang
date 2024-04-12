#pragma once
#include "JSGameObject.h"

namespace J
{
	class Monster : public GameObject
	{
	public:
		Monster();
		~Monster();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

	private:

	};
}

