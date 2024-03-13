#include "twopplayer.h"
#include "Function.h"

int a[MAX][MAX];
SDL_Event event;
//SDL_Texture* texture;
//SDL_Renderer* renderer;

void initializeBoard(int a[][MAX]){
    for( int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j){
            a[i][j] = 0;
        }
    }
}

void displayBoard(int a[][MAX]){
    //system("cls");
    for( int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j){
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void inputPlayer(int a[][MAX], int &x, int &y, int count){
    if(count%2 == 0){
        a[x][y] == 1;
    }
    else a[x][y] = 2;
}

bool validMove(int x, int y, int a[][MAX]){
    if(a[y][x] == 0 ) return true;
    else return false;
}

int twoPlayer(int a[][MAX], int &x, int &y, int &count, SDL_Event &event, bool quit, SDL_Texture* texture,
SDL_Renderer* renderer)
{
	initializeBoard(a);
	texture = loadTexture("play0.PNG", renderer);
	renderTexture(texture, renderer);


	while(!quit)
	{
		//displayBoard(a);
		SDL_PollEvent(&event);
		//SDL_GetModState(x, y);
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
					std::cout << "Toa do chuot " << x << " : " << y << std::endl;
					standardCoordinate(x, y);
					std::cout << "Toa do chuan hoa " << y << " : " << x << std::endl;
					//inputPlayer(a, x, y, count);
					if(validMove(x, y, a))
					{
						if(count < 256)
						{
							if(count % 2 == 0)
							{
								a[y][x] = 1;
								displayBoard(a);
								SDL_Texture* tx1 = loadTexture("xcell.png", renderer);
								renderTexture(tx1, renderer, x*34+4+63+x/6, y*34+4+50, 25, 25);
								SDL_RenderPresent(renderer);
								count++;
							}
							else
							{
								a[y][x] = 2;
								displayBoard(a);
								SDL_Texture* tx1 = loadTexture("ocell.png", renderer);
								renderTexture(tx1, renderer, x*34+4+63+x/6, y*34+4+50, 25, 25);
								SDL_RenderPresent(renderer);
								count++;
							}
						}

					}
				}
			}
		}
	}
}
