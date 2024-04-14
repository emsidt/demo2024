#ifndef _TWOPLAYER__H
#define _TWOPLAYER__H

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "game_func.h"
#include "constant.h"

int twoPlayer(int a[][MAX], int &x, int &y, int &count, SDL_Event &event, bool quit, SDL_Texture* texture,
SDL_Renderer* renderer); // che do choi 2 nguoi

#endif // _TWOPLAYER__H
