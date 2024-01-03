//#include "PlayerObj.h"
//#include "Input.h"
//
//
//bool PlayerObj::create(InitSet info, W_STR texFileName)
//{
//	m_initSet = info;
//	m_csName = info.name;
//	m_vPosition = info.position;
//	m_fSpeed = info.fMaxSpeed * 0.5f;
//	m_csDefaultVSFileName = L"../../data/shader/Default.hlsl";
//	m_csDefaultPSFileName = L"../../data/shader/Default.hlsl";
//	m_csDefaultVSEntryName = "VS";
//	m_csDefaultPSEntryName = "PS";
//	m_pTexMask = TextureMgr::Get().Load(info.tex);
//	Object::Create(m_csName, texFileName);
//
//	return true;
//}
//
//bool PlayerObj::SetVB(Vec2 _pos, Vec2 _uvPos, Vec2 _size, Vec2 texSize)
//{
//	_vertices.clear();
//	_vertices.resize(4);
//
//	float fU0 = _uvPos.x / texSize.x;
//	float fV0 = _uvPos.y / texSize.y;
//	float fW = fU0 + _size.x / texSize.x;
//	float fH = fV0 + _size.y / texSize.y;
//
//	Vec2 uv0 = { fU0, fV0 };
//	Vec2 uv1 = { fW, fV0 };
//	Vec2 uv2 = { fW, fH };
//	Vec2 uv3 = { fU0, fH };
//
//	_vertices[0] = { Vec3(_pos.x, _pos.y, 0.5f), uv0 };      // 0
//	_vertices[1] = { Vec3(_pos.x + _size.x, _pos.y, 0.5f), uv1 };    // 1
//	_vertices[2] = { Vec3(_pos.x + _size.x, _pos.y + _size.y, 0.5f), uv2 };  // 2
//	_vertices[3] = { Vec3(_pos.x, _pos.y + _size.y, 0.5f), uv3 };		//3
//
//	return true;
//}
//
//void PlayerObj::SetPosition(Vec2 _pos)
//{
//	_vertices[0].position = Vec3(_pos.x, _pos.y, 0.5f);
//	_vertices[1].position = Vec3(_pos.x + m_initSet.size.x, _pos.y, 0.5f);
//	_vertices[2].position = Vec3(_pos.x + m_initSet.size.x, _pos.y + m_initSet.size.y, 0.5f);
//	_vertices[3].position = Vec3(_pos.x, _pos.y + m_initSet.size.y, 0.5f);
//	m_pContext->UpdateSubresource(_vertexBuffer.Get(),
//		0,
//		nullptr,
//		&_vertices.at(0),
//		0,
//		0);
//}
//
//bool PlayerObj::CreateVertexBuffer()
//{
//	SetVB(m_initSet.position, m_initSet.uv, m_initSet.size,
//		{ (float)m_pTexMask->m_texImage->GetMetadata().width,
//		  (float)m_pTexMask->m_texImage->GetMetadata().height });
//	Object::CreateVertexBuffer();
//	
//	return true;
//}
//
//bool PlayerObj::PreRender()
//{
//	if (m_pTexMask != nullptr)
//	{
//		m_pContext->PSSetShaderResources(1, 1, &m_pTexMask->m_pTextureSRV);
//	}
//
//	return Object::PreRender();
//}
//
//bool PlayerObj::Frame()
//{
//	//  위치 = 현 위치 + 이동방향 * 시간의 동기화( 1초당 최대 거리 이동)
////  g_fSecPerFrame * m_fSpeed;
////  1프레임  -> 1초 * 300     -> 300
////  10프레임 -> 0.1초 * 300   -> 300
////  100프레임 -> 0.01초 *300  -> 300
//	m_fSpeed -= g_fSecPerFrame * m_fSpeed * 0.9f;
//	m_fSpeed = max(0.0f, m_fSpeed);
//	m_fSpeed = min(m_initSet.fMaxSpeed, m_fSpeed);
//	if (Input::Get().m_dwKeyState['W'] == KEY_HOLD)
//	{
//		m_fSpeed = max(m_initSet.fMaxSpeed * 0.5f, m_fSpeed);
//		m_fSpeed += g_fSecPerFrame * m_fSpeed;
//		m_vDirection += Vec2(0, -1.0f);
//	}
//	if (Input::Get().m_dwKeyState['S'] == KEY_HOLD)
//	{
//		m_fSpeed = max(m_initSet.fMaxSpeed * 0.5f, m_fSpeed);
//		m_fSpeed += g_fSecPerFrame * m_fSpeed;
//		m_vDirection = m_vDirection + Vec2(0, 1.0f);
//	}
//	if (Input::Get().m_dwKeyState['A'] == KEY_HOLD)
//	{
//		m_fSpeed = max(m_initSet.fMaxSpeed * 0.5f, m_fSpeed);
//		m_fSpeed += g_fSecPerFrame * m_fSpeed;
//		m_vDirection += Vec2(-1, 0.0f);
//	}
//	if (Input::Get().m_dwKeyState['D'] == KEY_HOLD)
//	{
//		m_fSpeed = max(m_initSet.fMaxSpeed * 0.5f, m_fSpeed);
//		m_fSpeed += g_fSecPerFrame * m_fSpeed;
//		m_vDirection += Vec2(1, 0.0f);
//	}
//
//	m_vDirection.Normalize();
//	m_vVelocity = m_vDirection * g_fSecPerFrame * m_fSpeed;
//	m_vPosition += m_vVelocity;
//	SetPosition(m_vPosition);
//
//	return true;
//}
//
//
