#pragma once

#ifndef __RPG_MONSTER_H__
#define __RPG_MONSTER_H__

#include "Weapon.h"

/*
	this is a forward class declaration
	it allows us to use the CPlayer without having defined it
	similiar to the way we use FUNCTION DECLARATIONS above main()
	then define it after main. ( Trick the compiler )
*/

// Forward Declaration
class Player;

class Monster
{
private:
	char name[MAXIMUM_NAME_LENGTH];
	int hitPoints;
	int accuracy;
	int experienceReward;
	int armour; // TODO rename to defense
	Weapon weapon;

public:
	Monster(const char* name, int currentHitPoints, int accuracy,
		int experience, int armour, const char* weaponName,
		int damageLowest, int damageHighest);
	~Monster();

	// void GenerateMonsterStats();
	const char * GetName();
	int GetArmour();

	bool IsDead();
	int DropExperience();

	void Attack(Player& player);
	void TakeDamage(int damage);
	void DisplayHitPoints();
	
};

#endif // __RPG_MONSTER_H__