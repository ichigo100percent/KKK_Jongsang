#pragma once
#include "Script.h"

namespace J
{


	class GoombaScript : public Script
	{
	public:
		GoombaScript();
		~GoombaScript();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
	};
}
