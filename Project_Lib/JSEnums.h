#pragma once


namespace J::enums
{
	enum class EComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
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
}
