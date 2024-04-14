
#ifndef __MEDIA_H
#define __MEDIA_H

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constant.h"



void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, Mix_Music *&music); // khoi tao cua so va but ve

void quitSDL(SDL_Window* window, SDL_Renderer* renderer, Mix_Music *&music); // giai phong

void waitUntilKeyPressed(); // cho su kien ban phim

SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);

void renderTexture(SDL_Texture* texture,SDL_Renderer* renderer); // tai anh toan man hinh

void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h); // tai anh theo toa do

void standardCoordinate(int &x, int &y);

int clickInMenu(int &x, int &y);

int clickInResult(int &x, int &y);

int clickInPlay(int &x, int &y);

void renderMenu(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y);

void renderXWon(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y);

void renderOWon(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y);

void renderDraw(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y);

void renderResult(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y);
#endif // __MEDIA_H
