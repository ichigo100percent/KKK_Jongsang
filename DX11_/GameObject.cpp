#include "GameObject.h"


void GameObject::SetRect(Vec2& _c, float _w, float _h)
{
	m_Rect.left = _c.x;
	m_Rect.top = _c.y;
	m_Rect.right = _w;
	m_Rect.bottom = _h;
}

void GameObject::SetPos(Vec3 _p)
{
	m_Postion = _p;
}

void GameObject::SetScale(Vec3 _s)
{
	m_Scale = _s;
}

void GameObject::SetMatrix(Matrix* _matWorld, Matrix* _matView, Matrix* _matProj)
{
	if (_matWorld != nullptr)
	{
		m_World = *_matWorld;
	}
	if (_matView != nullptr)
	{
		m_View = *_matView;
	}
	if (_matProj != nullptr)
	{
		m_Projection = *_matProj;
	}

	m_cbData.matWorld = m_World.Transpose();
	m_cbData.matView = m_World.Transpose();
	m_cbData.matProj = m_World.Transpose();
	m_Context->UpdateSubresource(m_ConstantBuffer.Get(), 0, nullptr, &m_cbData, 0, 0);
}

bool GameObject::Create(wstring _texName, wstring _shaderNmae)
{
	CreateConstantBuffer();
	CreateVertexBuffer();
	m_Shader = ShaderMgr::Instance().Load(_shaderNmae);
	CreateInputLayout();
	m_Texture = TextureMgr::Instance().Load(_texName);
	return true;
}

bool GameObject::Init()
{
	Object::Init();
	return true;
}

bool GameObject::Frame()
{
	Object::Frame();
	return true;
}

bool GameObject::Render()
{
	Object::Render();
	return true;
}

bool GameObject::Release()
{
	Object::Release();
	return true;
}

GameObject::GameObject()
{
	m_Postion = Vec3(0, 0, 0);
	m_Scale = Vec3(1, 1, 1);
	m_Rotation = Vec3(0, 0, 0);
}

