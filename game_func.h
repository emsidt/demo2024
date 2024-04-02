#ifndef _GAMEFUNC__H
#define _GAMEFUNC__H

const int MAX = 16;
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


int verticalAttackPoint(int i, int j);
int horizonAttackPoint(int i, int j);
int mainDiagonalAttackPoint(int i, int j);
int semiDiagonalAttackPoint(int i, int j);

int verticalDefensePoint(int i, int j);
int horizonDefensePoint(int i, int j);
int mainDiagonalDefensePoint(int i, int j);
int semiDiagonalDefensePoint(int i, int j);

#endif // _GAMEFUNC__H
