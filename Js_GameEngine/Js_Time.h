#pragma once
#include "std.h"

namespace Js
{
	class Time
	{
	public:
		static void Init();
		static void Update();

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
	};
}
