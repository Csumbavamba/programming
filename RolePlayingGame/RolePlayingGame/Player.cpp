#include <iostream>
#include <windows.h>

#include "Player.h"
#include "random.h"



Player::Player()
{
	strncpy_s(name, "Default", MAXIMUM_NAME_LENGTH - 1);
	strncpy_s(className, "Default", MAXIMUM_NAME_LENGTH - 1);

	accuracy = 0;
	currentHitPoints = maximumHitPoints = 0;
	experience = 0;
	nextLevelExperience = 0;
	level = 0;
	armour = 0;

	strncpy_s(weapon.name, "Default weapon name", MAXIMUM_NAME_LENGTH - 1);
	weapon.damageRange.lowest = 0;
	weapon.damageRange.highest = 0;

}


Player::~Player()
{
}

int Player::GetArmour()
{
	return armour;
}

bool Player::IsDead()
{
	return (currentHitPoints <= 0);
}

void Player::TakeDamage(int damage)
{
	currentHitPoints -= damage;
}

void Player::LevelUp()
{
	if (experience >= nextLevelExperience)
	{
		std::cout << "You gained a level!" << std::endl;

		level++;

		// Set next experience goal
		nextLevelExperience = level * level * 1000;

		// Increase stats randomly
		accuracy += Random(1, 3);
		maximumHitPoints += Random(2, 6);
		armour += Random(1, 2);

		// Give player full HP when they level up
		currentHitPoints = maximumHitPoints;
	}
}

void Player::BattleWon(int experience)
{
	std::cout << "You defeated your enemy!" << std::endl;
	std::cout << "You gained " << experience << " experience points!" << std::endl << std::endl;
	
	this->experience += experience;
}

void Player::GameOver()
{
	std::cout << "You died in battle...." << std::endl;
	std::cout << std::endl;

	std::cout << "------------" << std::endl;
	std::cout << "GAME OVER!!!" << std::endl;
	std::cout << "------------" << std::endl;

	std::cout << "Press q to quit the game: ";
	char quit = 'q';
	std::cin >> quit;

	std::cout << std::endl;
}

void Player::DisplayHitPoints()
{
	std::cout << name << "'s hitpoints: " << currentHitPoints << std::endl;
}

void Player::CreateClass()
{
	std::cout << "==========================" << std::endl;
	std::cout << "CHARACTER CLASS GENERATION" << std::endl;
	std::cout << "==========================" << std::endl;

	// Input character's name
	std::cout << "Enter your character's name: ";

	scanf_s("%s", name, MAXIMUM_NAME_LENGTH);

	// Character selection
	std::cout << "Please select a character class number..." << std::endl;
	std::cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";
	std::cout << std::endl << "choice: ";

	int characterNumber = 1;
	std::cin >> characterNumber;

	switch (characterNumber)
	{
	case 1: // Fighter
	{
		strncpy_s(className, "Fighter", MAXIMUM_NAME_LENGTH - 1);
		accuracy = 13;
		currentHitPoints = 22;
		maximumHitPoints = 25;
		experience = 0;
		nextLevelExperience = 1000;
		level = 1;
		armour = 4;
		strncpy_s(weapon.name, "Long Sword", MAXIMUM_NAME_LENGTH - 1);
		weapon.damageRange.lowest = 1;
		weapon.damageRange.highest = 8;
		break;
	}
	case 2: // Wizard
	{
		strncpy_s(className, "Wizard", MAXIMUM_NAME_LENGTH - 1);
		accuracy = 5;
		currentHitPoints = 10;
		maximumHitPoints = 10;
		experience = 0;
		nextLevelExperience = 1000;
		level = 1;
		armour = 1;
		strncpy_s(weapon.name, "Staff", MAXIMUM_NAME_LENGTH - 1);
		weapon.damageRange.lowest = 1;
		weapon.damageRange.highest = 4;
		break;
	}
	case 3: // Cleric
	{
		strncpy_s(className, "Cleric", MAXIMUM_NAME_LENGTH - 1);
		accuracy = 8;
		currentHitPoints = 15;
		maximumHitPoints = 15;
		experience = 0;
		nextLevelExperience = 1000;
		level = 1;
		armour = 3;
		strncpy_s(weapon.name, "Flail", MAXIMUM_NAME_LENGTH - 1);
		weapon.damageRange.lowest = 1;
		weapon.damageRange.highest = 6;
		break;
	}
	default: // Thief
	{
		strncpy_s(className, "Thief", MAXIMUM_NAME_LENGTH - 1);
		accuracy = 7;
		currentHitPoints = 12;
		maximumHitPoints = 12;
		experience = 0;
		nextLevelExperience = 1000;
		level = 1;
		armour = 2;
		strncpy_s(weapon.name, "Short Sword", MAXIMUM_NAME_LENGTH - 1);
		weapon.damageRange.lowest = 1;
		weapon.damageRange.highest = 6;
		break;
	}

	}
}

bool Player::Attack(Monster & monster)
{
	/*
		Combat is turned based: display an options menu. You can,
		of course, extend this to let the player use an item,
		cast a spell, and so on.
	*/

	int selection = 1;

	std::cout << "1) Attack, 2) Run: ";
	std::cout << std::endl << std::endl;
	std::cin >> selection;
	std::cout << std::endl;

	switch (selection)
	{
	case 1: // Attacking
	{
		std::cout << "You decided to attack an " << monster.GetName() << " with a " << weapon.name << std::endl;

		if (Random(0, 20) < accuracy)
		{
			int damage = Random(weapon.damageRange);
			int totalDamage = damage - armour;

			if (totalDamage <= 0)
			{
				std::cout << "Your attack failed to penetrate "	<< "the armor." << std::endl;
			}
			else
			{
				std::cout << "Your attack dealt " << totalDamage << " damage!" << std::endl;

				// Subtract from monster's hitpoints.
				monster.TakeDamage(totalDamage);
			}
		}
		else
		{
			std::cout << "You missed!" << std::endl;
		}
		std::cout << std::endl;
		break;
	}
	case 2: // Running
	{
		// 25 % chance of being able to run.
		int roll = Random(1, 4);

		if (roll == 1)
		{
			std::cout << "You run away!" << std::endl;
			return (true);//<--Return out of the function.
		}
		else
		{
			std::cout << "You could not escape!" << std::endl;
			break;
		}
	}
	}
	return false;
}

void Player::Rest()
{
	std::cout << "Resting...." << std::endl;

	currentHitPoints = maximumHitPoints;

	// TODO modify function so that you can be encountered by an enemy while resting
}

void Player::ViewStats()
{
	std::cout << "------------" << std::endl;
	std::cout << "PLAYER STATS" << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Name:					" << name << std::endl;
	std::cout << "Class:				" << className << std::endl;
	std::cout << "Accuracy:				" << accuracy << std::endl;
	std::cout << "HitPoints:			" << currentHitPoints << std::endl;
	std::cout << "MaxHitPoints:			" << maximumHitPoints << std::endl;
	std::cout << "Experience:			" << experience << std::endl;
	std::cout << "XP for next level:	" << nextLevelExperience << std::endl;
	std::cout << "Level:				" << level << std::endl;
	std::cout << "Armour:				" << armour << std::endl;
	std::cout << "Weapon Name:			" << weapon.name << std::endl;
	std::cout << "Weapon Damage:		" << weapon.damageRange.lowest << " - " << weapon.damageRange.highest << std::endl;

	std::cout << std::endl;
}
