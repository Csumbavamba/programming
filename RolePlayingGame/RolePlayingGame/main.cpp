#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

#include "Player.h"
#include "Map.h"

int main()
{
	srand(static_cast<int>(time(0)));

	Map gameMap;
	Player player;

	player.CreateClass();

	bool gameOver = false;

	while (!gameOver)
	{
		// Each loop cycle we output the player position and
		// a selection menu.
		gameMap.PrintPlayerPosition();

		int selection = 1;
		std::cout << "----------------" << std::endl;
		std::cout << " MAIN MENU " << std::endl;
		std::cout << "----------------" << std::endl;
		std::cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: ";
		std::cout << std::endl << "choice: ";
		std::cin >> selection;

		Monster* monster = 0;


		switch (selection)
		{
		case 1: // Move
		{
			gameMap.MovePlayer();
			/*
			Check for a random encounter. This function
			returns a null pointer if no monsters are
			encountered.
			*/
			monster = gameMap.CheckRandomEncounter();

			// If there is an encounter, fight breaks out.
			if (monster != 0)
			{
				while (true)
				{
					// Display hitpoints
					player.DisplayHitPoints();
					monster->DisplayHitPoints();
					std::cout << std::endl;

					// Player attacks first
					bool ranAway = player.Attack(*monster);

					if (ranAway)
					{
						break;
					}

					// Player won, drop XP
					if (monster->IsDead())
					{
						player.BattleWon(monster->DropExperience());
						player.LevelUp();

						break;
					}

					// Monster's turn to attack
					monster->Attack(player);

					// Player died
					if (player.IsDead())
					{
						player.GameOver();
						gameOver = true;
						break;
					}



				}

				delete  monster;
				monster = 0;
			}
			break;
		}
		case 2: // Rest
		{
			player.Rest();
			break;
		}
		case 3: // View Stats
		{
			player.ViewStats();
			break;
		}
		case 4: // Quit
		{
			gameOver = true;
			break;
		}
		}		
	}

	return 0;
}