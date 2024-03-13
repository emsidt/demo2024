#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "twopplayer.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 640;



void initSDL(SDL_Window* &window, SDL_Renderer* &renderer); // khoi tao cua so va but ve

void quitSDL(SDL_Window* window, SDL_Renderer* renderer); // giai phong

void waitUntilKeyPressed(); // cho su kien ban phim

SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);

void renderTexture(SDL_Texture* texture,SDL_Renderer* renderer); // tai anh toan man hinh

void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h); // tai anh theo toa do

void standardCoordinate(int &x, int &y);

int clickInMenu(int &x, int &y);

void renderMenu(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y);

#endif // FUNCTION_H
