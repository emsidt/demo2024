#include "Function.h"

int main(int argc, char* args[])
{
	SDL_Renderer* renderer;
	SDL_Event event;
	bool isRunning = false;
	int choose;


	if (init() == false) return 1;

	while(!isRunning)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (SDL_BUTTON_LEFT == event.button.button)
				{
					choose = clickInMenu(event, isRunning);
					switch(choose)
					{
					case 1:
						goto play;
						break;
					case 2:
						goto play;
						break;
					case 3:
						return 0;
						break;
					}
				}
			}
		}
	}

	play:

		if(choose == 2)
		{
			twoPLayer();

		}
		else
		{
			onePlayer();
		}

	SDL_Delay(5000);

	quit();
	return 0;
}
