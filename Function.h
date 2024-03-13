#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
//SDL_Window* window = nullptr;
//SDL_Surface* surface = nullptr;
//SDL_Renderer* renderer = nullptr;
//SDL_Texture* texture = nullptr;

const int MAX = 16;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 640;

//int x, y;
//int count = 0;



void initSDL(SDL_Window* &window, SDL_Renderer* &renderer); // khoi tao cua so va but ve
void quitSDL(SDL_Window* window, SDL_Renderer* renderer); // giai phong
void waitUntilKeyPressed(); // cho su kien ban phim
SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
void renderTexture(SDL_Texture* texture,SDL_Renderer* renderer); // tai anh toan man hinh
void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h); // tai anh theo toa do
void standardCoordinate(int &x, int &y);

void initializeBoard(int a[][MAX]);
void displayBoard(int a[][MAX]);
void inputPlayer(int a[][MAX], int &x, int &y, int count);
bool validMove(int x, int y, int a[][MAX]);
bool checkXWinNoBlock(int a[][MAX]);
bool checkOWinNoBlock(int a[][MAX]);
bool checkXWinBlock(int a[][MAX]);
bool checkOWinBlock(int a[][MAX]);
int click(int &x, int &y);
void clickInMenu();
void renderMenu(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y);

#endif // FUNCTION_H
