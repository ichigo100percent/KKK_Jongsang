#include "JSTime.h"

namespace J
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};

	float Time::DeltaTimeValue = 0.0f;

	void Time::Init()
	{
		//cpu 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		//프로그램이 시작 했을 때 현재 진동수
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;

	}

	void Time::Render(HDC _hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time: %d FPS: %d", (int)time, (int)fps);
		int len = wcsnlen(str, 50);

		TextOut(_hdc, 0, 0, str, len);
	}


}

//namespace J
//{
//	void Time::Init()
//	{
//		::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
//		::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount)); // CPU 클럭
//	}
//	void Time::Update()
//	{
//		uint64 currentCount;
//		::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));
//
//		_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
//		_prevCount = currentCount;
//
//		_frameCount++;
//		_frameTime += _deltaTime;
//
//		if (_frameTime >= 1.f)
//		{
//			_fps = static_cast<uint32>(_frameCount / _frameTime);
//
//			_frameTime = 0.f;
//			_frameCount = 0;
//		}
//	}
//	void Time::Render(HDC _hdc)
//	{
//	}
//}