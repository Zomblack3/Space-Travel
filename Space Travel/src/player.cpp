#include "player.h"

#include "consts.h"

namespace playerFunctions
{
	void setDefault(object::Player& player)
	{
		const float startingPosX = 50.0f;
		const float startingWidth = 50.0f;
		const float startingHeight = 50.0f;

		player.pos.x = startingPosX;
		player.pos.y = screen::height / 2.0f;
		
		player.hitbox.x = player.pos.x;
		player.hitbox.y = player.pos.y;
		player.hitbox.width = startingWidth;
		player.hitbox.height = startingHeight;

		player.origin.x = player.hitbox.width / 2.0f;
		player.origin.y = player.hitbox.height / 2.0f;

		player.rotation = 90.0f;

		player.color = WHITE;

		player.isActive = false;
	}

	void move(object::Player& player, float deltaTime)
	{
		float fallSpeed = 100.0f;

		if (IsKeyPressed(KEY_SPACE))
		{
			player.hitbox.y -= 50.0f;
			player.rotation = 30.0f;
		}

		if (player.hitbox.y < screen::height - player.hitbox.height)
			player.hitbox.y += fallSpeed * deltaTime;
	}

	void rotate(object::Player& player, float deltaTime)
	{
		float rotationSpeed = 100.0f;

		if (player.rotation < 180)
			player.rotation += rotationSpeed * deltaTime;
	}

	void draw(object::Player& player)
	{
		DrawRectanglePro(player.hitbox, player.origin, player.rotation, player.color);
	}
}
