#include <iostream>

#include "Human.h"



Human::Human()
{
	std::cout << "Human default constructor invoked" << std::endl;
}

Human::Human(const char * name, int hitPoints, int experience, int pulse, int magicDamage)
	: Alive(name, hitPoints, experience, pulse)
	, magicDamage(magicDamage)
{
	std::cout << "Human init constructor invoked" << std::endl;
}


Human::~Human()
{
	std::cout << "Human destructor invoked" << std::endl;
}

/*
void Human::Attack()
{
	std::cout << "Human attacked!" << std::endl;
}
*/

int Human::GetMagicDamage() const
{
	return magicDamage;
	std::cout << "Human GetMagicDamage called" << std::endl;
}

void Human::SetMagicDamage(int newMagicDamage)
{
	magicDamage = newMagicDamage;
	std::cout << "Human SetMagicDamage called" << std::endl;
}

void Human::Type()
{
	std::cout << "Human" << std::endl;
}
