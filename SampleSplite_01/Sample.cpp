#include "Sample.h"

float g_fMapHalfSizeX = 400;
float g_fMapHalfSizeY = 300;

bool Sample::Init()
{
	m_pMapObj = new TPlaneObj;
	m_pMapObj->Set(m_pDevice, m_pImmediateContext);
	m_pMapObj->SetPos({ 0.0f,0.0f ,0.0f });
	m_pMapObj->SetScale(TVector3(g_fMapHalfSizeX, g_fMapHalfSizeY, 1.0f));
	m_pMapObj->Create(L"../../res/topdownmap.jpg", L"../../res/shader/Plane.hlsl");

	m_pPlayer->Set(m_pDevice, m_pImmediateContext);
	m_pPlayer->SetPos({ 0.0f,0.0f ,0.0f });
	m_pPlayer->SetScale(TVector3(100.f,100.f, 1.0f));
	TVector2 rt = { m_pPlayer->m_vPos.x, m_pPlayer->m_vPos.y };
	m_pPlayer->SetRect(rt,m_pPlayer->m_vScale.x * 2.0f, m_pPlayer->m_vScale.y * 2.0f);
	m_pPlayer->Create(L"../../res/topdownmap.jpg", L"../../res/shader/Plane.hlsl");

	m_pPlayer->Init();
	
	m_pMainCamera->Create({0.0f,0.0f, 0.0f },	{ (float)m_dwWindowWidth, (float)m_dwWindowHeight });
	return true;
}
bool Sample::Frame()
{
	m_pMapObj->Frame();
	m_pPlayer->Frame();
	
	return true;
}
bool Sample::Render()
{	
	m_pMainCamera->m_vCameraPos = m_pPlayer->m_vPos;
	m_pMapObj->SetMatrix(nullptr, &m_pMainCamera->m_matView,&m_pMainCamera->m_matOrthoProjection);
	m_pMapObj->Render();
	m_pPlayer->m_pSpriteLeg->SetMatrix(nullptr, &m_pMainCamera->m_matView, &m_pMainCamera->m_matOrthoProjection);
	m_pPlayer->m_pSpriteBody->SetMatrix(nullptr, &m_pMainCamera->m_matView, &m_pMainCamera->m_matOrthoProjection);
	m_pPlayer->Render();
	//m_pPlayer->SetMatrix(nullptr, &m_pMainCamera->m_matView, &m_pMainCamera->m_matOrthoProjection);

	
	return true;
}
bool Sample::Release()
{
	m_pMapObj->Release();
	delete m_pMapObj;
	return true;
}

TGAME(L"kgca", 800, 600)