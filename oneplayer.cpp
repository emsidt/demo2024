#include "oneplayer.h"
#include "game_func.h"
#include "Function.h"
#include <ctime>

int onePlayer(int a[][MAX], int &x, int &y, int &count, SDL_Event &event, bool quit, SDL_Texture* texture,
SDL_Renderer* renderer)
{
	count = 0;
	initializeBoard(a);
	texture = loadTexture("play0.PNG", renderer);
	renderTexture(texture, renderer);

	humanPlay:
	while(!quit)
	{
			srand(time(nullptr));
			SDL_PollEvent(&event);

			switch(event.type)
			{
			case SDL_QUIT:
				quit = true;
			case SDL_MOUSEBUTTONDOWN:
				if(SDL_BUTTON_LEFT == event.button.button)
				{
					SDL_GetMouseState(&x, &y);
					if( 75 <= x && x <= 620 && 50 <= y && y <= 590 )
					{
						//std::cout << "Toa do chuot " << x << " : " << y << std::endl;
						standardCoordinate(x, y);
						//std::cout << "Toa do chuan hoa " << y << " : " << x << std::endl;

						if(validMove(x, y, a))
						{

							if(count % 2 == 0)
							{
								a[y][x] = 1;
								displayBoard(a);
								SDL_Texture* tx1 = loadTexture("xcell.png", renderer);
								renderTexture(tx1, renderer, x*34+4+63+x/6, y*34+4+50, 25, 25);
								SDL_RenderPresent(renderer);
								count++;
								if(checkXWinBlock(a))
								{
									std::cout << "x won" << std::endl;
									SDL_Texture* tx2 = loadTexture("xwon0.PNG", renderer);
									renderTexture(tx2, renderer);
									return 1;
								}
							}
						}
						else goto humanPlay;



					}
				}
			}
			botPLay:
				x = botPlayX();
				y = botPLayY();
				//std::cout << "Bot " << x << " : " << y << std::endl;
				standardCoordinate(x, y);
				std::cout << "Toa do bot : " << x << " " << y << std::endl;
				if (validMove(x, y, a))
				{
					if(count % 2 != 0)
					{
						a[y][x] = 2;
						displayBoard(a);
						SDL_Delay(200);
						SDL_Texture* tx1 = loadTexture("ocell.png", renderer);
						renderTexture(tx1, renderer, x*34+4+63+x/6, y*34+4+50, 25, 25);
						SDL_RenderPresent(renderer);

						count++;
						if(checkOWinBlock(a))
						{
							std::cout << "o won" << std::endl;
							SDL_Texture* tx2 = loadTexture("owon0.PNG", renderer);
							renderTexture(tx2, renderer);
							return 2;
						}
					}
				}
				else goto botPLay;
				goto humanPlay;
	}
	//std::cout << "flag" << std::endl;

}





