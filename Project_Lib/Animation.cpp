#include "Animation.h"
#include "Time.h"
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
		,m_bComplete(false)
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

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

		Sprite sprite = m_AnimationSheet[m_Index];
		HDC imgHdc = m_Texture->GetHdc();

		AlphaBlend(_hdc
			, pos.x
			, pos.y
			, sprite.size.x * 5.f
			, sprite.size.y * 5.f
			, imgHdc
			, sprite.leftTop.x
			, sprite.leftTop.y
			, sprite.size.x
			, sprite.size.y
			, func);

		return true;

	}

	void Animation::CreateAnimaiton(const std::wstring& _name
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