
#include "game.h"

int main(int argc, char* args[])
{
    Game game;

    game.init();

    while (game.isRunning)
    {
       game.isRunning = game.play();
    }

	game.quitGame();

	return 0;
}
