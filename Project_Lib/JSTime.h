#pragma once
#include "Std.h"


namespace J
{
	class Time
	{
	public:
		static void Init();
		static void Update();
		static void Render(HDC _hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
	};
}


//namespace J
//{
//	class Time
//	{
//		DECLARE_SINGLE(Time);
//
//	public:
//		void Init();
//		void Update();
//		void Render(HDC _hdc);
//
//		uint32 GetFps() { return _fps; }
//		float GetDeltaTime() { return _deltaTime; }
//
//	private:
//		uint64 _frequency = 0;
//		uint64 _prevCount = 0;
//		float _deltaTime = 0.f;
//
//	private:
//		uint32 _frameCount = 0;
//		float _frameTime = 0.f;
//		uint32 _fps = 0;
//	};
//}