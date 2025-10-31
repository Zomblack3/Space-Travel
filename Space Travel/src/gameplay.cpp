#include "gameplay.h"

#include "consts.h"

namespace run
{
	void gameplay(SCREENS& currentScreen, object::Player& player, std::vector <object::Obstacle>& obstacles)
	{
		basicFunctionsGameplay::update(currentScreen, player, obstacles);

		basicFunctionsGameplay::draw(player, obstacles);
	}
}

namespace basicFunctionsGameplay
{
	void update(SCREENS& currentScreen, object::Player& player, std::vector <object::Obstacle>& obstacles)
	{
		float deltaTime = GetFrameTime();

		if (player.isActive)
		{
			playerFunctions::move(player, deltaTime);
			playerFunctions::rotate(player, deltaTime);

			if (obstacles.size() > 0)
			{
				for (int i = 0; i < obstacles.size(); i++)
				{
					obstacleFunctions::move(obstacles.at(i), deltaTime);

					gameplayFunctions::despawnObstacle(obstacles, i);
				}
			}

			gameplayFunctions::spawnObstacle(obstacles, deltaTime);

			if (IsKeyPressed(KEY_ESCAPE))
				currentScreen = EXIT;
		}
		else
		{
			if (IsKeyPressed(KEY_ENTER))
				player.isActive = true;
		}
	}

	void draw(object::Player player, std::vector <object::Obstacle> obstacles)
	{
		int startingTextLenght = MeasureText("Presione ENTER para iniciar", 40);

		BeginDrawing();

		ClearBackground(BLACK);

		playerFunctions::draw(player);

		for (int i = 0; i < obstacles.size(); i++)
			obstacleFunctions::draw(obstacles.at(i));

		if (!player.isActive)
			DrawText("Presione ENTER para iniciar", (screen::width / 2) - (startingTextLenght / 2), screen::height / 2, 40, BLUE);

		EndDrawing();
	}
}

namespace gameplayFunctions
{
	float spawnTimer = 0.0f;

	void spawnObstacle(std::vector <object::Obstacle>& obstacles, float deltaTime)
	{
		const float baseSpawnTimer = 35.0f;

		if (spawnTimer <= 0.0f)
		{
			obstacles.push_back(obstacleFunctions::createAnObstacle());

			spawnTimer = baseSpawnTimer;
		}
		else
			spawnTimer -= deltaTime * 10.0f;
	}

	void despawnObstacle(std::vector <object::Obstacle>& obstacles, int index)
	{
		if (!obstacles.at(index).isActive)
			obstacles.erase(obstacles.begin() + index);
	}
}