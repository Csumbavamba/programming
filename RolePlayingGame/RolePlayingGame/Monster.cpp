#include <iostream>

#include "Monster.h"
#include "Player.h"
#include "Random.h"



Monster::Monster(const char* name, int currentHitPoints, int accuracy,
	int experience, int armour, const char* weaponName,
	int damageLowest, int damageHighest)
{
	strncpy_s(this->name, name, MAXIMUM_NAME_LENGTH - 1);
	this->hitPoints = currentHitPoints;
	this->accuracy = accuracy;
	this->experienceReward = experience;
	this->armour = armour;
	strncpy_s(weapon.name, weaponName, MAXIMUM_NAME_LENGTH - 1);
	weapon.damageRange.lowest = damageLowest;
	weapon.damageRange.highest = damageHighest;
}


Monster::~Monster()
{
}

const char * Monster::GetName()
{
	return name;
}

int Monster::GetArmour()
{
	return armour;
}

bool Monster::IsDead()
{
	return (hitPoints <= 0);
}

int Monster::DropExperience()
{
	return experienceReward;
}

void Monster::Attack(Player & player)
{
	std::cout << "A " << name << " attacks you with a " << weapon.name << std::endl;

	// Roll the D20 to see if the the monster  hit the player
	if (Random(0, 20) < accuracy)
	{
		// Generate damage value based on weapon range
		int damage = Random(weapon.damageRange);

		// Subtract the players armour from the damage (if the value is negative EG armour > damage, there was no damage done)
		int totalDamage = damage - player.GetArmour(); // TODO declare and define function

		if (totalDamage <= 0)
		{
			std::cout << "The monster's attack failed to penetrate your armour." << std::endl;
		}
		else
		{
			std::cout << "You were hit for " << totalDamage << "damage!!" << std::endl;

			// Subtract from player's hitpoints
			player.TakeDamage(totalDamage); // TODO declare and define function
		}
	}
	// if the the number is higher than the accuracy, monster failed to make damage
	else
	{
		std::cout << "The " << name << " missed." << std::endl;
	}

}

void Monster::TakeDamage(int damage)
{
	hitPoints -= damage;
}

void Monster::DisplayHitPoints()
{
	std::cout << name << "'s hitpoints = " << hitPoints << std::endl;
}
