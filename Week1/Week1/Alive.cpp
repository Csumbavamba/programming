#include <iostream>

#include "Alive.h"




Alive::Alive()
{
	std::cout << "Alive default constructor invoked" << std::endl;
}

Alive::Alive(const char * name, int hitPoints, int experience, int pulse)
	: Enemy(name, hitPoints, experience)
	, pulse(pulse)
{
	std::cout << "Alive init constructor invoked" << std::endl;
}


Alive::~Alive()
{
	std::cout << "Alive destructor invoked" << std::endl;
}

int Alive::GetPulse() const
{
	return pulse;
	std::cout << "Alive getting pulse" << std::endl;
}

void Alive::SetPulse(int newPulse)
{
	pulse = newPulse;
	std::cout << "Alive setting pulse" << std::endl;
}

void Alive::Type()
{
	std::cout << "Alive" << std::endl;
}
