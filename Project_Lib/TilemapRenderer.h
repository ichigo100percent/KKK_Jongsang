#pragma once
#include "Entity.h"
#include "Component.h"
#include "Texture.h"

namespace J
{
	class TilemapRenderer : public Component
	{
	public:
		TilemapRenderer();
		~TilemapRenderer();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

		void SetTexture(graphics::Texture* _texture) { m_Texture = _texture; }
		void SetSize(math::Vector2 _size) { m_Size = _size; }

	private:
		Vector2				m_TileSize;
		graphics::Texture*	m_Texture;
		Vector2				m_Size;
		Vector2				m_Index;
	};
}
