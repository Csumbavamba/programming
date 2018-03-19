#include <iostream>

#include "Enemy.h"
#include "Werewolf.h"
#include "Human.h"

void TestDynamicCast(Enemy * enemy)
{
	// if castable it will return a true
	Human * human = dynamic_cast<Human*>(enemy);

	if (human)
	{
		std::cout << "human passed in" << std::endl;

		human->SetMagicDamage(500);
	}
	else
	{
		std::cout << "NOT A HUMAN!" << std::endl;
	}

	Werewolf * werewolf = dynamic_cast<Werewolf*>(enemy);

	if (werewolf)
	{
		std::cout << "Werewolf passed in" << std::endl;

		werewolf->SetBiteDamage(600);
	}
	else
	{
		std::cout << "NOT A WEREWOLF!" << std::endl;
	}
}

int main()
{
	const int MAX_BADDIES = 10;

	Enemy * baddies [MAX_BADDIES];

	baddies[0] = new Werewolf("Ror", 35, 200, 180, 5);     
	baddies[1] = new Werewolf("Bor", 25, 200, 180, 3);     
	baddies[2] = new Werewolf("Tor", 45, 200, 180, 4);     
	baddies[3] = new Werewolf("Gor", 15, 200, 180, 8);     
	baddies[4] = new Werewolf("Mor", 33, 200, 180, 6);

	baddies[5] = new Human("Joe", 10, 50, 110, 15);     
	baddies[6] = new Human("Jim", 11, 50, 110, 11);
	baddies[7] = new Human("Snake", 12, 50, 110, 12);     
	baddies[8] = new Human("Luke", 9, 50, 110, 13);     
	baddies[9] = new Human("Duke", 8, 50, 110, 13);

	TestDynamicCast(baddies[1]);
	TestDynamicCast(baddies[5]);

	for (int i = 0; i < MAX_BADDIES; i++)
	{
		std::cout << baddies[i]->GetName();
		std::cout << "'s type is: "; 
		baddies[i]->Type();
	}

	for (int i = 0; i < MAX_BADDIES; i++)
	{
		delete baddies[i];
		baddies[i] = 0;
	}

	int wait;
	std::cin >> wait;

	return 0;
}