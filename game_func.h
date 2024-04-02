#ifndef _GAMEFUNC__H
#define _GAMEFUNC__H

const int MAX = 16;
const long defensePoint[7] = { 0, 1, 9, 81, 729, 6561, 59049 };
const long attackPoint[7] = { 0, 3, 24, 192, 1536, 12288, 98304 };

struct Move
{
	int x;
	int y;
};

void initializeBoard(int a[][MAX]); // khoi tao ban choi

void displayBoard(int a[][MAX]); // hien thi ban choi tren terminal

void inputPlayer(int a[][MAX], int &x, int &y, int count); // nhap vao nuoc di cua nguoi choi

bool validMove(int x, int y, int a[][MAX]); // kiem tra nuoc di hop le

bool checkXWinNoBlock(int a[][MAX]); // khong chan 2 dau

bool checkOWinNoBlock(int a[][MAX]); // khong chan 2 dau

bool checkXWinBlock(int a[][MAX]); // chan hai dau

bool checkOWinBlock(int a[][MAX]); //chan hai dau

int botPlayX();
int botPLayY();


long verticalAttackPoint(int x, int y,int a[][MAX]);
long horizonAttackPoint(int x, int y,int a[][MAX]);
long mainDiagonalAttackPoint(int x, int y,int a[][MAX]);
long semiDiagonalAttackPoint(int x, int y,int a[][MAX]);

long verticalDefensePoint(int x, int y,int a[][MAX]);
long horizonDefensePoint(int x, int y,int a[][MAX]);
long mainDiagonalDefensePoint(int x, int y,int a[][MAX]);
long semiDiagonalDefensePoint(int x, int y,int a[][MAX]);

#endif // _GAMEFUNC__H
