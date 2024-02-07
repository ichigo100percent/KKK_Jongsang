#include "SpriteRenderer.h"
#include "JSGameObject.h"
#include "Transform.h"
#include "Texture.h"

namespace J
{
	SpriteRenderer::SpriteRenderer()
		: Component()
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

		if (m_Texture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			//https://blog.naver.com/power2845/50147965306
			TransparentBlt(_hdc, pos.x, pos.y
				, m_Texture->GetWidth() * m_Size.x, m_Texture->GetHeight() * m_Size.y
				, m_Texture->GetHdc(), 0, 0, m_Texture->GetWidth(), m_Texture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (m_Texture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(_hdc);
			graphics.DrawImage(m_Texture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y
					, m_Texture->GetWidth() * m_Size.x, m_Texture->GetHeight() * m_Size.y));
		}
	
		
		return true;
	}
	bool SpriteRenderer::Release()
	{
		return true;
	}
	//void SpriteRenderer::ImageLoad(const std::wstring& path)
	//{
	//	m_Image = Gdiplus::Image::FromFile(path.c_str());
	//	m_Width = m_Image->GetWidth();
	//	m_Height = m_Image->GetHeight();
	//}
}