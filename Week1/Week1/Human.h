#pragma once
#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "Alive.h"

class Human : public Alive
{
private:
	int magicDamage;
public:
	Human();
	Human(const char * name, int hitPoints, int experience, int pulse, int magicDamage);
	virtual ~Human();

	// virtual void Attack();

	int GetMagicDamage() const;
	void SetMagicDamage(int newMagicDamage);
	virtual void Type();
};

#endif // __HUMAN_H__