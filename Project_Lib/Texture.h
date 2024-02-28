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

		static Texture* Create(const std::wstring _name, UINT _width, UINT _height);

		Texture();
		~Texture();
		
		HRESULT Load(const std::wstring& _path) override;

		UINT GetWidth() { return m_Width; }
		UINT GetHeight() { return m_Height; }
		HDC  GetHdc() { return m_Hdc; }
		void SetWidth(UINT _width) { m_Width = _width; }
		void SetHeight(UINT _height) { m_Height = _height; }
		eTextureType GetTextureType() { return m_Type; }
		Gdiplus::Image* GetImage() { return m_Image; }
		bool IsAlpha() { return m_bAlpha; }

	private:
		bool			m_bAlpha;
		eTextureType	m_Type;
		Gdiplus::Image* m_Image;
		HBITMAP			m_Bitmap;
		HDC				m_Hdc;

		UINT			m_Width;
		UINT			m_Height;
	};
}
