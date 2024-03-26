#include "TilemapRenderer.h"
#include "JSGameObject.h"
#include "Transform.h"
#include "Texture.h"
#include "Renderer.h"

namespace J
{
	TilemapRenderer::TilemapRenderer()
		: Component(enums::EComponentType::SpriteRenderer)
		, m_Texture(nullptr)
		, m_Size(3.0f, 3.0f)
		, m_Index(8, 7)
		, m_TileSize(16.0f, 16.0f)
	{
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

		if (m_Texture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			if (m_Texture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(_hdc
					, pos.x
					, pos.y
					, m_Texture->GetWidth() * m_Size.x * scale.x
					, m_Texture->GetHeight() * m_Size.y * scale.y
					, m_Texture->GetHdc()
					, 0, 0
					, m_Texture->GetWidth()
					, m_Texture->GetHeight()
					, func);
			}
			else
			{
				//https://blog.naver.com/power2845/50147965306
				TransparentBlt(_hdc
					, pos.x, pos.y
					, m_Texture->GetWidth() * m_Size.x * scale.x
					, m_Texture->GetHeight() * m_Size.y * scale.y
					, m_Texture->GetHdc()
					, 0, 0
					, m_Texture->GetWidth()
					, m_Texture->GetHeight()
					, RGB(255, 0, 255));
			}
		}

		return true;
	}
}