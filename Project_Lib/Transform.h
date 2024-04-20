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

		// 이전 위치 설정 함수
		void SetPreviousPosition(Vector2 _prevPos)
		{
			m_PreviousPosition = _prevPos;
		}

		// 이전 위치 반환 함수
		Vector2 GetPreviousPosition() const
		{
			return m_PreviousPosition;
		}

		Vector2 GetPosition() { return m_Position; }
		Vector2 GetScale() { return m_Scale; }
		float   GetRotation() { return m_Rotation; }


	private:
		Vector2		m_Position;
		Vector2     m_Scale;
		float       m_Rotation;

		// 이전 위치 저장 변수
		Vector2     m_PreviousPosition;
	};
}
