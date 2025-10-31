#include "game.h"

#include <raylib.h>

#include "consts.h"
#include "screens.h"

#include "gameplay.h"

namespace run
{
	void game()
	{
		InitWindow(screen::width, screen::height, "SPACE TRAVEL");

		object::Player player;

		std::vector <object::Obstacle> obstacles = { };

		playerFunctions::setDefault(player);

		SCREENS currentScreen = GAMEPLAY;

		while (!WindowShouldClose())
		{
			switch (currentScreen)
			{
			case MAIN_MENU:



				break;
			case GAMEPLAY:
				
				run::gameplay(currentScreen, player, obstacles);
				
				break;
			case EXIT:
				
				CloseWindow();
				
				break;
			default:
				break;
			}
		}
	}
}