#pragma once

#ifndef __RPG_PLAYER_H__
#define __RPG_PLAYER_H__

#include "Weapon.h"
#include "Monster.h"

class Player
{
private:

	char name[MAXIMUM_NAME_LENGTH];
	char className[MAXIMUM_NAME_LENGTH];
	int accuracy;
	int currentHitPoints;
	int maximumHitPoints;
	int experience;
	int nextLevelExperience;
	int level;
	int armour;
	Weapon weapon;

public:

	Player();
	~Player();

	int GetArmour();
	bool IsDead();

	// Passive methods
	void TakeDamage(int damage);
	void LevelUp();
	void BattleWon(int experience);
	void GameOver();
	void DisplayHitPoints();

	// Active  methods
	void CreateClass();
	bool Attack(Monster& monster);
	void Rest();
	void ViewStats();

	


};

#endif // __RPG_PLAYER_H__