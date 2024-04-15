#ifndef __CONSTANT_H
#define __CONSTANT_H

#include <SDL_mixer.h>
const int MAX = 16;
const long defensePoint[7] = { 0, 1, 10, 100, 1000, 5000, 50000 };
const long attackPoint[7] = { 0, 5, 30, 500, 2000, 12000, 100000 };

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 640;

struct Move
{
	int x;
	int y;
};


#endif // __CONSTANT_H
