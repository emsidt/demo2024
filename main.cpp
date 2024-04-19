#include "media.h"
#include "twopplayer.h"
#include "oneplayer.h"
#include "constant.h"
int main(int argc, char* args[])
{

    Media media;
	int x, y;
	int a[MAX][MAX];
	int count = 0;
    SDL_Event event;
	int gameMode = 0; // bien lua chon che do
	int choose = 0;
	int checkwin = 0; // kiem tra thang, thua, hoa
	bool quit = false;

	media.initSDL(); // khoi tao man hinh window
	media.texture = media.loadTexture("image/mainmenu.PNG", media.renderer);
	media.renderTexture(media.texture, media.renderer);

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
				gameMode = media.clickInMenu(x, y);
				media.playMusic("sound_effects/mouseclick.wav", media.audio);
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
			media.renderMenu(media.texture, media.renderer, x, y);
			break;
		}
	}

	oneplayer:
		checkwin = onePlayer(a, x, y,count, event, quit, media.texture, media.renderer, media.audio);
		//std::cout << "check win = " << checkwin << std::endl;
		if (checkwin == 3) goto menu;
		goto result;

	twoplayer:

		checkwin = twoPlayer(a, x, y,count, event, quit, media.texture, media.renderer, media.audio);
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
					choose = media.clickInResult(x, y);
                    media.playMusic("sound_effects/mouseclick.wav", media.audio);

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
				media.renderResult(media.texture, media.renderer, x, y);
				break;
			}
		}

	media.quitSDL();
	return 0;
}
