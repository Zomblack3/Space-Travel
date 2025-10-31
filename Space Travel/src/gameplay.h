#pragma once

#include "screens.h"

#include "player.h"

namespace run
{
	void gameplay(SCREENS& currentScreen, object::Player& player);
}

namespace basicFunctions
{
	void update(SCREENS& currentScreen, object::Player& player);
	void draw(object::Player player);
}