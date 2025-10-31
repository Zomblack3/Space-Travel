#include "player.h"

#include "consts.h"

namespace playerFunctions
{
	void setDefault(object::Player& player)
	{
		const float startingPosX = 50.0f;
		const float startingWidth = 35.0f;
		const float startingHeight = 35.0f;
		
		player.hitbox.x = startingPosX;
		player.hitbox.y = screen::height / 2.0f;
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
			if (player.hitbox.y - player.hitbox.height > 0.0f)
				player.hitbox.y -= 50.0f;
			
			player.rotation = 30.0f;
		}

		if (player.hitbox.y - player.hitbox.height < screen::height)
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
