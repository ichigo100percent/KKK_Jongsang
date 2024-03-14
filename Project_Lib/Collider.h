#pragma once
#include "Component.h"

namespace J
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);

		virtual void OnCollisionEnter(Collider* _other);
		virtual void OnCollisionStay(Collider* _other);
		virtual void OnCollisionExit(Collider* _other);

		Vector2 GetOffset() { return m_Offset; }
		void SetOffset(Vector2 _offset) { m_Offset = _offset; }
		UINT32 GetID() { return m_ID; }
		Vector2 GetSize() { return m_Size; }
		void SetSize(Vector2 _size) { m_Size = _size; }

	private:
		static UINT CollisionID;

		UINT32 m_ID;
		Vector2 m_Offset;
		Vector2 m_Size;
	};
}
