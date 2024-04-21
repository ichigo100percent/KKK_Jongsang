#include "MarioScript.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"
#include "JSGameObject.h"
#include "Animator.h"
#include "Monster.h"
#include "MonsterScript.h"
#include "Object.h"
#include "Resources.h"
#include "Rigidbody.h"
#include "CollisionManager.h"

namespace J
{
	MarioScript::MarioScript()
		: m_eState(eMarioState::Idle)
		, m_eType(eMarioType::Normal)
		, isJumping(false)
		, m_isDie(false)
	{
	}
	MarioScript::~MarioScript()
	{
	}
	bool MarioScript::Init()
	{
		return true;
	}
	bool MarioScript::Update()
	{
		switch (m_eState)
		{
		case J::MarioScript::eMarioState::Idle:
			move();
			break;
		case J::MarioScript::eMarioState::Move:
			break;
		case J::MarioScript::eMarioState::Jump:
			break;
		case J::MarioScript::eMarioState::Climbing:
			break;
		case J::MarioScript::eMarioState::Sliding:
			break;
		case J::MarioScript::eMarioState::Die:
			die();
			break;
		default:
			break;
		}

		return true;
	}
	bool MarioScript::LateUpdate()
	{
		return true;
	}
	bool MarioScript::Render(HDC _hdc)
	{
		return true;
	}
	void MarioScript::OnCollisionEnter(Collider* other)
	{
		auto layerType = other->GetOwner()->GetLayerType();
		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();

		if (layerType == enums::eLayerType::Monster && rb->GetGround())
		{
			m_eState = MarioScript::eMarioState::Die;
			//GetOwner()->IsDead();
		}
		else if(layerType == enums::eLayerType::Monster)
		{
			object::Destroy(other->GetOwner());
			//other->GetOwner()->SetActive(false);
		}
	}
	void MarioScript::OnCollisionStay(Collider* other)
	{
	}
	void MarioScript::OnCollisionExit(Collider* other)
	{
	}
	void MarioScript::Setinit()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->SetPosition(Vector2(0.0f, 100.0f));
		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();
		Vector2 velocity = rb->GetVelocity();
		rb->SetVelocity(Vector2(0.0f, velocity.y));
		m_eState = eMarioState::Idle;
		m_eType = eMarioType::Normal;
		m_isDie = false;

	}
	void MarioScript::idle()
	{
	}
	void MarioScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();
		bool isGrounded = rb->GetGround();

		if (Input::GetKey(eKeyCode::Up) && isGrounded)
		{
			Vector2 velocity = rb->GetVelocity();
			velocity.y = -600.0f;
			rb->SetVelocity(velocity);
			rb->SetGround(false);
			isJumping = true;
		}
		if (Input::GetKeyUp(eKeyCode::Up) && isJumping)
		{
			isJumping = false;
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			rb->AddForce(Vector2(100.0f, 0.0f));
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			rb->AddForce(Vector2(-100.0f, 0.0f));
		}

		//위치 값을 출력하는 부분 추가
		auto currentPosition = tr->GetPosition();
		std::string output = "Current Position: ";
		output += "X= " + std::to_string((int)currentPosition.x);
		output += ", Y= " + std::to_string((int)currentPosition.y) + "\n";

		OutputDebugStringA(output.c_str());
	}
	void MarioScript::jump()
	{
		
	}
	void MarioScript::die()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();
		Vector2 velocity = rb->GetVelocity();

		// 마리오가 죽으면 x축은 이동할 수 없도록 설정합니다.
		rb->SetVelocity(Vector2(0.0f, velocity.y)); // x축 이동 속도를 0으로 설정

		// 마리오의 y축 속도를 초기화하고 위로 튀어오르게 설정합니다.
		if (!m_isDie)
		{
			m_Time = 0.0f;
			rb->SetVelocity(Vector2(0.0f, -800.0f)); // y축 이동 속도를 -300으로 설정
			rb->SetGround(false); // 지상에 서있지 않음으로 설정
			m_isDie = true; // 죽었음을 표시
		}
		else
		{
			m_Time += Time::DeltaTime();

			// 일정 시간이 지나면 모든 충돌을 비활성화하고 아래로 내려가게 설정합니다.
			if (m_Time > 1)
			{
				CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, false);
				CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, false);
				rb->SetVelocity(Vector2(0.0f, 800.0f));
			}
		}
	}
	void MarioScript::attack()
	{
	}
}