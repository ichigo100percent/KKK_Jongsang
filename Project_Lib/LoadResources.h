#pragma once
#include "Resources.h"
#include "Texture.h"


namespace J
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"../../data/CloudOcean.png");
		Resources::Load<graphics::Texture>(L"Cat", L"../../data/ChickenAlpha.bmp");
		
		Resources::Load<graphics::Texture>(L"Player", L"../../data/Player.bmp");
	}
}