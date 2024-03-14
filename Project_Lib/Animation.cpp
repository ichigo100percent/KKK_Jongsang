#include "Animation.h"
#include "JSTime.h"
#include "Transform.h"
#include "JSGameObject.h"
#include "Animator.h"
#include "Renderer.h"
#include "Camera.h"

namespace J
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, m_Animator(nullptr)
		, m_Texture(nullptr)
		, m_AnimationSheet{}
		, m_Index(-1)
		, m_Time(0.0f)
		, m_bComplete(false)
	{

	}

	Animation::~Animation()
	{

	}

	HRESULT Animation::Load(const std::wstring& _path)
	{
		return E_NOTIMPL;
	}

	bool Animation::Update()
	{
		if (m_bComplete)
			return false;

		m_Time += Time::DeltaTime();
		
		if (m_AnimationSheet[m_Index].duration < m_Time)
		{
			m_Time = 0.0f;
			if (m_Index < m_AnimationSheet.size() - 1)
				m_Index++;
			else
				m_bComplete = true;
		}

		return true;
	}
	bool Animation::Render(HDC _hdc)
	{
		// 알파블렌드를 쓸수 있는 조건 : 해당이미지 알파채널이 있어야한다.
		//AlphaBlend(125, );

		if (m_Texture == nullptr)
			return false;

		GameObject* gameObj = m_Animator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float   rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		Sprite sprite = m_AnimationSheet[m_Index];
		graphics::Texture::eTextureType type = m_Texture->GetTextureType();

		if (type == graphics::Texture::eTextureType::Bmp)
		{
			HDC imgHdc = m_Texture->GetHdc();

			if (m_Texture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(_hdc
					, pos.x - (sprite.size.x / 2.0f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.0f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, func);
			}
			else
			{
				TransparentBlt(_hdc
					, pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, RGB(255, 255, 255));
			}
		}
		else if (type == graphics::Texture::eTextureType::Png)
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
					  pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel
				, &imgAtt//nullptr
			);
		}

		return true;

	}

	void Animation::CreateAnimation(const std::wstring& _name
		, graphics::Texture* _spriteSheet
		, Vector2 _leftTop
		, Vector2 _size
		, Vector2 _offset
		, UINT _spriteLength
		, float _duration)
	{
		m_Texture = _spriteSheet;
		for (size_t i = 0; i < _spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = _leftTop.x + (_size.x * i);
			sprite.leftTop.y = _leftTop.y;
			sprite.size = _size;
			sprite.offset = _offset;
			sprite.duration = _duration;

			m_AnimationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		m_Time = 0.0f;
		m_Index = 0;
		m_bComplete = false;
	}

}