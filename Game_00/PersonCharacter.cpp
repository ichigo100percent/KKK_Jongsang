#include "PersonCharacter.h"

PersonCharacter::~PersonCharacter()
{
	std::cout << "해제자 호출" << std::endl;
}

void PersonCharacter::SetExperience(float p)
{
	m_fExperience = p;
}

float PersonCharacter::GetExperience()
{
	return m_fExperience;
}

void PersonCharacter::SetHealth(float p)
{
	Character::SetHealth(p + 50.0f);
}

void PersonCharacter::SetMana(float p)
{
	Character::SetMana(p + 50.0f);
}

void PersonCharacter::SetAttackPower(float p)
{
	Character::SetAttackPower(p + 50.0f);
}

void PersonCharacter::SetDefensivePower(float p)
{
	Character::SetDefensivePower(p + 50.0f);
}

