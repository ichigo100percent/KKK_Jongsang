#pragma once
#include "JSGameObject.h"

namespace J
{
	class Mario : public GameObject
	{
	public:
		Mario();
		~Mario();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
	private:

	};
}
