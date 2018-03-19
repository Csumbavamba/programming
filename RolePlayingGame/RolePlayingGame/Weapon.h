#pragma once

#ifndef __RPG_WEAPON_H__
#define __RPG_WEAPON_H__

#include "Range.h"

const int MAXIMUM_NAME_LENGTH = 20;

struct Weapon
{
	char name[MAXIMUM_NAME_LENGTH];
	Range damageRange;
};

#endif // __RPG_WEAPON_H__