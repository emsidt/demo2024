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
	Board board;
	Media media;
	board.initializeBoard(a);
	texture = media.loadTexture("image/play0.PNG", renderer);
	media.renderTexture(texture, renderer);

	//media.music == nullptr;
	//Mix_PlayMusic(media.music, -1);

	botPLay:
				Move bot;
				if(count == 0)
				{
					bot.x = 7;
					bot.y = 7;
				}
				else
				{
					bot = findBestMove(a, board);
				}

				//std::cout << bot.x << " " << bot.y << std::endl;
				x = bot.x;
				y = bot.y;
				if (board.validMove(x, y, a))
				{
					if(count % 2 == 0)
					{
						a[y][x] = 1;
						board.displayBoard(a);
                        SDL_Delay(500);
						std::cout << std::endl;
						SDL_Texture* tx1 = media.loadTexture("image/xcell.png", renderer);
						media.renderTexture(tx1, renderer, x*34+4+63+x/6, y*34+4+50, 25, 25);
						media.playMusic("sound_effects/oplay.wav", audio);
						SDL_RenderPresent(renderer);
						//audio = nullptr;


						count++;
						if(board.checkXWinBlock(a))
						{
							SDL_Delay(3000);
							//std::cout << "o won" << std::endl;
							SDL_Texture* tx2 = media.loadTexture("image/xwon0.PNG", renderer);
							media.renderTexture(tx2, renderer);

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
						media.standardCoordinate(x, y);
						//std::cout << "Toa do chuan hoa " << y << " : " << x << std::endl;

						if(board.validMove(x, y, a))
						{

							if(count % 2 != 0)
							{
								a[y][x] = 2;
								board.displayBoard(a);
								std::cout << std::endl;
								SDL_Texture* tx1 = media.loadTexture("image/ocell.png", renderer);

								media.renderTexture(tx1, renderer, x*34+4+63+x/6, y*34+4+50, 25, 25);
								SDL_RenderPresent(renderer);
								media.playMusic("sound_effects/xplay.wav", audio);
								count++;
								if(board.checkOWinBlock(a))
								{
									SDL_Delay(2000);
									//std::cout << "x won" << std::endl;
									SDL_Texture* tx2 = media.loadTexture("image/owon0.PNG", renderer);
                                    media.playMusic("sound_effects/owin.wav", audio);
									media.renderTexture(tx2, renderer);
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

Move findBestMove(int a[][MAX], Board &board)
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
				= board.verticalAttackPoint(i, j, a)
				+ board.horizonAttackPoint(i, j, a)
				+ board.semiDiagonalAttackPoint(i, j, a)
				+ board.mainDiagonalAttackPoint(i, j, a);

				long defenseVal
				= board.verticalDefensePoint(i, j, a)
				+ board.horizonDefensePoint(i, j, a)
				+ board.semiDiagonalDefensePoint(i, j, a)
				+ board.mainDiagonalDefensePoint(i, j, a);

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
					//std::cout << tempVal << std::endl;
					moveMaxVal = tempVal;
					bestMove.y = i;
					bestMove.x = j;

				}
			}
		}
	}
	//std::cout << "movemaxval: "<< moveMaxVal << std::endl;
	return bestMove;
	//std::cout << bestMove.x << " " << bestMove.y << std::endl;
}



