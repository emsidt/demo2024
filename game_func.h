#ifndef _GAMEFUNC__H
#define _GAMEFUNC__H

const int MAX = 16;

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

int attackPoint(int a[][MAX]);
int verticalAttackPoint(int a[][MAX]);
int horizonAttackPoint(int a[][MAX]);
int mainDiagonalAttackPoint(int a[][MAX]);
int semiDiagonalAttackPoint(int a[][MAX]);

int defensePoint(int a[][MAX]);
int verticalDefensePoint(int a[][MAX]);
int horizonDefensePoint(int a[][MAX]);
int mainDiagonalDefensePoint(int a[][MAX]);
int semiDiagonalDefensePoint(int a[][MAX]);

#endif // _GAMEFUNC__H
