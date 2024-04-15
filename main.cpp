#include "media.h"
#include "twopplayer.h"
#include "oneplayer.h"
#include "constant.h"
int main(int argc, char* args[])
{

    SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event event;
	SDL_Texture* texture = nullptr;
	Mix_Music *music = nullptr;
	Mix_Chunk *audio = nullptr;
	int x, y;
	int a[MAX][MAX];
	int count = 0;

	int gameMode = 0; // bien lua chon che do
	int choose = 0;
	int checkwin = 0; // kiem tra thang, thua, hoa
	bool quit = false;

	initSDL(window, renderer, music, audio); // khoi tao man hinh window
	texture = loadTexture("mainmenu.PNG", renderer);
	renderTexture(texture, renderer);

	menu:

	while(!quit)
	{
		SDL_PollEvent(&event);
		SDL_GetMouseState(&x, &y);

		switch(event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if(SDL_BUTTON_LEFT == event.button.button)
			{
				gameMode = clickInMenu(x, y);
				switch(gameMode)
				{
				case 1:
					goto oneplayer;
					break;
				case 2:
					goto twoplayer;
					break;
				case 3:
					return 0;
					break;
				}
			}
		case SDL_MOUSEMOTION:
			renderMenu(texture, renderer, x, y);
			break;
		}
	}

	oneplayer:
		checkwin = onePlayer(a, x, y,count, event, quit, texture, renderer, audio);
		//std::cout << "check win = " << checkwin << std::endl;
		if (checkwin == 3) goto menu;
		goto result;

	twoplayer:

		checkwin = twoPlayer(a, x, y,count, event, quit, texture, renderer);
		if (checkwin == 3) goto menu;

		//std::cout << "check win = " << checkwin << std::endl;
		goto result;

	result:

		while(!quit)
		{
			SDL_PollEvent(&event);
			SDL_GetMouseState(&x, &y);

			switch(event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(SDL_BUTTON_LEFT == event.button.button)
				{
					choose = clickInResult(x, y);
					switch(gameMode)
					{
					case 1:
						if(choose == 1)
						{
							goto oneplayer;
						}
						else goto menu;
						break;
					case 2:
						if(choose == 1)
						{
							goto twoplayer;
						}
						else goto menu;
						break;
					}
				}
			case SDL_MOUSEMOTION:
				renderResult(texture, renderer, x, y);
				break;
			}
		}

	quitSDL(window, renderer, music, audio);
	return 0;
}
