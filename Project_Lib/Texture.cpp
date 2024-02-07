#include "Texture.h"
#include "Core.h"

//해당 전역변수가 존재함을 알리는 키워드 extern
extern J::Core core;

namespace J::graphics
{
	Texture::Texture()
		:Resource(enums::eResourceType::Texture)
	{

	}
	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const std::wstring& _path)
	{
		std::wstring ext
			= _path.substr(_path.find_last_of(L".") + 1);

		//bmp 일때
		if (ext == L"bmp")
		{
			m_Type = eTextureType::Bmp;
			m_Bitmap = (HBITMAP)LoadImageW(nullptr, _path.c_str(), IMAGE_BITMAP,
											0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (m_Bitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(m_Bitmap, sizeof(BITMAP), &info);

			m_Width = info.bmWidth;
			m_Height = info.bmHeight;

			HDC mainDC = core.GetHdc();
			m_Hdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(m_Hdc, m_Bitmap);
			DeleteObject(oldBitmap);
		}
		else if (ext == L"png")
		{
			m_Type = eTextureType::Png;
			m_Image = Gdiplus::Image::FromFile(_path.c_str());
			if (m_Image == nullptr)
				return S_FALSE;

			m_Width = m_Image->GetWidth();
			m_Height = m_Image->GetHeight();
		}

		return S_OK;
	}
}