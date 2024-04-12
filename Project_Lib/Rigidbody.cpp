#include "Rigidbody.h"
#include "JSTime.h"
#include "Transform.h"
#include "JSGameObject.h"

namespace J
{
    Rigidbody::Rigidbody()
        : Component(enums::eComponentType::Rigidbody)
        , m_bGround(false)
        , m_Mass(1.0f)
        , m_Friction(10.0f)
        , m_Force(Vector2::Zero)
        , m_Velocity(Vector2::Zero)
        , m_LimitedVelocity(Vector2(200.0f, 1000.0f))
        , m_Gravity(Vector2(0.0f, 800.0f))
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

        if (m_bGround)
        {
            //�� ���� ������
            Vector2 gravity = m_Gravity;
            gravity.normalize();

            float dot = Vector2::Dot(m_Velocity, gravity);
            m_Velocity -= gravity * dot;
        }
        else
        {
            //���߿� ������
            m_Velocity += m_Gravity * Time::DeltaTime();
        }

        //�ִ� �ӵ� ����
        Vector2 gravity = m_Gravity;
        gravity.normalize();
        float dot = Vector2::Dot(m_Velocity, gravity);
        gravity = gravity * dot;

        Vector2 sideVelocity = m_Velocity - gravity;
        if (m_LimitedVelocity.y < gravity.length())
        {
            gravity.normalize();
            gravity *= Time::DeltaTime();
        }
        if (m_LimitedVelocity.x < sideVelocity.length())
        {
            sideVelocity.normalize();
            sideVelocity *= m_LimitedVelocity.x;
        }
        m_Velocity = gravity + sideVelocity;


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