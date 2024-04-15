#pragma once
#include "JSGameObject.h"

namespace J
{


	class Goomba : public GameObject
	{
	public:
		Goomba();
		~Goomba();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

	private:

	};
}
