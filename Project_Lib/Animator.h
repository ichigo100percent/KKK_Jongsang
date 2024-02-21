#pragma once
#include "Component.h"
#include "Animation.h"

namespace J
{
	class Animator : public Component 
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> _fun)
			{
				m_Event = std::move(_fun);
			}

			void operator()()
			{
				if (m_Event)
					m_Event();
			}

			std::function<void()> m_Event;
		};

		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

		Animator();
		~Animator();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
		bool Release() override;

		void CreateAnimation(const std::wstring& _name
			, graphics::Texture* _spriteSheet
			, Vector2 _leftTop
			, Vector2 _size
			, Vector2 _offset
			, UINT _spriteLength
			, float _duration);
		Animation* FindAnimation(const std::wstring& _name);
		void PlayAnimaiton(const std::wstring& _name, bool _loop = true);


		Events* FindEvents(const std::wstring& _name);
		std::function<void()>& GetStartEvent(const std::wstring& _name);
		std::function<void()>& GetCompleteEvent(const std::wstring& _name);
		std::function<void()>& GetEndEvent(const std::wstring& _name);

		bool IsComplete() { return m_ActiveAnimation->IsComplete(); }

	private:
		std::map<std::wstring, Animation*> m_Animations;
		Animation*						   m_ActiveAnimation;
		bool							   m_bLoop;

		std::map<std::wstring, Events*> m_Events;
	};
}

