#pragma once
//#include "Object.h"
//
//typedef struct tagUVRECT
//{
//	float    left;
//	float    top;
//	float    right;
//	float    bottom;
//} UVRECT;
//
//class TextureAni
//{
//public:
//	W_STR                   m_csName;
//	RECT					m_rtRect;
//	UINT					m_iNumHeight;
//	UINT					m_iNumWidth;
//	UVRECT					m_uvIndex;
//	UINT					m_iApplyIndex = 0;
//
//	float					m_fTimer = 0.0f;
//	float					m_fAnimationTime = 1.0f;
//	float					m_fInitAnimationTime = 1.0f;
//	float					m_fStepTime = 0.0f;
//
//	std::vector<UVRECT>		m_pUVArray;
//	//std::vector<Texture*>  m_pTexArray;
//	std::vector<shared_ptr<Texture>>  m_pTexArray;
//	std::vector<Vertex>	_vertices;  // 시스템 메모리
//	//Texture* m_ptTex = nullptr;
//	shared_ptr<Texture> m_ptTex;
//
//
//public:
//	virtual bool    Init();
//	virtual bool    Create(W_STR name) {
//		return true;
//	};
//	virtual bool    Create(W_STR name, T_STR_VECTOR texFileName);
//	virtual bool    Create(W_STR name, W_STR texFileName,
//							UINT iNumWidth = 1,
//							UINT iNumHeight = 1,
//							float fAnimTime = 1.0f);
//	virtual bool	LoadTexture(T_STR_VECTOR texArray);
//	virtual bool    LoadTexture(std::wstring texFileName);
//	virtual bool    PreRender();
//	virtual bool    Frame(float fElapsTime);
//	virtual bool    Render(ID3D11DeviceContext* pd3dContext);
//	virtual bool    PostRender();
//	virtual bool    Release();
//
//};

