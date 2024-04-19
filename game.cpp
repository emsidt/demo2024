#include "game.h"



void Game::play()
{
    menu:
    Game game;
	while(!game.quit)
	{
		SDL_PollEvent(&game.event);
		SDL_GetMouseState(&game.x, &game.y);

		switch(game.event.type)
		{
		case SDL_QUIT:
			game.quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if(SDL_BUTTON_LEFT == game.event.button.button)
			{
				game.gameMode = game.media.clickInMenu(game.x, game.y);
				game.media.playMusic("sound_effects/mouseclick.wav", game.media.audio);
				switch(game.gameMode)
				{
				case 1:
					goto oneplayer;
					break;
				case 2:
					goto twoplayer;
					break;
				case 3:
					game.quit = true;
					break;
				}
			}
		case SDL_MOUSEMOTION:
			game.media.renderMenu(game.media.texture, game.media.renderer, game.x, game.y);
			break;
		}
	}

	oneplayer:
		game.checkwin = onePlayer(board.a, game.x, game.y, board.count, game.event, game.quit, media.texture, media.renderer, media.audio);
		//std::cout << "check win = " << checkwin << std::endl;
		if (game.checkwin == 3) goto menu;
		goto result;

	twoplayer:

		game.checkwin = twoPlayer(board.a, game.x, game.y, board.count, game.event, game.quit, media.texture, media.renderer, media.audio);
		if (game.checkwin == 3) goto menu;
		goto result;

	result:

		while(!game.quit)
		{
			SDL_PollEvent(&game.event);
			SDL_GetMouseState(&game.x, &game.y);

			switch(game.event.type)
			{
			case SDL_QUIT:
				game.quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(SDL_BUTTON_LEFT == game.event.button.button)
				{
					game.choose = media.clickInResult(game.x, game.y);
                    media.playMusic("sound_effects/mouseclick.wav", media.audio);

					switch(game.gameMode)
					{
					case 1:
						if(game.choose == 1)
						{
							goto oneplayer;
						}
						else goto menu;
						break;
					case 2:
						if(game.choose == 1)
						{
							goto twoplayer;
						}
						else goto menu;
						break;
					}
				}
			case SDL_MOUSEMOTION:
				media.renderResult(media.texture, media.renderer, game.x, game.y);
				break;
			}
		}
}
void Game::init()
{
    media.initSDL();
}
void Game::quitGame()
{
    media.quitSDL();
}
