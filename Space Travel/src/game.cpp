#include "game.h"

#include <raylib.h>

#include "consts.h"
#include "screens.h"

#include "mainMenu.h"
#include "gameplay.h"

namespace run
{
	void game()
	{
		InitWindow(screen::width, screen::height, "SPACE TRAVEL");

		object::Player player;

		std::vector <object::Obstacle> obstacles = { };

		playerFunctions::setDefault(player);

		bool shouldClose = false;


		SCREENS currentScreen = MAIN_MENU;

		while (!WindowShouldClose())
		{
			BeginDrawing();

			ClearBackground(BLACK);

			switch (currentScreen)
			{
			case MAIN_MENU:

				run::mainMenu(currentScreen);

				break;
			case GAMEPLAY:
				
				run::gameplay(currentScreen, player, obstacles);
				
				break;
			case CREDITS:



				break;
			case EXIT:				
				
				shouldClose = true;
				
				break;
			default:
				break;
			}

			DrawText("Version 0.1", 10, screen::height - 30, 20, RED);

			EndDrawing();

			if (shouldClose)
				CloseWindow();
		}
	}
}