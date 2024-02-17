#pragma once
#include "Entity.h"
#include "Component.h"

namespace J
{
	using namespace math;

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
		bool Release() override;

		void SetPosition(Vector2 _pos)
		{
			m_Position.x = _pos.x;
			m_Position.y = _pos.y;
		}
		void SetScale(Vector2 _scale)
		{
			m_Scale = _scale;
		}
		void SetRotation(float _rotation)
		{
			m_Rotation = _rotation;
		}

		Vector2 GetPosition() { return m_Position; }
		Vector2 GetScale() { return m_Scale; }
		float   GetRotation() { return m_Rotation; }


	private:
		Vector2		m_Position;
		Vector2     m_Scale;
		float       m_Rotation;
	};
}
