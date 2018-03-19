#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

const int MAXIMUM_CHARACTERS = 20;

class Enemy
{
protected:
	char name[MAXIMUM_CHARACTERS];
	int hitPoints;
	int experience;

public:
	Enemy();
	Enemy(const char * name, int hitPoints, int experience);
	virtual ~Enemy();

	const char * GetName() const;
	void SetName(const char * newName);
	
	void Attack() const;
	int GetHitPoints() const;
	void SetHitPoints(int newHitPoints);

	int GetExperience() const;
	void SetExperience(int newExperience);

	virtual void Type();


};

#endif // __ENEMY__H__

