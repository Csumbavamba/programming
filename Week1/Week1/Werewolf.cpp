#include <iostream>

#include "Werewolf.h"


Werewolf::Werewolf()
{
	std::cout << "Werewolf default constructor invoked" << std::endl;
}

Werewolf::Werewolf(const char * name, int hitPoints, int experience, int pulse, int biteDamage)
	: Alive(name, hitPoints, experience, pulse)
	, biteDamage(biteDamage)
{
	std::cout << "Werewolf init constructor invoked" << std::endl;
}


Werewolf::~Werewolf()
{
	std::cout << "Werewolf destructor invoked" << std::endl;
}
/*
void Werewolf::Attack()
{
	std::cout << "Werewolf Attacked!" << std::endl;
}
*/

int Werewolf::GetBiteDamage() const
{
	return biteDamage;
	std::cout << "Werewolf GetBiteDamage called" << std::endl;
}

void Werewolf::SetBiteDamage(int newBiteDamage)
{
	biteDamage = newBiteDamage;
	std::cout << "Werewolf SetBiteDamage called" << std::endl;
}

void Werewolf::Type()
{
	std::cout << "Werewolf" << std::endl;
}
