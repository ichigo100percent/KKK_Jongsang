#include "Animator.h"

namespace J
{
	Animator::Animator()
		: Component(enums::EComponentType::Animator)
		, m_Animations {}
		, m_ActiveAnimation(nullptr)
		, m_bLoop(false)
	{

	}

	Animator::~Animator()
	{

	}

	bool Animator::Init()
	{
		return true;
	}
	bool Animator::Update()
	{
		if (m_ActiveAnimation)
		{
			m_ActiveAnimation->Update();

			if (m_ActiveAnimation->IsComplete() == true &&
				m_bLoop == true)
			{
				m_ActiveAnimation->Reset();
			}
		}

		return true;
	}
	bool Animator::LateUpdate()
	{
		return true;
	}
	bool Animator::Render(HDC _hdc)
	{
		if (m_ActiveAnimation)
		{
			m_ActiveAnimation->Render(_hdc);
		}
		return true;
	}
	bool Animator::Release()
	{
		return true;
	}

	void Animator::CreateAnimation(const std::wstring& _name
		, graphics::Texture* _spriteSheet
		, Vector2 _leftTop
		, Vector2 _size
		, Vector2 _offset
		, UINT _spriteLength
		, float _duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(_name);
		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->CreateAnimation(_name
			, _spriteSheet
			, _leftTop
			, _size
			, _offset
			, _spriteLength
			, _duration);

		animation->SetAnimator(this);
		m_Animations.insert(std::make_pair(_name, animation));

	}
	Animation* Animator::FindAnimation(const std::wstring& _name)
	{
		auto iter = m_Animations.find(_name);
		if (iter == m_Animations.end())
			return nullptr;

		return iter->second;
	}
	void Animator::PlayAnimaiton(const std::wstring& _name, bool _loop)
	{
		Animation* animation = FindAnimation(_name);
		if (animation == nullptr)
			return;

		m_ActiveAnimation = animation;
		m_ActiveAnimation->Reset();
		m_bLoop = _loop;
	}
}