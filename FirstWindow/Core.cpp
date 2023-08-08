#include "Core.h"
bool  Core::Init() { return true; }
bool  Core::Frame() { return true; }
bool  Core::Render() { return true; }
bool  Core::Release() { return true; }
bool  Core::EngineInit()
{
	Init();
	return true;
}
bool  Core::EngineFrame()
{
	Frame();
	return true;
}
bool  Core::EngineRender()
{
	Render();
	return true;
}
bool  Core::EngineRelease()
{
	Release();
	return true;
}