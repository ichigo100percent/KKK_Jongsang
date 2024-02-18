#pragma once
#include "Resource.h"
#include "Texture.h"

namespace J
{

	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float   duration;

			Sprite() 
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};
		Animation();
		~Animation();

		HRESULT Load(const std::wstring& _path) override;

		bool Update();
		bool Render(HDC _hdc);

		void CreateAnimation(const std::wstring& _name
			, graphics::Texture* _spriteSheet
			, Vector2 _leftTop
			, Vector2 _size
			, Vector2 _offset
			, UINT _spriteLength
			, float _duration);

		void Reset();

		bool IsComplete() { return m_bComplete; }
		void SetAnimator(class Animator* _animator) { m_Animator = _animator; }

	private:
		class Animator*		m_Animator;
		graphics::Texture*	m_Texture;

		std::vector<Sprite> m_AnimationSheet;
		int					m_Index;
		float				m_Time;
		bool				m_bComplete;
	};
}

