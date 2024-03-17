#pragma once


namespace J::enums
{
	enum class EComponentType
	{
		Transform,
		Collider,
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
		Npc,
		Player,
		Particle,
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
}
