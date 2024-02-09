#pragma once


namespace J::enums
{
	enum class EComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		End,
	};

	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		//
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		//Mesh
		//Shader,
		AudioClip,
		Prefab,
		End,
	};
}
