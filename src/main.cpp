// entry point
#include <iostream>


#include "Game.h"

int main()
{
	Game game;

	std::cout << "[main.cpp]: Game Process Started!" << std::endl;

	if (game.Initialize())
	{
		game.RunLoop();
	}

	game.Shutdown();



	return 0;
}