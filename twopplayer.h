#ifndef TWOPLAYER_H
#define TWOPLAYER_H

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

const int MAX = 16;
//int a[MAX][MAX];

void initializeBoard(int a[][MAX]); // khoi tao ban choi

void displayBoard(int a[][MAX]); // hien thi ban choi tren terminal

void inputPlayer(int a[][MAX], int &x, int &y, int count); // nhap vao nuoc di cua nguoi choi

bool validMove(int x, int y, int a[][MAX]); // kiem tra nuoc di hop le

bool checkXWinNoBlock(int a[][MAX]); // khong chan 2 dau

bool checkOWinNoBlock(int a[][MAX]); // khong chan 2 dau

bool checkXWinBlock(int a[][MAX]); // chan hai dau

bool checkOWinBlock(int a[][MAX]); //chan hai dau

int twoPlayer(int a[][MAX], int &x, int &y, int &count, SDL_Event &event, bool quit, SDL_Texture* texture,
SDL_Renderer* renderer); // che do choi 2 nguoi

#endif // TWOPLAYER
