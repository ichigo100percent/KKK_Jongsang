#include "Player.h"
#include "TInput.h"
bool Player::Frame()
{
    static bool wKeyPressed = false;
    static bool aKeyPressed = false;
    static bool sKeyPressed = false;
    static bool dKeyPressed = false;
    static bool NonPressed = false;
  


    // �̵� �ӵ�
    float speed = 500.0f * g_fSecondPerFrame;

    float diagonalSpeed = speed / std::sqrt(2.0f); // �밢�� �̵� �ӵ�

    if (TInput::GetInstance().m_dwKeyState['A'] > KEY_UP)
    {
        if (TInput::GetInstance().m_dwKeyState['A'] == KEY_PUSH)
        {
            SetLegState(Forward, 1.0f);
            aKeyPressed = true;
            NonPressed = true;
        }
        if (aKeyPressed)
        {
            if (TInput::GetInstance().m_dwKeyState['W'] > KEY_UP) //���� �� �밢��
            {
                m_vPos.x -= diagonalSpeed;
                m_vPos.y += diagonalSpeed;
                m_vRotation.z = DegreeToRadian(135.f);

            }
            else if (TInput::GetInstance().m_dwKeyState['S'] > KEY_UP) // ���� �Ʒ� �밢��
            {
                m_vPos.x -= diagonalSpeed;
                m_vPos.y -= diagonalSpeed;
                m_vRotation.z = DegreeToRadian(-135.0f);
            }
            else
            {
                m_vPos.x -= speed;
                m_vRotation.z = DegreeToRadian(180.0f);//����

            }
        }
    }
    else if (TInput::GetInstance().m_dwKeyState['D'] > KEY_UP)
    {
        if (TInput::GetInstance().m_dwKeyState['D'] == KEY_PUSH)
        {
            SetLegState(Forward, 1.0f);
            dKeyPressed = true;
            NonPressed = true;
        }
        if (dKeyPressed)
        {
            if (TInput::GetInstance().m_dwKeyState['W'] > KEY_UP) // ������ �� �밢��
            {
                m_vPos.x += diagonalSpeed;
                m_vPos.y += diagonalSpeed;
                m_vRotation.z = DegreeToRadian(45.0f);
            }
            else if (TInput::GetInstance().m_dwKeyState['S'] > KEY_UP) // ������ �Ʒ� �밢��
            {
                m_vPos.x += diagonalSpeed;
                m_vPos.y -= diagonalSpeed;
                m_vRotation.z = DegreeToRadian(-45.0f);
            }
            else                                                                                // ������
            {
                m_vPos.x += speed;
                m_vRotation.z = DegreeToRadian(0.f);
            }
        }
    }
    else if (TInput::GetInstance().m_dwKeyState['W'] > KEY_UP)
    {
        if (TInput::GetInstance().m_dwKeyState['W'] == KEY_PUSH)
        {
            SetLegState(Forward, 1.0f);
            wKeyPressed = true;
            NonPressed = true;
        }
        if (wKeyPressed)
        {
            m_vPos.y += speed;
            m_vRotation.z = DegreeToRadian(90.f);
        }
    }
    else if (TInput::GetInstance().m_dwKeyState['S'] > KEY_UP)
    {
        if (TInput::GetInstance().m_dwKeyState['S'] == KEY_PUSH)
        {
            SetLegState(Forward, 1.0f);
            sKeyPressed = true;
            NonPressed = true;
        }
        if (sKeyPressed)
        {
            m_vPos.y -= speed;
            m_vRotation.z = DegreeToRadian(-90.f);
        }
    }
    else
    {
        if (NonPressed) // ������ Ű�� ������ �ʾ��� ���� ����
        {
            SetLegState(Idle_Leg, 1.0f);
            NonPressed = false; // NonPressed�� true�� �����Ͽ� �� �̻� ������� �ʵ��� ��
        }
    }

    static bool MoustRbtPressed = false;
    static bool MoustNonePressed = true;
    MoustNonePressed = true;
    MoustRbtPressed = false;
    if (I_Input.m_dwKeyState[VK_RBUTTON] >= KEY_PUSH)
    {
        if (!MoustRbtPressed) // ������ Ű�� ������ �ʾ��� ���� ����
        {
            SetBodyState(Aiming, 5.0f);
            MoustRbtPressed = true;
        }
        
        TVector3 mousePos = { static_cast<float>(I_Input.m_MousePos.x), static_cast<float>(I_Input.m_MousePos.y), 0.0f };
        TVector2 vMouseWorldLT = { -400,
                           300 };
        mousePos.x = vMouseWorldLT.x + mousePos.x;
        mousePos.y = vMouseWorldLT.y - mousePos.y;
        TVector3 playerToMouse = mousePos - m_vPos;

        // atan2 �Լ��� ����Ͽ� �÷��̾�� ���콺������ ������ ���
        float angleRadians = std::atan2(playerToMouse.y, playerToMouse.x);
        m_pSpriteBody->m_vRotation.z = angleRadians ;
        this->m_vRotation.z= angleRadians;
    }
    else
    {
        if(MoustNonePressed)
        SetBodyState(Idle, 1.0f);
        static bool MoustNonePressed = false;
    }

    float fSizeHalfWidth = m_vScale.x;
    float fSizeHalfHeight = m_vScale.y;
    if (m_vPos.x < -g_fMapHalfSizeX + fSizeHalfWidth)
    {
        m_vPos.x = -g_fMapHalfSizeX + fSizeHalfWidth;
    }
    if (m_vPos.y < -g_fMapHalfSizeY + fSizeHalfHeight)
    {
        m_vPos.y = -g_fMapHalfSizeY + fSizeHalfHeight;
    }
    if (m_vPos.x > g_fMapHalfSizeX - fSizeHalfWidth)
    {
        m_vPos.x = g_fMapHalfSizeX - fSizeHalfWidth;
    }
    if (m_vPos.y > g_fMapHalfSizeY - fSizeHalfHeight)
    {
        m_vPos.y = g_fMapHalfSizeY - fSizeHalfHeight;
    }

    m_pSpriteLeg->Frame();
    m_pSpriteBody->Frame();
    // �浹������ ������Ʈ( ȸ�� ó�� �̹ݿ� )


    TVector2 rt = { m_vPos.x, m_vPos.y };
    SetRect(rt, m_vScale.x * 2.0f, m_vScale.y * 2.0f);

    TMatrix matScale, matRotation, matTranslate;
    matScale.Scale(m_vScale);
    matRotation.ZRotate(m_vRotation.z);
    matTranslate.Translation(m_vPos);
    m_matWorld = matScale * matRotation * matTranslate;
    m_pSpriteLeg->m_vPos = this->m_vPos;
    m_pSpriteLeg->m_vRotation = this->m_vRotation;
    
    m_pSpriteBody->m_vPos = this->m_vPos;
   if(!(I_Input.m_dwKeyState[VK_RBUTTON] >= KEY_PUSH))
        m_pSpriteBody->m_vRotation.z = this->m_vRotation.z;
        m_pSpriteLeg->m_vRotation.z = m_pSpriteBody->m_vRotation.z;
    
    return true;
    
}
void Player::CreateTexList(T_STR_VECTOR& TexList,W_STR FilePath , int s, int e) // ../../res/Leg/
{
    TexList.clear();
    for (int i = s; i <= e; i++)
        TexList.push_back(FilePath + std::to_wstring(i) + L".png");
        
}
void Player::InsertLegAnim(T_STR_VECTOR TexList)
{
    m_animList.push_back(TexList);

}
void Player::InsertBodyAnim(T_STR_VECTOR TexList)
{
    m_animList.push_back(TexList);

}
void Player::SetLegAnimation()
{
    if (m_LegAnimState == Idle_Leg)
    {
        m_pSpriteLeg->LoadTexArray(m_animList[0]);
    }
    else if (m_LegAnimState == Forward)
    {
        m_pSpriteLeg->LoadTexArray(m_animList[1]);
    }
    else if (m_LegAnimState == Back)
    {
        m_pSpriteLeg->LoadTexArray(m_animList[2]);
    }
    else if (m_LegAnimState == Left)
    {
        m_pSpriteLeg->LoadTexArray(m_animList[3]);
    }
    else if (m_LegAnimState == Right)
    {
        m_pSpriteLeg->LoadTexArray(m_animList[4]);
    }
       
}
void Player::SetBodyAnimation()
{
    if (m_BodyAnimState == Idle)
        m_pSpriteBody->LoadTexArray(m_animList[5]);
    else if (m_BodyAnimState == Aiming)
        m_pSpriteBody->LoadTexArray(m_animList[6]);
}


