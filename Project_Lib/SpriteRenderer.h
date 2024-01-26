#pragma once
#include "Entity.h"
#include "Component.h"

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

		 void ImageLoad(const std::wstring& path);
		 
	private:
		Gdiplus::Image* m_Image;
		UINT			m_Width;
		UINT			m_Height;
	};
}
