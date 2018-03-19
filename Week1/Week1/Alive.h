#pragma once
#ifndef __ALIVE_H__
#define __ALIVE_H__

#include "Enemy.h"

class Alive : public Enemy
{
private:
	int pulse;

public:
	Alive();
	Alive(const char * name, int hitPoints, int experience, int pulse);
	virtual ~Alive();

	int GetPulse() const;
	void SetPulse(int newPulse);
	void Type();
};

#endif // __ALIVE_H__