#ifndef _ONEPLAYER__H
#define _ONEPLAYER__H
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "game_func.h"


int onePlayer(int a[][MAX], int &x, int &y, int &count, SDL_Event &event, bool quit, SDL_Texture* texture,
SDL_Renderer* renderer);

const long defensePoint[7] = { 0, 1, 9, 81, 729, 6561, 59049 };
const long attackPoint[7] = { 0, 3, 24, 192, 1536, 12288, 98304 };
Move findBestMove(int a[][MAX]);

#endif // _ONEPLAYER__H
