#pragma once
#include "Component.h"

namespace J
{
	using namespace J::math;

	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 _pos) { return _pos - m_Distance; }

		Camera();
		~Camera();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
		bool Release() override;

	private:
		class GameObject* m_Target;
		Vector2 m_Distance;
		Vector2 m_Resolution;
		Vector2 m_LookPosition;
	};
}
