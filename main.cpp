#include "Function.h"


int main(int argc, char* args[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	SDL_Texture* texture;
	int x, y;

	int choose = 0;
	bool quit = false;

	initSDL(window, renderer); // khoi tao man hinh window
	texture = loadTexture("mainmenu.PNG", renderer);
	renderTexture(texture, renderer);

	menu:
	while(!quit)
	{
		SDL_PollEvent(&event);
		{
			SDL_GetMouseState(&x, &y);
			switch(event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(SDL_BUTTON_LEFT == event.button.button)
				{

					choose = click(x, y);
					switch(choose)
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
				//std::cout << "Toa do chuot " << x << " : " << y << std::endl;
				break;

			}
		}
	}

	oneplayer:

	twoplayer:


	quitSDL(window, renderer);
	return 0;
}
