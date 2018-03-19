#include <iostream>
#include <windows.h>

#include "Map.h"
#include "Random.h"



Map::Map()
{
	// Player starts in the origin
	playerPositionX = 0;
	playerPositionY = 0;
}


Map::~Map()
{
}

int Map::GetPlayerPositionX()
{
	return playerPositionX;
}

int Map::GetPlayerPositionY()
{
	return playerPositionY;
}

void Map::MovePlayer()
{
	int direction = 1;

	std::cout << "-----------------" << std::endl;
	std::cout << " MOVE PLAYER " << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "1) North, 2) East, 3) South, 4) West: ";
	std::cout << std::endl << "choice: ";
	std::cin >> direction;

	// Update coordinates based on selection.
	switch (direction)
	{
	case 1: // North
		playerPositionY++;
		break;
	case 2: // East
		playerPositionX++;
		break;
	case 3: // South
		playerPositionY--;
		break;
	default: // West
		playerPositionX--;
		break;
	}
	std::cout << std::endl;
}

Monster * Map::CheckRandomEncounter()
{
	int roll = Random(0, 20);

	Monster * monster = 0;

	if (roll <= 5)
	{
		// No encounter, return a null pointer.
		return nullptr;
	}
	else if (roll >= 6 && roll <= 10)
	{
		monster = new Monster("Orc", 10, 8, 200, 1, "Short Sword", 2, 7);
		std::cout << "You encountered an " << monster->GetName() << "!" << std::endl;
		std::cout << "Prepare for battle!" << std::endl;
		std::cout << std::endl;
	}
	else if (roll >= 11 && roll <= 15)
	{
		monster = new Monster("Goblin", 6, 6, 100, 0, "Dagger", 1, 5);
		std::cout << "You encountered a " << monster->GetName()	<< "!" << std::endl;
		std::cout << "Prepare for battle!" << std::endl;
		std::cout << std::endl;
	}
	else if (roll >= 16 && roll <= 19)
	{
		monster = new Monster("Ogre", 20, 12, 500, 2, "Club", 3, 8);
		std::cout << "You encountered an " << monster->GetName()	<< "!" << std::endl;
		std::cout << "Prepare for battle!" << std::endl;
		std::cout << std::endl;
	}
	else if (roll == 20)
	{
		monster = new Monster("Orc Lord", 25, 15, 2000, 5, "Two Handed Sword", 5, 20);
		std::cout << "You encountered a " << monster->GetName()	<< "!" << std::endl;
		std::cout << "Prepare for battle!" << std::endl;
		std::cout << std::endl;
	}

	return monster;
}

void Map::PrintPlayerPosition()
{
	std::cout << "Player Position = (" << playerPositionX << ", " << playerPositionY << ")" << std::endl << std::endl;
}
