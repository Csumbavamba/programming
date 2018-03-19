#include <iostream>

#include "Enemy.h"




Enemy::Enemy() 
	: hitPoints(0)
	, experience(0)
{
	SetName("Default");

	std::cout << "Enemy default constructor invoked" << std::endl;
}

Enemy::Enemy(const char * name, int hitPoints, int experience)
	: hitPoints(hitPoints)
	, experience(experience)
{
	SetName(name);

	std::cout << "Enemy init constructor invoked" << std::endl;
}


Enemy::~Enemy()
{
	std::cout << "Enemy destructor invoked" << std::endl;
}

const char * Enemy::GetName() const
{
	return name;
}

void Enemy::SetName(const char * newName)
{
	// Set copies newName to the location of name, that is not longer than 20
	strncpy_s(name, newName, MAXIMUM_CHARACTERS);
}


void Enemy::Attack() const
{
	std::cout << "Enemy Attacks!" << std::endl;
}

int Enemy::GetHitPoints() const
{
	return hitPoints;
}

void Enemy::SetHitPoints(int newHitPoints)
{
	hitPoints = newHitPoints;
}

int Enemy::GetExperience() const
{
	return experience;
}

void Enemy::SetExperience(int newExperience)
{
	experience = newExperience;
}

void Enemy::Type()
{
	std::cout << "Enemy" << std::endl;
}
