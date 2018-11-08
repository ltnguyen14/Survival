#include "../engine/Engine.h"

#include <time.h>

#include "gameStates/gameStates.h"

int main(void)
{
	GameEngine game = { 640, 480, "Survival", false, 60 };
	TestState testState = {};
	
	game.Init();
	game.PushState(&testState);

	double lag = 0.0;
	double FPS = 60.0;
	double MS_PER_UPDATE = 1000.0 / FPS;
	clock_t previous = clock();

	while (game.Running()) {

		auto current = clock();
		auto elapsed = current - previous;

		previous = current;
		lag += elapsed;

		game.HandleEvents();

		while (lag >= MS_PER_UPDATE) {
			game.Update();
			lag -= MS_PER_UPDATE;
		}
			
		game.Draw();	
	}

	game.Cleanup();
	return 0;
}