#include "SpriteRenderer.h"
#include "JSGameObject.h"
#include "Transform.h"
#include "Texture.h"
#include "Renderer.h"

namespace J
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::EComponentType::SpriteRenderer)
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
		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector2 pos = tr->GetPosition();

		//Gdiplus::Graphics graphics(_hdc);
		//graphics.DrawImage(m_Image, Gdiplus::Rect(pos.x, pos.y, m_Width, m_Height));

		if (m_Texture == nullptr)
			assert(false);

		auto tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CalculatePosition(pos);

		if (m_Texture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			//https://blog.naver.com/power2845/50147965306
			TransparentBlt(_hdc, pos.x, pos.y
				, m_Texture->GetWidth() * m_Size.x * scale.x, m_Texture->GetHeight() * m_Size.y * scale.y
				, m_Texture->GetHdc(), 0, 0, m_Texture->GetWidth(), m_Texture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (m_Texture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{

			//내가 원하는 픽셀을 투명화 시킬 경우
			Gdiplus::ImageAttributes imgAtt = {};

			//투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

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
				, nullptr/*&imgAtt*/);
		}
	
		
		return true;
	}
	bool SpriteRenderer::Release()
	{
		return true;
	}

}