#include "Game.h"

float g_fMapHalfSizeX = 400.0f;
float g_fMapHalfSizeY = 300.0f;

void  Game::CreateBlendState()
{
    // alpha blending
    D3D11_BLEND_DESC bsd;
    ZeroMemory(&bsd, sizeof(bsd));
    bsd.RenderTarget[0].BlendEnable = true;
    bsd.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
    bsd.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    bsd.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
    // 알파블랜딩 공식 - 소스(float4(0,1,0,0.5f)), 대상(1,0,0,1)
    //finalcolor(RGB) = SrcColor* SrcBlend   + DestColor*DestBlend
    //           = Scrcolor* alphaValue + DestColor * (1.0f-alphaValue)
    //           = 0,1,0 * 0.5f + 1,0,0 * (1.0f-0.5f)
    // //        만약 t= 0.0f; 결과 => 배경만 나온다.
    // //        만약 t= 1.0f; 결과 => 소스만 나온다.
    //           만약 t= 0.5f; 결과 - >소스컬러*0.5 + 배경컬러*0.5f
    //           = 0,1,0 * t + 1,0,0 * (1.0f-t)
    //           =  r*t,b*t,b*t + r*(1.0f-t),b*(1.0f-t),b*(1.0f-t)

    // (A)
    bsd.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    bsd.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    bsd.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;

    bsd.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
    m_pDevice->CreateBlendState(&bsd, &m_AlphaBlend);
}

bool  Game::Init()
{
    m_mapObj = make_unique<PlaneObject>();
    m_mapObj->Set(m_pDevice, m_pContext);
    m_mapObj->SetPos({ 0.0f, 0.0f, 0.0f });
    m_mapObj->SetScale(Vec3(g_fMapHalfSizeX, g_fMapHalfSizeY, 1.0f));
    m_mapObj->Create(L"../../data/Green.png", L"Plane.hlsl");

	return true;
}
bool  Game::Frame()
{
    m_mapObj->Frame();
	return true;
}
bool  Game::Render()
{
    m_mapObj->Render();
	

	return true;
}
bool  Game::Release()
{
    m_mapObj->Release();
	return true;
}

GAME(L"GameEngine", 800, 600);