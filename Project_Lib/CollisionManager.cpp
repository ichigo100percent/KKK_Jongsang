#include "CollisionManager.h"
#include "Scene.h"
#include "SceneManager.h"
#include "JSGameObject.h"
#include "Collider.h"
#include "Transform.h"

namespace J
{
	std::bitset<(UINT)eLayerType::Max> CollisionManager::m_CollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::m_CollisionMap = {};

	void CollisionManager::Init()
	{
	}
	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (m_CollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}
	void CollisionManager::LateUpdate()
	{
	}
	void CollisionManager::Render(HDC _hdc)
	{
	}
	void CollisionManager::Clear()
	{
		m_CollisionMap.clear();
		m_CollisionLayerMatrix->reset();
	}
	void CollisionManager::CollisionLayerCheck(eLayerType _left, eLayerType _right, bool enable)
	{
		int row = 0;
		int col = 0;
		if (_left <= _right)
		{
			row = (UINT)_left;
			col = (UINT)_right;
		}
		else
		{
			row = (UINT)_right;
			col = (UINT)_left;
		}
		m_CollisionLayerMatrix[row][col] = enable;
	}

	void CollisionManager::LayerCollision(Scene* _scene, eLayerType _left, eLayerType _right)
	{
		const std::vector<GameObject*>& lefts = SceneManager::GetGameObjects(_left); //_scene->GetLayer(_left)->GetGameObjects();
		const std::vector<GameObject*>& rights = SceneManager::GetGameObjects(_right); //_scene->GetLayer(_right)->GetGameObjects();

		for (GameObject* left : lefts)
		{
			if (left->IsActive() == false)
				continue;
			Collider* leftCol = left->GetComponent<Collider>();
			if (leftCol == nullptr)
				continue;

			for (GameObject* right : rights)
			{
				if (right->IsActive() == false)
					continue;
				Collider* rightCol = right->GetComponent<Collider>();
				if (rightCol == nullptr)
					continue;
				if (left == right)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}

	}
	void CollisionManager::ColliderCollision(Collider* _left, Collider* _right)
	{
		//두 충돌체 번호로 가져온 ID 확인하여 CollisonID 세팅
		CollisionID id = {};
		id.left = _left->GetID();
		id.right = _right->GetID();

		//이전 충돌 정보를 검색한다
		//만약에 충돌정보가 없는 상태라면
		//충돌정보를 생성해준다
		auto iter = m_CollisionMap.find(id.id);
		if (iter == m_CollisionMap.end())
		{
			m_CollisionMap.insert(std::make_pair(id.id, false));
			iter = m_CollisionMap.find(id.id);
		}

		//충돌체크를 해준다
		if (Intersect(_left, _right))
		{
			//최초 충돌
			if (iter->second == false)
			{
				_left->OnCollisionEnter(_right);
				_right->OnCollisionEnter(_left);
				iter->second = true;
			}
			else //이미 충돌 중
			{
				_left->OnCollisionStay(_right);
				_right->OnCollisionStay(_left);
			}
		}
		else
		{
			//충돌을 하지 않는 상태
			if (iter->second == true)
			{
				_left->OnCollisionExit(_right);
				_right->OnCollisionExit(_left);
				iter->second = false;
			}
		}
	}
	bool CollisionManager::Intersect(Collider* _left, Collider* _right)
	{
		Transform* leftTr = _left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = _right->GetOwner()->GetComponent<Transform>();

		//size가 1,1 일때 기본크기가 100픽셀
		Vector2 leftSize = _left->GetSize() * 100.0f;
		Vector2 rightSize = _right->GetSize() * 100.0f;

		Vector2 leftPos = leftTr->GetPosition() + _left->GetOffset() + (leftSize / 2.0f);
		Vector2 rightPos = rightTr->GetPosition() + _right->GetOffset() + (rightSize / 2.0f);


		//AABB 충돌
		enums::eColliderType leftType = _left->GetColliderType();
		enums::eColliderType rightType = _right->GetColliderType();

		if (leftType == enums::eColliderType::Rect2D
			&& rightType == enums::eColliderType::Rect2D)
		{
			// rect - rect
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
			{
				return true;
			}
		}
		return false;

		/*
		if (leftType == enums::eColliderType::Circle2D
			&& rightType == enums::eColliderType::Circle2D)
		{
			// circle - circle
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);
			float distance = (leftCirclePos - rightCirclePos).length();
			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
			{
				return true;
			}
		}

		if ((leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Rect2D)
			|| (leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Circle2D))
		{
			// circle - rect

		}
		*/
	}
}