#pragma once
#include "Resources.h"
#include "Texture.h"


namespace J
{
	void LoadResources()
	{
		//study

		Resources::Load<graphics::Texture>(L"Map", L"../../data/CloudOcean.png");
		Resources::Load<graphics::Texture>(L"Cat", L"../../data/ChickenAlpha.bmp");
		
		Resources::Load<graphics::Texture>(L"Player", L"../../data/Player.bmp");

		//portfolio
		//Resources::Load<graphics::Texture>(L"JsIdle", L"../../data/Portfolio/Player/Idle.png");
	}
}