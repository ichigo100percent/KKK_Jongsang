#include "Core.h"
#include "Input.h"
#include "JSTime.h"
#include "SceneManager.h"
#include "Resources.h"
#include "CollisionManager.h"

namespace J
{
	Core::Core()
		:m_Hwnd(nullptr)
		,m_Hdc(nullptr)
		,m_Width(0)
		,m_Height(0)
		,m_BackHdc(NULL)
		,m_Backbitmap(NULL)
	{

	}

	Core::~Core()
	{

	}

	bool Core::Init(HWND _hwnd, UINT _width, UINT _height)
	{
		adjustWindowRect(_hwnd, _width, _height);
		CreateBuffer(_width, _height);
		InitEtc();

		CollisionManager::Init();
		SceneManager::Init();

		return true;
	}

	bool Core::Update()
	{
		Input::Update();
		Time::Update();
		CollisionManager::Update();
		SceneManager::Update();

		return true;
	}

	bool Core::LateUpdate()
	{
		CollisionManager::LateUpdate();
		SceneManager::LateUpdate();
		return true;
	}

	bool Core::Render()
	{
		clearRenderTarget();

		//Time::Render(m_BackHdc);
		CollisionManager::Render(m_BackHdc);
		SceneManager::Render(m_BackHdc);

		copyRenderTarget(m_BackHdc, m_Hdc);
		return true;
	}

	bool Core::Release()
	{
		SceneManager::Release();
		Resources::Release();

		return true;
	}

	void Core::Destroy()
	{
		SceneManager::Destroy();
	}

	bool Core::clearRenderTarget()
	{
		//clear
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(m_BackHdc, grayBrush);

		Rectangle(m_BackHdc, -1, -1, 1601, 901);

		(HBRUSH)SelectObject(m_BackHdc, oldBrush);
		DeleteObject(grayBrush);
		return true;
	}

	bool Core::copyRenderTarget(HDC source, HDC dest)
	{
		// BackBuffer에 있는걸 원본 Buffer에 복사(그려준다)
		BitBlt(dest, 0, 0, m_Width, m_Height
			, source, 0, 0, SRCCOPY);
		return true;
	}

	bool Core::adjustWindowRect(HWND _hwnd, UINT _width, UINT _height)
	{
		m_Hwnd = _hwnd;
		m_Hdc = GetDC(_hwnd);

		RECT rect = { 0, 0, _width, _height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		m_Width = rect.right - rect.left;
		m_Height = rect.bottom - rect.top;

		SetWindowPos(_hwnd, nullptr, 0, 0, m_Width, m_Height, 0);
		ShowWindow(_hwnd, true);

		return true;
	}

	bool Core::CreateBuffer(UINT _width, UINT _height)
	{
		//윈도우 해상도에 맞는 백버퍼(도화지)생성
		m_Backbitmap = CreateCompatibleBitmap(m_Hdc, _width, _height);

		//백버퍼를 가르킬 DC생성
		m_BackHdc = CreateCompatibleDC(m_Hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(m_BackHdc, m_Backbitmap);
		DeleteObject(oldBitmap);
		return true;
	}

	bool Core::InitEtc()
	{
		Input::Init();
		Time::Init();

		return true;
	}

	bool Core::Run()
	{
		Update();
		LateUpdate();
		Render();

		Destroy();

		return true;
	}
}