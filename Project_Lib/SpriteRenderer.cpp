#include "SpriteRenderer.h"
#include "JSGameObject.h"
#include "Transform.h"

namespace J
{
	SpriteRenderer::SpriteRenderer()
		: m_Image(nullptr)
		, m_Width(0)
		, m_Height(0)
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphics(_hdc);
		graphics.DrawImage(m_Image, Gdiplus::Rect(pos.x, pos.y, m_Width, m_Height));
		
		return true;
	}
	bool SpriteRenderer::Release()
	{
		return true;
	}
	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		m_Image = Gdiplus::Image::FromFile(path.c_str());
		m_Width = m_Image->GetWidth();
		m_Height = m_Image->GetHeight();
	}
}