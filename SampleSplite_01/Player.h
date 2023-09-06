#pragma once
#include "TPlaneObj.h"
#include "SpriteObj.h"
enum AnimState_Leg
{
    Idle_Leg, Forward, Back, Left, Right
};
enum AnimState_Body
{
    Idle=5 ,Aiming
};
class Player : public TPlaneObj
{
    using AnimList = std::vector<T_STR_VECTOR>;
    //0 = Leg Idle
    //1 = Leg Foward
    //2 = Leg Back
    //3 = Leg Left
    //4 = Leg Right;
    //5 = Body Idle
    //6 = Body Aim
public:
    TSpriteTexture* m_pSpriteLeg = new TSpriteTexture;
    TSpriteTexture* m_pSpriteBody = new TSpriteTexture;
    T_STR_VECTOR m_SpriteList;
    AnimList m_animList;
    AnimState_Leg m_LegAnimState = Idle_Leg;
    AnimState_Body m_BodyAnimState = Idle;

public:
    void CreateTexList(T_STR_VECTOR& TexList, W_STR FilePath , int s, int e); 
    void InsertLegAnim(T_STR_VECTOR TexList); //m_animList;¿¡ T_STR_VECTOR push
    void InsertBodyAnim(T_STR_VECTOR TexList);
    void SetLegAnimation();
    void SetBodyAnimation();
    void SetLegState(AnimState_Leg state, float fOffsetTime);
    void SetBodyState(AnimState_Body state, float fOffsetTime);


public:
    bool  Init();
    bool  Frame();
    bool  Render();
    bool  Release();
   
};

