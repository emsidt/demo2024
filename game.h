#ifndef __GAME_H
#define __GAME_H

#include "constant.h"
#include "media.h"
#include "oneplayer.h"
#include "twoplayer.h"

struct Game
{

    SDL_Event event;
	int mode = 0; // bien lua chon che do
	int choose = 0;
	int checkwin = 0; // kiem tra thang, thua, hoa
	bool isRunning = true;
    int x, y;

    Media media;
    Board board;


    bool play();
    void init();
    void quitGame();




};


#endif // __GAME_H
