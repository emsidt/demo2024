#include "media.h"
#include "twopplayer.h"
#include "oneplayer.h"
#include "constant.h"
#include "game.h"

int main(int argc, char* args[])
{
    Game game;

    game.init();

    game.play();

	game.quitGame();

	return 0;
}
