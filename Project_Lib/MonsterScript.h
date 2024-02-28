#pragma once
#include "Script.h"
#include "Transform.h"

namespace J
{
	class MonsterScript : public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack,
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};

		MonsterScript();
		~MonsterScript();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

	private:
		void sitDown();
		void move();
		void layDown();

		void playWalkAnimationByDirection(eDirection _dir);
		void translate(Transform* _tr);

	private:
		eState m_State;
		class Animator* m_Animator;
		eDirection      m_Direction;
		float           m_Time;
		float			m_DeathTime;
	};
}
