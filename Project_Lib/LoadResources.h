#pragma once
#include "Resources.h"
#include "Texture.h"

namespace J
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"../../data/CloudOcean.png");
	}
}