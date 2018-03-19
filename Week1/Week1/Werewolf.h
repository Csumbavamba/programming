#pragma once
#ifndef __WEREWOLF_H__
#define __WEREWOLF_H__

#include "Alive.h"

class Werewolf : public Alive
{
private:
	int biteDamage;
public:
	Werewolf();
	Werewolf(const char * name, int hitPoints, int experience, int pulse, int biteDamage);
	virtual ~Werewolf();

	// virtual void Attack();

	int GetBiteDamage() const;
	void SetBiteDamage(int newBiteDamage);
	void Type();
};

#endif // __WEREWOLF_H__