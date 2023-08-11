#include <Windows.h>
#include <assert.h>
#include <tchar.h>

class Window
{
public:
	HINSTANCE	m_hInstance;		 //인스턴스 핸들
	HWND		m_hWnd;				 //윈도우 핸들
	DWORD		m_dwWindowStyle;	 //윈도우 스타일
	RECT		m_rcWindowBounds;	 //윈도우 영역
	RECT		m_rcWindowClient;	 //클라이언트 영역
	UINT		m_iWindowWidth;		 //클라이언트 영역 가로크기
	UINT		m_iWinodwHeight;	 //클라이언트 영역 세로크기

public:
	//윈도우 생성
	bool		InitWindow(HINSTANCE hInstance, int nCmdShow, TCHAR* strWindowTitle);
	//윈도우 위치화면 중앙으로 이동
	void		centerWindow(HWND hwnd);

public:
	virtual bool		Init();
	virtual bool		Render();
	virtual bool		Release();
	virtual bool		Run();
	virtual LRESULT		WndPoc(HWND, UINT, WPARAM, LPARAM);

public:
	Window();
	virtual ~Window();
};