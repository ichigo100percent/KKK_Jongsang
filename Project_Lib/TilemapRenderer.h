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
		void SetIndex(Vector2 _index) { m_Index = _index; }
		Vector2 GetIndex() { return m_Index; }

	public:
		static Vector2		TileSize;
		static Vector2		OriginTileSize;
		static Vector2		SelectedIndex;

	private:
		Vector2				m_TileSize;
		graphics::Texture*	m_Texture;
		Vector2				m_Size;
		Vector2				m_Index;
	};
}
