#include "Rigidbody.h"
#include "JSTime.h"
#include "Transform.h"
#include "JSGameObject.h"

namespace J
{
    Rigidbody::Rigidbody()
        : Component(enums::eComponentType::Rigidbody)
        , m_Mass(1.0f)
        , m_Friction(10.0f)
        , m_Force(Vector2::Zero)
        , m_Velocity(Vector2::Zero)
        , m_Gravity(Vector2::Zero)
        , m_Accelation(Vector2::Zero)
    {
    }
    Rigidbody::~Rigidbody()
    {
    }
    bool Rigidbody::Init()
    {
        return true;
    }
    bool Rigidbody::Update()
    {
        //f(��) = m(����) * a(���ӵ�)
        //a = f / m
        m_Accelation = m_Force / m_Mass;

        //�ӵ��� ���Ӹ� ���Ѵ�
        m_Velocity += m_Accelation * Time::DeltaTime();

        if (!(m_Velocity == Vector2::Zero))
        {
            //�ӵ��� �ݴ�������� ������ �ۿ�
            Vector2 friction = -m_Velocity;
            friction = friction.normalize() * m_Friction * m_Mass * Time::DeltaTime();

            //���������� ���� �ӵ� ���ҷ��� ���� �ӵ����� ū ���
            if (m_Velocity.length() <= friction.length())
            {
                //����
                m_Velocity = Vector2::Zero;
            }
            else
            {
                m_Velocity += friction;
            }
        }

        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        pos = pos + m_Velocity * Time::DeltaTime();
        tr->SetPosition(pos);

        m_Force.clear();
        return true;
    }
    bool Rigidbody::LateUpdate()
    {
        return true;
    }
    bool Rigidbody::Render(HDC _hdc)
    {
        return true;
    }
}