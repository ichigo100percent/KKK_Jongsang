#include "NonPersonCharacter.h"

void NonPersonCharacter::SetHealth(float p)
{
	Character::SetHealth(p - 10.0f);
}

void NonPersonCharacter::SetMana(float p)
{
	Character::SetMana(p - 10.0f);
}

void NonPersonCharacter::SetAttackPower(float p)
{
	Character::SetAttackPower(p - 10.0f);
}

void NonPersonCharacter::SetDefensivePower(float p)
{
	Character::SetDefensivePower(p - 10.0f);
}

NonPersonCharacter::~NonPersonCharacter()
{
	std::cout << "해제자 호출" << std::endl;
}
