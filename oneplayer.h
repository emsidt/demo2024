#ifndef _ONEPLAYER__H
#define _ONEPLAYER__H
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "game_func.h"
#include "constant.h"


int onePlayer(int a[][MAX], int &x, int &y, int &count, SDL_Event &event, bool quit, SDL_Texture* texture,
SDL_Renderer* renderer, Mix_Chunk *&audio);

Move findBestMove(int a[][MAX]);

#endif // _ONEPLAYER__H
