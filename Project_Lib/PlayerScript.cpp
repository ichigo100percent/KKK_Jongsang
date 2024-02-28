#include "PlayerScript.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"
#include "JSGameObject.h"
#include "Animator.h"
#include "Monster.h"
#include "MonsterScript.h"
#include "Object.h"
#include "Resources.h"

namespace J
{
	PlayerScript::PlayerScript()
		: m_State(PlayerScript::eState::Idle)
		, m_Animator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	bool PlayerScript::Init()
	{
		return true;
	}
	bool PlayerScript::Update()
	{
		if (m_Animator == nullptr)
			m_Animator = GetOwner()->GetComponent<Animator>();
		
		switch (m_State)
		{
		case J::PlayerScript::eState::Idle:
			idle();
			break;
		case J::PlayerScript::eState::Walk:
			move();
			break;
		case J::PlayerScript::eState::Sleep:
			break;
		case J::PlayerScript::eState::Attack:
			break;
		case J::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		default:
			break;
		}
	
		return true;
	}
	bool PlayerScript::LateUpdate()
	{
		return true;
	}
	bool PlayerScript::Render(HDC _hdc)
	{
		return true;
	}
	void PlayerScript::AttackEffect()
	{
		Monster* cat = object::Instantiate<Monster>(enums::eLayerType::Npc);
		cat->AddComponent<MonsterScript>();

		graphics::Texture* CatTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", CatTex, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", CatTex, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", CatTex, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", CatTex, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", CatTex, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.07f);
		catAnimator->CreateAnimation(L"Grooming", CatTex, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.07f);
		catAnimator->CreateAnimation(L"LayDown", CatTex, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.07f);

		catAnimator->PlayAnimaiton(L"SitDown", false);
		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

	}
	void PlayerScript::idle()
	{
		if (Input::Getkey(eKeyCode::LButton))
		{
			m_State = PlayerScript::eState::GiveWater;
			m_Animator->PlayAnimaiton(L"FrontGiveWater", false);

			Vector2 mousePos = Input::GetMousePosition();
		}

		if (Input::Getkey(eKeyCode::Right))
		{
			m_State = PlayerScript::eState::Walk;
			m_Animator->PlayAnimaiton(L"RightWalk");
		}

		if (Input::Getkey(eKeyCode::Left))
		{
			m_State = PlayerScript::eState::Walk;
			m_Animator->PlayAnimaiton(L"LeftWalk");
		}

		if (Input::Getkey(eKeyCode::Up))
		{
			m_State = PlayerScript::eState::Walk;
			m_Animator->PlayAnimaiton(L"UpWalk");
		}

		if (Input::Getkey(eKeyCode::Down))
		{
			m_State = PlayerScript::eState::Walk;
			m_Animator->PlayAnimaiton(L"DownWalk");
		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::Getkey(eKeyCode::Right))
		{
			pos.x += 100 * Time::DeltaTime();
		}

		if (Input::Getkey(eKeyCode::Left))
		{
			pos.x -= 100 * Time::DeltaTime();
		}

		if (Input::Getkey(eKeyCode::Up))
		{
			pos.y -= 100 * Time::DeltaTime();
		}

		if (Input::Getkey(eKeyCode::Down))
		{
			pos.y += 100 * Time::DeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::GetkeyUp(eKeyCode::Right) || Input::GetkeyUp(eKeyCode::Left) ||
			Input::GetkeyUp(eKeyCode::Up) || Input::GetkeyUp(eKeyCode::Down))
		{
			m_State = PlayerScript::eState::Idle;
			m_Animator->PlayAnimaiton(L"SitDown", false);
		}
	}
	void PlayerScript::giveWater()
	{
		if (m_Animator->IsComplete())
		{
			m_State = eState::Idle;
			m_Animator->PlayAnimaiton(L"Idle", false);
		}
	}
}