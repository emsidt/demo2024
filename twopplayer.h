#ifndef TWOPLAYER_H
#define TWOPLAYER_H

#include "oneplayer.h"
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

int twoPlayer(int a[][MAX], int &x, int &y, int &count, SDL_Event &event, bool quit, SDL_Texture* texture,
SDL_Renderer* renderer); // che do choi 2 nguoi

#endif // TWOPLAYER
