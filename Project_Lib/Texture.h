#pragma once
#include "Resource.h"

namespace J::graphics
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None,
		};

		Texture();
		~Texture();
		
		HRESULT Load(const std::wstring& _path) override;

		UINT GetWidth() { return m_Width; }
		UINT GetHeight() { return m_Height; }
		HDC  GetHdc() { return m_Hdc; }
		eTextureType GetTextureType() { return m_Type; }
		Gdiplus::Image* GetImage() { return m_Image; }

	private:
		eTextureType	m_Type;
		Gdiplus::Image* m_Image;
		HBITMAP			m_Bitmap;
		HDC				m_Hdc;

		UINT			m_Width;
		UINT			m_Height;
	};
}
