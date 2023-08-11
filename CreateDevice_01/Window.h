#include <Windows.h>
#include <assert.h>
#include <tchar.h>

class Window
{
public:
	HINSTANCE	m_hInstance;		 //�ν��Ͻ� �ڵ�
	HWND		m_hWnd;				 //������ �ڵ�
	DWORD		m_dwWindowStyle;	 //������ ��Ÿ��
	RECT		m_rcWindowBounds;	 //������ ����
	RECT		m_rcWindowClient;	 //Ŭ���̾�Ʈ ����
	UINT		m_iWindowWidth;		 //Ŭ���̾�Ʈ ���� ����ũ��
	UINT		m_iWinodwHeight;	 //Ŭ���̾�Ʈ ���� ����ũ��

public:
	//������ ����
	bool		InitWindow(HINSTANCE hInstance, int nCmdShow, TCHAR* strWindowTitle);
	//������ ��ġȭ�� �߾����� �̵�
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