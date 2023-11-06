#pragma once
#include "Character.h"

class NonPersonCharacter: public Character
{
public:
	void	SetHealth(float p);
	void	SetMana(float p);
	void	SetAttackPower(float p);
	void	SetDefensivePower(float p);
	virtual	~NonPersonCharacter();
};

