#include "pch.h"
#include "Test.h"
#include "InputManager.h"
#include "GameObject.h"

void Test::Awake()
{

}

void Test::Update()
{
    //// 움직일 속도를 설정합니다.
    //float moveSpeed = 0.001f;

    //// Transform 컴포넌트를 가져옵니다.
    //auto transform = GetGameObject()->GetTransform();

    //// 현재 게임 오브젝트의 위치를 가져옵니다.
    //Vec3 currentPosition = transform->GetPosition();

    //// 위치를 업데이트하여 오른쪽으로 이동하도록 합니다.
    //currentPosition.x += moveSpeed;

    //// 새로운 위치를 설정합니다.
    //transform->SetPosition(currentPosition);

    MoveObjectForward();
    
    //// 키 입력 매니저를 가져옵니다. (여기서는 전역 변수 등으로 가져온다고 가정합니다)
    auto inputManager = InputManager::GetInstance();

    //// 키 입력 상태를 확인하여 오브젝트 이동
    //if (inputManager.GetButton(KEY_TYPE::D)) // W 키가 눌렸을 때
    //{
    //    MoveObjectForward(); // 앞으로 이동
    //}
    //if (inputManager.GetButton(KEY_TYPE::A)) // A 키가 눌렸을 때
    //{
    //    //MoveObjectLeft(); // 왼쪽으로 이동
    //}
    //if (inputManager.GetButton(KEY_TYPE::S)) // S 키가 눌렸을 때
    //{
    //    //MoveObjectBackward(); // 뒤로 이동
    //}
    //if (inputManager.GetButton(KEY_TYPE::D)) // D 키가 눌렸을 때
    //{
    //    //MoveObjectRight(); // 오른쪽으로 이동
    //}
}

void Test::MoveObjectForward()
{
    // 움직일 속도를 설정합니다.
    float moveSpeed = 0.05f;



    // Transform 컴포넌트를 가져옵니다.
    auto transform = GetGameObject()->GetTransform();

    // 현재 게임 오브젝트의 위치를 가져옵니다.
    Vec3 currentPosition = transform->GetPosition();

    // 위치를 업데이트하여 오른쪽으로 이동하도록 합니다.
    currentPosition.x += moveSpeed;
    //currentPosition.y += moveSpeed;
    // 새로운 위치를 설정합니다.
    transform->SetPosition(currentPosition);
}