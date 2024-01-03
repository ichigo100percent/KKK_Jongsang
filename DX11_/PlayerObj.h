#pragma once
//#include "Object.h"
//
//struct InitSet
//{
//	W_STR name;
//	W_STR tex;
//	Vec2 position;
//	Vec2 uv;
//	Vec2 size;
//	float fMaxSpeed;
//};
//
//
//class PlayerObj : public Object
//{
////public:
////	PlayerObj(ComPtr<ID3D11Device>			_pDevice,
////		ComPtr<ID3D11DeviceContext>		_pContext,
////		RECT							_rtClient)
////	{
////		m_pDevice = _pDevice;
////		m_pContext = _pContext;
////		m_rtClient = _rtClient;
////		_vertices.resize(4);
////		Init();
////	}
//
//public:
//	InitSet m_initSet;
//
//	Vec2    m_vPosition;
//	Vec2	m_vDirection;
//	Vec2	m_vVelocity;
//	float	m_fAccel = 0.0f;
//	float	m_fSpeed;
//	shared_ptr<Texture>			m_pTexMask = nullptr;
//
//
//public:
//	bool				CreateVertexBuffer() override;
//	bool				PreRender()			 override;
//	bool			    Frame()				 override;		
//
//
//public:
//	bool create(InitSet info, W_STR texFileName);
//	bool SetVB(Vec2 _pos, Vec2 _uvPos, Vec2 _size, Vec2 texSize);
//	void SetPosition(Vec2 _pos);
//
//public:
//	PlayerObj() {}
//	PlayerObj(ComPtr<ID3D11Device>			_pDevice,
//		ComPtr<ID3D11DeviceContext>		_pContext,
//		RECT							_rtClient)
//	{
//		m_pDevice = _pDevice;
//		m_pContext = _pContext;
//		m_rtClient = _rtClient;
//	}
//};
//
