#ifndef _ONEPLAYER__H
#define _ONEPLAYER__H

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "game_func.h"


int onePlayer(int a[][MAX], int &x, int &y, int &count, SDL_Event &event, bool quit, SDL_Texture* texture,
SDL_Renderer* renderer);



#endif // _ONEPLAYER__H
