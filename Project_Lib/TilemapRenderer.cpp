#include "TilemapRenderer.h"
#include "JSGameObject.h"
#include "Transform.h"
#include "Texture.h"
#include "Renderer.h"

namespace J
{
	Vector2 TilemapRenderer::TileSize = Vector2::One;
	Vector2	TilemapRenderer::OriginTileSize = Vector2::One;
	Vector2 TilemapRenderer::SelectedIndex = Vector2::One;

	TilemapRenderer::TilemapRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, m_Texture(nullptr)
		, m_Size(3.0f, 3.0f)
		, m_Index(0, 0)
		, m_TileSize(16.0f, 16.0f)
	{
		TileSize = m_TileSize * m_Size;
		OriginTileSize = m_TileSize;
	}
	TilemapRenderer::~TilemapRenderer()
	{
	}
	bool TilemapRenderer::Init()
	{
		return true;
	}
	bool TilemapRenderer::Update()
	{
		return true;
	}
	bool TilemapRenderer::LateUpdate()
	{
		return true;
	}
	bool TilemapRenderer::Render(HDC _hdc)
	{
		if (m_Texture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CalculatePosition(pos);

		if (m_Texture->GetTextureType()
			== graphics::Texture::eTextureType::Bmp)
		{
			if (m_Texture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(_hdc
					, pos.x, pos.y
					, m_TileSize.x * m_Size.x * scale.x
					, m_TileSize.y * m_Size.y * scale.y
					, m_Texture->GetHdc()
					, m_Index.x * m_TileSize.x
					, m_Index.y * m_TileSize.y
					, m_TileSize.x
					, m_TileSize.y
					, func);
			}
			else
			{
				//https://blog.naver.com/power2845/50147965306
				TransparentBlt(_hdc
					, pos.x, pos.y
					, m_TileSize.x * m_Size.x * scale.x
					, m_TileSize.y * m_Size.y * scale.y
					, m_Texture->GetHdc()
					, m_Index.x * m_TileSize.x
					, m_Index.y * m_TileSize.y
					, m_TileSize.x
					, m_TileSize.y
					, RGB(255, 0, 255));
			}
		}

		return true;
	}
}