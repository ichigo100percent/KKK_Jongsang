#pragma once
#include "Std.h"
#include "BoxCollider2D.h"
#include "CircleCollider2D.h"           

namespace J
{
	using namespace enums;

	union CollisionID
	{
		struct 
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};

	class CollisionManager
	{
	public:
		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC _hdc);

		static void CollisionLayerCheck(eLayerType _left, eLayerType _right, bool enable);
		static void LayerCollision(class Scene* _scene, eLayerType _left, eLayerType _right);
		static void ColliderCollision(Collider* _left, Collider* _right);
		static bool Intersect(Collider* _left, Collider* _right);

	private:
		static std::bitset<(UINT)eLayerType::Max> m_CollisionLayerMatrix[(UINT)eLayerType::Max];
		static std::unordered_map<UINT64, bool> m_CollisionMap;
	};
}
