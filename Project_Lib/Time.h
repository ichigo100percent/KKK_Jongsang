#pragma once
#include "Std.h"


namespace J
{
	class Time
	{
	public:
		static void Init();
		static void Frame();
		static void Render(HDC _hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
	};
}

