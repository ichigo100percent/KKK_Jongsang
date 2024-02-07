#pragma once
#include "Entity.h"
#include "Component.h"
#include "Texture.h"

namespace J
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		 bool Init() override;
		 bool Update() override;
		 bool LateUpdate() override;
		 bool Render(HDC _hdc) override;
		 bool Release() override;

		 void SetTexture(graphics::Texture* _texture) { m_Texture = _texture; }
		 void SetSize(math::Vector2 _size) { m_Size = _size; }
		 
	private:
		graphics::Texture* m_Texture;
		math::Vector2	   m_Size;
	};
}
