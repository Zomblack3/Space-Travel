#include "gameplay.h"

namespace run
{
	void gameplay(SCREENS& currentScreen, object::Player& player)
	{
		basicFunctions::update(currentScreen, player);

		basicFunctions::draw(player);
	}
}

namespace basicFunctions
{
	void update(SCREENS& currentScreen, object::Player& player)
	{
		float deltaTime = GetFrameTime();

		playerFunctions::move(player, deltaTime);
		playerFunctions::rotate(player, deltaTime);

		if (IsKeyPressed(KEY_ESCAPE))
			currentScreen = EXIT;
	}

	void draw(object::Player player)
	{
		BeginDrawing();

		ClearBackground(BLACK);

		playerFunctions::draw(player);

		EndDrawing();
	}
}