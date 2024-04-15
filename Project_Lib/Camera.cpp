#include "Camera.h"
#include "JSGameObject.h"
#include "Transform.h"
#include "Core.h"

extern J::Core core;

namespace J
{
	Camera::Camera()
		: Component(enums::eComponentType::Camera)
		, m_Distance(Vector2::Zero)
		, m_Resolution(Vector2::Zero)
		, m_LookPosition(Vector2::Zero)
		, m_Target(nullptr)
	{

	}
	Camera::~Camera()
	{

	}

	bool Camera::Init()
	{
		m_Resolution.x = core.GetWidth();
		m_Resolution.y = core.GetHeight();

		return true;
	}

	bool Camera::Update()
	{
		if (m_Target)
		{
			Transform* tr = m_Target->GetComponent<Transform>();
			m_LookPosition = tr->GetPosition();

			m_LookPosition.x = std::clamp(m_LookPosition.x, 200.f, 3024.f - 400.f);
			m_LookPosition.y = std::clamp(m_LookPosition.y, 000.f, 3024.f - 300.f);
		}
		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			m_LookPosition = cameraTr->GetPosition();
		}

		m_Distance = m_LookPosition - (m_Resolution / 2.0f);

		return true;
	}

	bool Camera::LateUpdate()
	{
		return true;
	}

	bool Camera::Render(HDC _hdc)
	{
		return true;
	}

}