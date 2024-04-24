#include "game.h"



bool Game::play()
{
    menu:

    Game game;

	while(game.isRunning)
	{
		SDL_PollEvent(&game.event);
		SDL_GetMouseState(&game.x, &game.y);

		switch(game.event.type)
		{
		case SDL_QUIT:
			game.isRunning = false;
			return false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if(SDL_BUTTON_LEFT == game.event.button.button)
			{
				game.mode = game.media.clickInMenu(game.x, game.y);
				std::cout << game.mode << std::endl;
				game.media.playMusic("sound_effects/mouseclick.wav", game.media.audio);

				switch(game.mode)
				{
				case 1:
					goto oneplayer;
					break;
				case 2:
					goto twoplayer;
					break;
				case 3:
                    game.isRunning = false;
                    return false;
					break;
                case 4:
                    Mix_PauseMusic();
                    break;
                default:
                    Mix_ResumeMusic();
                    break;
                }
			}
			break;
		case SDL_MOUSEMOTION:
			media.renderMenu(media.texture, media.renderer, game.x, game.y);
			break;
		}
	}


	oneplayer:
		game.checkwin = onePlayer(board.a, game.x, game.y, board.count, game.event, game.isRunning, media.texture, media.renderer, media.audio);
		std::cout << "check win = " << checkwin << std::endl;
		if (game.checkwin == 3) goto menu;
		goto result;

	twoplayer:

		game.checkwin = twoPlayer(board.a, game.x, game.y, board.count, game.event, game.isRunning, media.texture, media.renderer, media.audio);
        std::cout << "check win = " << checkwin << std::endl;
		if (game.checkwin == 3) goto menu;
		goto result;

	result:

		while(game.isRunning)
		{
			SDL_PollEvent(&game.event);
			SDL_GetMouseState(&game.x, &game.y);

			switch(game.event.type)
			{
			case SDL_QUIT:
				game.isRunning = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(SDL_BUTTON_LEFT == game.event.button.button)
				{
					game.choose = media.clickInResult(game.x, game.y);
                    media.playMusic("sound_effects/mouseclick.wav", media.audio);

					switch(game.mode)
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
    return true;
}

void Game::init()
{
    media.initSDL();
}
void Game::quitGame()
{
    media.quitSDL();
}
