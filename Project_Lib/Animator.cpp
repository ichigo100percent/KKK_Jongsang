#include "Animator.h"
#include "Resources.h"
#include "Texture.h"

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
		for (auto& iter : m_Animations)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		for (auto& iter : m_Events)
		{
			delete iter.second;
			iter.second = nullptr;
		}
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

			Events* events = FindEvents(m_ActiveAnimation->GetNmae());

			if (m_ActiveAnimation->IsComplete() == true)
			{
				if (events)
					events->completeEvent();

				if (m_bLoop == true)
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
		animation->SetName(_name);
		animation->CreateAnimation(_name
			, _spriteSheet
			, _leftTop
			, _size
			, _offset
			, _spriteLength
			, _duration);

		animation->SetAnimator(this);

		Events* events = new Events();

		m_Events.insert(std::make_pair(_name, events));
		m_Animations.insert(std::make_pair(_name, animation));

	}
	void Animator::CreateAnimationByFolder(const std::wstring& _name, const std::wstring& _path, Vector2 _offset, float _duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(_name);
		if (animation != nullptr)
			return;

		int fileCount = 0;
		std::filesystem::path fs(_path);
		std::vector<graphics::Texture*> images = {};

		for (auto& p : std::filesystem::recursive_directory_iterator(fs))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = p.path();

			graphics::Texture* texture = Resources::Load < graphics::Texture>(fileName, fullName);
			
			images.push_back(texture);
			fileCount++;
		}

		UINT sheetWidth = images[0]->GetWidth() * fileCount;
		UINT sheetHeight = images[0]->GetHeight();
		graphics::Texture* spriteSheet = graphics::Texture::Create(_name, sheetWidth, sheetHeight);

		UINT imageWidth = images[0]->GetWidth();
		UINT imageHeight = images[0]->GetHeight();
		for (size_t i = 0; i < images.size(); i++)
		{
			BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0
				, imageWidth, imageHeight
				, images[i]->GetHdc(), 0, 0, SRCCOPY);
		}

		CreateAnimation(_name, spriteSheet
			, Vector2(0.0f, 0.0f), Vector2(imageWidth, imageHeight)
			, _offset, fileCount, _duration);

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

		if (m_ActiveAnimation)
		{
			Events* currentEvents = FindEvents(m_ActiveAnimation->GetNmae());

			if (currentEvents)
				currentEvents->endEvent();
		}

		Events* nextEvents = FindEvents(animation->GetNmae());

		if (nextEvents)
			nextEvents->startEvent();

		m_ActiveAnimation = animation;
		m_ActiveAnimation->Reset();
		m_bLoop = _loop;
	}
	Animator::Events* Animator::FindEvents(const std::wstring& _name)
	{
		auto iter = m_Events.find(_name);
		if (iter == m_Events.end())
			return nullptr;

		return iter->second;
	}
	std::function<void()>& Animator::GetStartEvent(const std::wstring& _name)
	{
		Events* events = FindEvents(_name);
		return events->startEvent.m_Event;
	}
	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& _name)
	{
		Events* events = FindEvents(_name);
		return events->completeEvent.m_Event;
	}
	std::function<void()>& Animator::GetEndEvent(const std::wstring& _name)
	{
		Events* events = FindEvents(_name);
		return events->endEvent.m_Event;
	}
}