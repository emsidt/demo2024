#include "oneplayer.h"
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
						SDL_Texture* tx1 = loadTexture("ocell.png", renderer);
						renderTexture(tx1, renderer, x*34+4+63+x/6, y*34+4+50, 25, 25);
						SDL_RenderPresent(renderer);
						SDL_Delay(200);
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



int botPlayX()
{

	int n = rand() % (620 - 75) + 75 + 1;

	return n;
}
int botPLayY()
{

	int n = rand() % (590 - 50) + 50 + 1;
	return n;
}


int attackPoint(int a[][MAX])
{
	int val;
	val = verticalAttackPoint(a) + horizonAttackPoint(a) + mainDiagonalAttackPoint(a) + semiDiagonalAttackPoint(a);
	return val;
}
int verticalAttackPoint(int a[][MAX])
{
	long totalVal = 0;
	int allies = 0;
	int enemies = 0;

}
int horizonAttackPoint(int a[][MAX])
{

}
int mainDiagonalAttackPoint(int a[][MAX])
{

}
int semiDiagonalAttackPoint(int a[][MAX])
{

}




















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
    if(a[y][x] == 0 && x <= 15 && y <= 15) return true;
    else return false;
}

bool checkXWinBlock(int a[][MAX]){
    // check hang ngang
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1){
                if(a[i][j+1] == 1 && a[i][j+2] == 1 && a[i][j+3] == 1 && a[i][j+4] == 1 && (a[i][j+5] == 0 || a[i][j-1] == 0)) return true;
                if(a[i][j+1] == 1 && a[i][j+2] == 1 && a[i][j+3] == 1 && a[i][j-1] == 1 && (a[i][j+4] == 0 || a[i][j-2] == 0)) return true;
                if(a[i][j+1] == 1 && a[i][j+2] == 1 && a[i][j-1] == 1 && a[i][j-2] == 1 && (a[i][j+3] == 0 || a[i][j-3] == 0)) return true;
                if(a[i][j+1] == 1 && a[i][j-1] == 1 && a[i][j-2] == 1 && a[i][j-3] == 1 && (a[i][j+2] == 0 || a[i][j-4] == 0)) return true;
                if(a[i][j-1] == 1 && a[i][j-2] == 1 && a[i][j-3] == 1 && a[i][j-4] == 1 && (a[i][j+1] == 0 || a[i][j-5] == 0)) return true;
            }
        }
    }
    //check hang doc
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1){
                if(a[i+1][j] == 1 && a[i+2][j] == 1 && a[i+3][j] == 1 && a[i+4][j] == 1 && (a[i-1][j] == 0 || a[i+5][j] == 0)) return true;
                if(a[i-1][j] == 1 && a[i+1][j] == 1 && a[i+2][j] == 1 && a[i+3][j] == 1 && (a[i-2][j] == 0 || a[i+4][j] == 0)) return true;
                if(a[i-2][j] == 1 && a[i-1][j] == 1 && a[i+1][j] == 1 && a[i+2][j] == 1 && (a[i-3][j] == 0 || a[i+3][j] == 0)) return true;
                if(a[i-3][j] == 1 && a[i-2][j] == 1 && a[i-1][j] == 1 && a[i+1][j] == 1 && (a[i-4][j] == 0 || a[i+2][j] == 0)) return true;
                if(a[i-4][j] == 1 && a[i-3][j] == 1 && a[i-2][j] == 1 && a[i-1][j] == 1 && (a[i-5][j] == 0 || a[i+1][j] == 0)) return true;
            }
        }
    }
    // check hang cheo 1
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1){
                if(a[i+1][j+1] == 1 && a[i+2][j+2] == 1 && a[i+3][j+3] == 1 && a[i+4][j+4] == 1 && (a[i-1][j-1] == 0 || a[i+5][j+5] == 0)) return true;
                if(a[i-1][j-1] == 1 && a[i+1][j+1] == 1 && a[i+2][j+2] == 1 && a[i+3][j+3] == 1 && (a[i-2][j-2] == 0 || a[i+4][j+4] == 0)) return true;
                if(a[i-2][j-2] == 1 && a[i-1][j-1] == 1 && a[i+1][j+1] == 1 && a[i+2][j+2] == 1 && (a[i-3][j-3] == 0 || a[i+3][j+3] == 0)) return true;
                if(a[i-3][j-3] == 1 && a[i-2][j-2] == 1 && a[i-1][j-1] == 1 && a[i+1][j+1] == 1 && (a[i-4][j-4] == 0 || a[i+2][j+2] == 0)) return true;
                if(a[i-4][j-4] == 1 && a[i-3][j-3] == 1 && a[i-2][j-2] == 1 && a[i-1][j-1] == 1 && (a[i-5][j-5] == 0 || a[i+1][j+1] == 0)) return true;
            }
        }
    }

    // check hang cheo 2
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1){
                if(a[i+1][j-1] == 1 && a[i+2][j-2] == 1 && a[i+3][j-3] == 1 && a[i+4][j-4] == 1 && (a[i-1][j+1] == 0 || a[i+5][j-5] == 0)) return true;
                if(a[i+1][j-1] == 1 && a[i+2][j-2] == 1 && a[i+3][j-3] == 1 && a[i-1][j+1] == 1 && (a[i-2][j+2] == 0 || a[i+4][j-4] == 0)) return true;
                if(a[i+2][j-2] == 1 && a[i+2][j-2] == 1 && a[i-1][j+1] == 1 && a[i-2][j+2] == 1 && (a[i-3][j+3] == 0 || a[i+3][j-3] == 0)) return true;
                if(a[i+1][j-1] == 1 && a[i-1][j+1] == 1 && a[i-2][j+2] == 1 && a[i-3][j+3] == 1 && (a[i-4][j+4] == 0 || a[i+2][j-2] == 0)) return true;
                if(a[i-1][j+1] == 1 && a[i-2][j+2] == 1 && a[i-3][j+3] == 1 && a[i-4][j+4] == 1 && (a[i-5][j+5] == 0 || a[i+1][j-1] == 0)) return true;
            }
        }
    }
    return false;

}

