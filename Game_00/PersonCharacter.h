#pragma once
#include "Character.h"

class PersonCharacter : public Character
{
public:
	float		m_fExperience;
public:
	virtual		~PersonCharacter();

	void		SetExperience(float p);
	float		GetExperience();

	void		SetHealth(float p) override;
	void		SetMana(float p) override;
	void		SetAttackPower(float p) override;
	void		SetDefensivePower(float p) override;	
};

