#pragma once

#ifndef __RPG_MAP_H__
#define __RPG_MAP_H__

#include "Weapon.h"
#include "Monster.h"


/*
	This class, Map, is used to represent or MODEL the game board of either
	the game world, part of the game world, or a dungeon in the game world in
	this example we will only have one single Map object one of Map's
	responsibilities is to keep track of the players WORLD POSITION (XY
	COORD) in doing so we make the Map object responsible for inputting the
	users movement input. Also, as a game board should know where objects are
	located within / on top of it, Map should know where the Monster
	objects are. Therefore, the Map class is responsible for handling enemy
	encounters.

	Further enhancements would be to define landmarks, or key areas, where
	you want something to happen. For example, (2, 3) could contain a
	dungeon, so if the player moves to (2, 3) the game could describe the
	dungeon, and ask the user if he wants to enter a town could be another
	example, with (4, 4) being a weaponsmith, (2, 2) being a tavern, etc.
*/

class Map
{
private:
	int playerPositionX;
	int playerPositionY;

public:
	Map();
	~Map();

	int GetPlayerPositionX();
	int GetPlayerPositionY();
	void MovePlayer();
	Monster * CheckRandomEncounter();
	void PrintPlayerPosition();
};

#endif // __RPG_MAP_H__