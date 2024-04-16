#ifndef __CONSTANT_H
#define __CONSTANT_H

#include <SDL_mixer.h>
const int MAX = 16;
const long defensePoint[7] = { 0, 1, 9, 81, 729, 6561, 59049 };
const long attackPoint[7] = { 0, 3, 24, 192, 1536, 12288, 98304 };

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 640;

struct Move
{
	int x;
	int y;
};


#endif // __CONSTANT_H
