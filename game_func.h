#ifndef _GAMEFUNC__H
#define _GAMEFUNC__H


#include "constant.h"

struct Board
{
    int a[MAX][MAX];
    int count = 0;
    int x, y;

    void initializeBoard(int a[][MAX]); // khoi tao ban choi
    void displayBoard(int a[][MAX]); // hien thi ban choi tren terminal
    void inputPlayer(int a[][MAX], int &x, int &y, int count); // nhap vao nuoc di cua nguoi choi
    bool validMove(int x, int y, int a[][MAX]); // kiem tra nuoc di hop le
    bool checkXWinNoBlock(int a[][MAX]); // khong chan 2 dau
    bool checkOWinNoBlock(int a[][MAX]); // khong chan 2 dau
    bool checkXWinBlock(int a[][MAX]); // chan hai dau
    bool checkOWinBlock(int a[][MAX]); //chan hai dau
    // tinh diem tan cong va phong thu
    long verticalAttackPoint(int x, int y,int a[][MAX]);
    long horizonAttackPoint(int x, int y,int a[][MAX]);
    long mainDiagonalAttackPoint(int x, int y,int a[][MAX]);
    long semiDiagonalAttackPoint(int x, int y,int a[][MAX]);

    long verticalDefensePoint(int x, int y,int a[][MAX]);
    long horizonDefensePoint(int x, int y,int a[][MAX]);
    long mainDiagonalDefensePoint(int x, int y,int a[][MAX]);
    long semiDiagonalDefensePoint(int x, int y,int a[][MAX]);
    // kiem tra chan 2 dau
    bool horizonBlockX(int a[][MAX]);
    bool verticalBlockX(int a[][MAX]);
    bool mainDiagonaBlockX(int a[][MAX]);
    bool semiDiagonaBlockX(int a[][MAX]);
    //Move findBestMove(int a[][MAX]);

};





#endif // _GAMEFUNC__H
