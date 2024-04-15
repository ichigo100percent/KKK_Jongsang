#pragma once


namespace J::enums
{
	enum class eComponentType
	{
		Transform,
		Collider,
		Rigidbody,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		End,
	};

	enum class eLayerType
	{
		None,
		BackGround,
		Tile,
		Npc,
		Player,
		Monster,
		Item,
		Floor,
		Particle,
		DeadLine,
		//
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		Animation,
		//Mesh
		//Shader,
		AudioClip,
		Prefab,
		End,
	};

	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};

	enum class eUIType
	{
		End =16,
	};
}
