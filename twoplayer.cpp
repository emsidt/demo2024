#include "twopplayer.h"
#include "media.h"


int twoPlayer(int a[][MAX], int &x, int &y, int &count, SDL_Event &event, bool isRunning, SDL_Texture* texture,
SDL_Renderer* renderer, Mix_Chunk *&audio)
{
    Media media;
    Board board;
	count = 0;
	board.initializeBoard(a);
	texture = media.loadTexture("image/play0.PNG", renderer);
	media.renderTexture(texture, renderer);


	while(isRunning)
	{
		//displayBoard(a);
		SDL_PollEvent(&event);
		//SDL_GetModState(x, y);
		switch(event.type)
		{
		case SDL_QUIT:
			isRunning = true;
		case SDL_MOUSEBUTTONDOWN:
			if(SDL_BUTTON_LEFT == event.button.button)
			{
				SDL_GetMouseState(&x, &y);
				if( 75 <= x && x <= 620 && 50 <= y && y <= 590 )
				{
					//std::cout << "Toa do chuot " << x << " : " << y << std::endl;
					media.standardCoordinate(x, y);
					//std::cout << "Toa do chuan hoa " << y << " : " << x << std::endl;
					//inputPlayer(a, x, y, count);
					if(board.validMove(x, y, a))
					{
						if(count < 256)
						{
							if(count % 2 == 0)
							{
							    SDL_Texture *tx0 = media.loadTexture("image/default.png", renderer);
							    media.renderTexture(tx0, renderer, 620, 0, 580, 640);
							    SDL_Texture *tx = media.loadTexture("image/turno.png", renderer);
							    media.renderTexture(tx, renderer, 617, 0, 240, 640);
								a[y][x] = 1;
								board.displayBoard(a);
								SDL_Texture* tx1 = media.loadTexture("image/xcell.png", renderer);
								media.renderTexture(tx1, renderer, x*34+4+63+x/6, y*34+4+50, 25, 25);
								SDL_RenderPresent(renderer);
								media.playMusic("sound_effects/xplay.wav", audio);
								count++;
								if(board.checkXWinBlock(a))
								{
									//SDL_Delay(2000);
									std::cout << "x won" << std::endl;
									SDL_Texture* tx2 = media.loadTexture("image/xwon.PNG", renderer);
									media.renderTexture(tx2, renderer);
									return 1;
								}
							}

							else
							{
							    SDL_Texture *tx0 = media.loadTexture("image/default.png", renderer);
							    media.renderTexture(tx0, renderer, 620, 0, 580, 640);
							    SDL_Texture *tx = media.loadTexture("image/turnx.png", renderer);
							    media.renderTexture(tx, renderer, 620, 0, 240, 640);
								a[y][x] = 2;
								board.displayBoard(a);
								SDL_Texture* tx1 = media.loadTexture("image/ocell.png", renderer);
								media.renderTexture(tx1, renderer, x*34+4+63+x/6, y*34+4+50, 25, 25);
								SDL_RenderPresent(renderer);
								media.playMusic("sound_effects/oplay.wav", audio);
								count++;
								if(board.checkOWinBlock(a))
								{
									//SDL_Delay(2000);
									std::cout << "o won" << std::endl;
									SDL_Texture* tx2 = media.loadTexture("image/owon.PNG", renderer);
									media.renderTexture(tx2, renderer);
									media.playMusic("sound_effects/owin.wav", audio);
									return 2;
								}

							}
						}
						else
						{
							std::cout << "draw!" << std::endl;
							SDL_Texture* tx2 = media.loadTexture("image/draw.PNG", renderer);
							media.renderTexture(tx2, renderer);
							return 3;
						}
					}
				}
				if( 1085 <= x && x <= 1165 && 25 <= y && y <= 70 )
                {
						return 4;
                }
			}
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&x, &y);

            media.renderPlay(texture, renderer, x, y);
			break;
		}
	}
	return -1;
}


