#include "SpriteRenderer.h"
#include "JSGameObject.h"
#include "Transform.h"
#include "Texture.h"
#include "Renderer.h"

namespace J
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, m_Texture(nullptr)
		, m_Size(Vector2::One)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	bool SpriteRenderer::Init()
	{
		return true;
	}
	bool SpriteRenderer::Update()
	{
		return true;
	}
	bool SpriteRenderer::LateUpdate()
	{
		return true;
	}
	bool SpriteRenderer::Render(HDC _hdc)
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
		else if (m_Texture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{

			//내가 원하는 픽셀을 투명화 시킬 경우
			Gdiplus::ImageAttributes imgAtt = {};

			//투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(255, 0, 255), Gdiplus::Color(255, 0, 255));

			Gdiplus::Graphics graphics(_hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(m_Texture->GetImage()
				, Gdiplus::Rect
				(
					pos.x, pos.y
					, m_Texture->GetWidth() * m_Size.x * scale.x
					, m_Texture->GetHeight() * m_Size.y * scale.y
				)
				, 0, 0
				, m_Texture->GetWidth(), m_Texture->GetHeight()
				, Gdiplus::UnitPixel
				, &imgAtt//nullptr
			);
		}
	
		
		return true;
	}
}