bool checkOWinBlock(int a[][MAX]){
    // check hang ngang
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2){
                if(a[i][j+1] == 2 && a[i][j+2] == 2 && a[i][j+3] == 2 && a[i][j+4] == 2 && (a[i][j+5] == 0 || a[i][j-1] == 0)) return true;
                if(a[i][j+1] == 2 && a[i][j+2] == 2 && a[i][j+3] == 2 && a[i][j-1] == 2 && (a[i][j+4] == 0 || a[i][j-2] == 0)) return true;
                if(a[i][j+1] == 2 && a[i][j+2] == 2 && a[i][j-1] == 2 && a[i][j-2] == 2 && (a[i][j+3] == 0 || a[i][j-3] == 0)) return true;
                if(a[i][j+1] == 2 && a[i][j-1] == 2 && a[i][j-2] == 2 && a[i][j-3] == 2 && (a[i][j+2] == 0 || a[i][j-4] == 0)) return true;
                if(a[i][j-1] == 2 && a[i][j-2] == 2 && a[i][j-3] == 2 && a[i][j-4] == 2 && (a[i][j+1] == 0 || a[i][j-5] == 0)) return true;
            }
        }
    }
    //check hang doc
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2){
                if(a[i+1][j] == 2 && a[i+2][j] == 2 && a[i+3][j] == 2 && a[i+4][j] == 2 && (a[i-1][j] == 0 || a[i+5][j] == 0)) return true;
                if(a[i-1][j] == 2 && a[i+1][j] == 2 && a[i+2][j] == 2 && a[i+3][j] == 2 && (a[i-2][j] == 0 || a[i+4][j] == 0)) return true;
                if(a[i-2][j] == 2 && a[i-1][j] == 2 && a[i+1][j] == 2 && a[i+2][j] == 2 && (a[i-3][j] == 0 || a[i+3][j] == 0)) return true;
                if(a[i-3][j] == 2 && a[i-2][j] == 2 && a[i-1][j] == 2 && a[i+1][j] == 2 && (a[i-4][j] == 0 || a[i+2][j] == 0)) return true;
                if(a[i-4][j] == 2 && a[i-3][j] == 2 && a[i-2][j] == 2 && a[i-1][j] == 2 && (a[i-5][j] == 0 || a[i+1][j] == 0)) return true;
            }
        }
    }
    // check hang cheo 1
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2){
                if(a[i+1][j+1] == 2 && a[i+2][j+2] == 2 && a[i+3][j+3] == 2 && a[i+4][j+4] == 2 && (a[i-1][j-1] == 0 || a[i+5][j+5] == 0)) return true;
                if(a[i-1][j-1] == 2 && a[i+1][j+1] == 2 && a[i+2][j+2] == 2 && a[i+3][j+3] == 2 && (a[i-2][j-2] == 0 || a[i+4][j+4] == 0)) return true;
                if(a[i-2][j-2] == 2 && a[i-1][j-1] == 2 && a[i+1][j+1] == 2 && a[i+2][j+2] == 2 && (a[i-3][j-3] == 0 || a[i+3][j+3] == 0)) return true;
                if(a[i-3][j-3] == 2 && a[i-2][j-2] == 2 && a[i-1][j-1] == 2 && a[i+1][j+1] == 2 && (a[i-4][j-4] == 0 || a[i+2][j+2] == 0)) return true;
                if(a[i-4][j-4] == 2 && a[i-3][j-3] == 2 && a[i-2][j-2] == 2 && a[i-1][j-1] == 2 && (a[i-5][j-5] == 0 || a[i+1][j+1] == 0)) return true;
            }
        }
    }

    // check hang cheo 2
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2){
                if(a[i+1][j-1] == 2 && a[i+2][j-2] == 2 && a[i+3][j-3] == 2 && a[i+4][j-4] == 2 && (a[i-1][j+1] == 0 || a[i+5][j-5] == 0)) return true;
                if(a[i+1][j-1] == 2 && a[i+2][j-2] == 2 && a[i+3][j-3] == 2 && a[i-1][j+1] == 2 && (a[i-2][j+2] == 0 || a[i+4][j-4] == 0)) return true;
                if(a[i+2][j-2] == 2 && a[i+2][j-2] == 2 && a[i-1][j+1] == 2 && a[i-2][j+2] == 2 && (a[i-3][j+3] == 0 || a[i+3][j-3] == 0)) return true;
                if(a[i+1][j-1] == 2 && a[i-1][j+1] == 2 && a[i-2][j+2] == 2 && a[i-3][j+3] == 2 && (a[i-4][j+4] == 0 || a[i+2][j-2] == 0)) return true;
                if(a[i-1][j+1] == 2 && a[i-2][j+2] == 2 && a[i-3][j+3] == 2 && a[i-4][j+4] == 2 && (a[i-5][j+5] == 0 || a[i+1][j-1] == 0)) return true;
            }
        }
    }
    return false;
}


