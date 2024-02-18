#include "MonsterScript.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"
#include "JSGameObject.h"
#include "Animator.h"

namespace J
{
	MonsterScript::MonsterScript()
		: m_State(MonsterScript::eState::SitDown)
		, m_Animator(nullptr)
		, m_Time(0.0f)
	{
	}
	MonsterScript::~MonsterScript()
	{
	}
	bool MonsterScript::Init()
	{
		return true;
	}
	bool MonsterScript::Update()
	{
		if (m_Animator == nullptr)
			m_Animator = GetOwner()->GetComponent<Animator>();


		switch (m_State)
		{
		case J::MonsterScript::eState::SitDown:
			sitDown();
			break;
		case J::MonsterScript::eState::Walk:
			move();
			break;

		case J::MonsterScript::eState::Sleep:
			break;
		case J::MonsterScript::eState::LayDown:\
			layDown();
			break;
		case J::MonsterScript::eState::Attack:
			break;
		default:
			break;
		}

		return true;
	}
	bool MonsterScript::LateUpdate()
	{
		return true;
	}
	bool MonsterScript::Render(HDC _hdc)
	{
		return true;
	}
	bool MonsterScript::Release()
	{
		return true;
	}


	void MonsterScript::sitDown()
	{
		m_Time += Time::DeltaTime();
		if (m_Time > 6.0f)
		{
			m_State = MonsterScript::eState::Walk;
			int direction = (rand() % 4);
			m_Direction = (eDirection)direction;
			playWalkAnimationByDirection(m_Direction);
			m_Time = 0.0f;
		}

	}
	void MonsterScript::move()
	{
		m_Time += Time::DeltaTime();
		if (m_Time > 3.0f)
		{
			int isLayDown = (rand() % 2);
			if (isLayDown)
			{
				m_State = MonsterScript::eState::LayDown;
				m_Animator->PlayAnimaiton(L"LayDown", false);
			}
			else
			{
				m_State = MonsterScript::eState::SitDown;
				m_Animator->PlayAnimaiton(L"SitDown", false);
			}
		}
		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);

	}
	void MonsterScript::layDown()
	{
		m_Time += Time::DeltaTime();
		if (m_Time > 10.0f)
		{
			m_State = MonsterScript::eState::Walk;
			int direction = (rand() % 4);
			m_Direction = (eDirection)direction;
			playWalkAnimationByDirection(m_Direction);
			m_Time = 0.0f;
		}
	}
	void MonsterScript::playWalkAnimationByDirection(eDirection _dir)
	{
		switch (_dir)
		{
		case J::MonsterScript::eDirection::Left:
			m_Animator->PlayAnimaiton(L"LeftWalk", true);
			break;
		case J::MonsterScript::eDirection::Right:
			m_Animator->PlayAnimaiton(L"RightWalk", true);
			break;
		case J::MonsterScript::eDirection::Down:
			m_Animator->PlayAnimaiton(L"DownWalk", true);
			break;
		case J::MonsterScript::eDirection::Up:
			m_Animator->PlayAnimaiton(L"UpWalk", true);
			break;
		default:
			assert(false);
			break;
		}
	}
	void MonsterScript::translate(Transform* _tr)
	{
		Vector2 pos = _tr->GetPosition();
		switch (m_Direction)
		{
		case J::MonsterScript::eDirection::Left:
			pos.x -= 50 * Time::DeltaTime();
			break;
		case J::MonsterScript::eDirection::Right:
			pos.x += 50 * Time::DeltaTime();
			break;
		case J::MonsterScript::eDirection::Down:
			pos.y += 50 * Time::DeltaTime();
			break;
		case J::MonsterScript::eDirection::Up:
			pos.y -= 50 * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		_tr->SetPosition(pos);
	}
}