#ifndef _GAMEFUNC__H
#define _GAMEFUNC__H

const int MAX = 16;
const long defensePoint[7] = { 0, 1, 10, 100, 1000, 5000, 50000 };
const long attackPoint[7] = { 0, 3, 30, 250, 2000, 12000, 100000 };

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

bool twoBlockX(int a[][MAX]);

#endif // _GAMEFUNC__H
