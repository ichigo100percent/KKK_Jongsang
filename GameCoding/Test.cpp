#include "pch.h"
#include "Test.h"
#include "InputManager.h"
#include "GameObject.h"

void Test::Awake()
{

}

void Test::Update()
{
    //// ������ �ӵ��� �����մϴ�.
    //float moveSpeed = 0.001f;

    //// Transform ������Ʈ�� �����ɴϴ�.
    //auto transform = GetGameObject()->GetTransform();

    //// ���� ���� ������Ʈ�� ��ġ�� �����ɴϴ�.
    //Vec3 currentPosition = transform->GetPosition();

    //// ��ġ�� ������Ʈ�Ͽ� ���������� �̵��ϵ��� �մϴ�.
    //currentPosition.x += moveSpeed;

    //// ���ο� ��ġ�� �����մϴ�.
    //transform->SetPosition(currentPosition);

    MoveObjectForward();
    
    //// Ű �Է� �Ŵ����� �����ɴϴ�. (���⼭�� ���� ���� ������ �����´ٰ� �����մϴ�)
    auto inputManager = InputManager::GetInstance();

    //// Ű �Է� ���¸� Ȯ���Ͽ� ������Ʈ �̵�
    //if (inputManager.GetButton(KEY_TYPE::D)) // W Ű�� ������ ��
    //{
    //    MoveObjectForward(); // ������ �̵�
    //}
    //if (inputManager.GetButton(KEY_TYPE::A)) // A Ű�� ������ ��
    //{
    //    //MoveObjectLeft(); // �������� �̵�
    //}
    //if (inputManager.GetButton(KEY_TYPE::S)) // S Ű�� ������ ��
    //{
    //    //MoveObjectBackward(); // �ڷ� �̵�
    //}
    //if (inputManager.GetButton(KEY_TYPE::D)) // D Ű�� ������ ��
    //{
    //    //MoveObjectRight(); // ���������� �̵�
    //}
}

void Test::MoveObjectForward()
{
    // ������ �ӵ��� �����մϴ�.
    float moveSpeed = 0.05f;



    // Transform ������Ʈ�� �����ɴϴ�.
    auto transform = GetGameObject()->GetTransform();

    // ���� ���� ������Ʈ�� ��ġ�� �����ɴϴ�.
    Vec3 currentPosition = transform->GetPosition();

    // ��ġ�� ������Ʈ�Ͽ� ���������� �̵��ϵ��� �մϴ�.
    currentPosition.x += moveSpeed;
    //currentPosition.y += moveSpeed;
    // ���ο� ��ġ�� �����մϴ�.
    transform->SetPosition(currentPosition);
}