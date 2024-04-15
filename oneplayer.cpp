#include "oneplayer.h"
#include "game_func.h"
#include "media.h"
#include <ctime>
#include <cmath>
#include <algorithm>

int onePlayer(int a[][MAX], int &x, int &y, int &count,
			SDL_Event &event, bool quit,
			SDL_Texture* texture,
			SDL_Renderer* renderer, Mix_Chunk *&audio)
{
	count = 0;
	initializeBoard(a);
	texture = loadTexture("play0.PNG", renderer);
	renderTexture(texture, renderer);

	botPLay:
				Move bot;
				if(count == 0)
				{
					bot.x = 7;
					bot.y = 7;
				}
				else
				{
					bot = findBestMove(a);
				}

				//std::cout << bot.x << " " << bot.y << std::endl;
				x = bot.x;
				y = bot.y;
				if (validMove(x, y, a))
				{
					if(count % 2 == 0)
					{
						a[y][x] = 1;
						displayBoard(a);
                        SDL_Delay(500);
						std::cout << std::endl;
						SDL_Texture* tx1 = loadTexture("xcell.png", renderer);
						renderTexture(tx1, renderer, x*34+4+63+x/6, y*34+4+50, 25, 25);
						playMusic("sound_effects/oplay.wav", audio);
						SDL_RenderPresent(renderer);
						//audio = nullptr;


						count++;
						if(checkXWinBlock(a))
						{
							SDL_Delay(3000);
							//std::cout << "o won" << std::endl;
							SDL_Texture* tx2 = loadTexture("xwon0.PNG", renderer);
							renderTexture(tx2, renderer);

							return 2;
						}
					}
				}
				else goto botPLay;
				goto humanPlay;
	humanPlay:
	while(!quit)
	{
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

							if(count % 2 != 0)
							{
								a[y][x] = 2;
								displayBoard(a);
								std::cout << std::endl;
								SDL_Texture* tx1 = loadTexture("ocell.png", renderer);

								renderTexture(tx1, renderer, x*34+4+63+x/6, y*34+4+50, 25, 25);
								SDL_RenderPresent(renderer);
								playMusic("sound_effects/xplay.wav", audio);
								count++;
								if(checkOWinBlock(a))
								{
									SDL_Delay(2000);
									//std::cout << "x won" << std::endl;
									SDL_Texture* tx2 = loadTexture("owon0.PNG", renderer);
                                    playMusic("sound_effects/owin.wav", audio);
									renderTexture(tx2, renderer);
									return 1;
								}
							}
						}
						else goto humanPlay;
					}
					if( 1085 <= x && x <= 1165 && 25 <= y && y <= 70 )
					{
						return 3;
					}
				}
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&x, &y);
				if( 1085 <= x && x <= 1165 && 25 <= y && y <= 70 )
					{
						std::cout << "back" << std::endl;
					}
				break;
			}
		goto botPLay;
		break;
	}

}

Move findBestMove(int a[][MAX])
{
	Move bestMove;
	bestMove.x = 0;
	bestMove.y = 0;
	long moveMaxVal = 0;

	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			if (a[i][j] == 0)
			{
				long attackVal
				= verticalAttackPoint(i, j, a)
				+ horizonAttackPoint(i, j, a)
				+ semiDiagonalAttackPoint(i, j, a)
				+ mainDiagonalAttackPoint(i, j, a);

				long defenseVal
				= verticalDefensePoint(i, j, a)
				+ horizonDefensePoint(i, j, a)
				+ semiDiagonalDefensePoint(i, j, a)
				+ mainDiagonalDefensePoint(i, j, a);

				long tempVal;
				if (attackVal > defenseVal)
				{
					 tempVal = attackVal;
				}
				else
				{
					tempVal = defenseVal;
				}

				if (moveMaxVal < tempVal)
				{
					std::cout << tempVal << std::endl;
					moveMaxVal = tempVal;
					bestMove.y = i;
					bestMove.x = j;

				}
			}
		}
	}
	//std::cout << "movemaxval: "<< moveMaxVal << std::endl;
	return bestMove;
	std::cout << bestMove.x << " " << bestMove.y << std::endl;
}



