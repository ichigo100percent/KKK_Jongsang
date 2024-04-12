#pragma once
#include "JSGameObject.h"

namespace J
{
	class Floor : public GameObject
	{
	public:
		Floor();
		~Floor();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
	private:

	};
}