void Player::SetLegState(AnimState_Leg state, float fAnimTimer)
{
    m_pSpriteLeg->m_iCurrentAnimIndex = 0;
    m_pSpriteLeg->m_pTexList.clear();
    m_pSpriteBody->m_fAnimTimer = fAnimTimer;
  //  m_pSpriteLeg->m_fOffsetTime = fAnimTimer /  m_animList[state].size();
    m_pSpriteLeg->m_fElapsedTimer = 0.0f;
    
    m_LegAnimState = state;
    SetLegAnimation();
    
}
void Player::SetBodyState(AnimState_Body state, float fAnimTimer)
{
    m_pSpriteBody->m_iCurrentAnimIndex = 0;
    m_pSpriteBody->m_pTexList.clear();
 //   m_pSpriteBody->m_fOffsetTime = fAnimTimer / m_animList[state].size();
    m_pSpriteBody->m_fElapsedTimer = 0.0f;
    m_pSpriteBody->m_fAnimTimer = fAnimTimer;
    m_BodyAnimState = state;
    SetBodyAnimation();

}
bool Player::Init()
{

    TSpriteInfo info;
    info.p = { 0.0f,0.0f ,0.0f };
    info.s = TVector3(50.0f, 50.0f, 1.0f);
    info.fAnimTimer = 1.0f;
    info.shaderFile = L"../../res/shader/Plane.hlsl";
    info.texFile = L"../../res/Leg/1.png";
    CreateTexList(info.texList, L"../../res/Leg/", 61, 75);
    InsertLegAnim(info.texList);
    m_pSpriteLeg->Load(m_pDevice, m_pImmediateContext, info);
    CreateTexList(info.texList, L"../../res/Leg/", 1, 16);
    InsertLegAnim(info.texList);
    CreateTexList(info.texList, L"../../res/Leg/", 16, 30);
    InsertLegAnim(info.texList);
    CreateTexList(info.texList, L"../../res/Leg/", 31, 46);
    InsertLegAnim(info.texList);
    CreateTexList(info.texList, L"../../res/Leg/", 47, 62);
    InsertLegAnim(info.texList);
 

    info.p = { 0.0f,0.0f ,0.0f };
    info.s = TVector3(100, 100, 1.0f);
    info.fAnimTimer = 1.0f;
    info.shaderFile = L"../../res/shader/Plane.hlsl";
    info.texFile = L"../../res/Body/1.png";
    CreateTexList(info.texList, L"../../res/Body/", 76, 76);
    InsertBodyAnim(info.texList);
    m_pSpriteBody->Load(m_pDevice, m_pImmediateContext, info);
    CreateTexList(info.texList, L"../../res/Body/", 78, 87);
    InsertBodyAnim(info.texList);
  
    return true;
}
bool Player::Render()
{
  
    
    TPlaneObj::Render();
    m_pSpriteLeg->Render();
    m_pSpriteBody->Render();
    
    return true;
}
bool Player::Release()
{
    return true;
}