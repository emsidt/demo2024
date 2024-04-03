#include "Function.h"
#include <ctime>

int botPlayX()
{

	int n = rand() % (620 - 75) + 75 + 1;

	return n;
}
int botPLayY()
{

	int n = rand() % (590 - 50) + 50 + 1;
	return n;
}



long verticalAttackPoint(int x, int y,int a[][MAX])
{
	long totalVal = 0;
	int allies = 0;
	int enemies = 0;

	for (int i = 1; i < 6 && x + i < MAX; ++i)
	{
		if (a[x+i][y] == 1)
		{
			allies++;
		}
		else if (a[x+i][y] == 2)
		{
			enemies++;
			break;
		}
		else break;
	}
	for (int i = 1; i < 6 && x - i >= 0; i++)
	{
		if (a[x-i][y] == 1)
		{
			allies++;
		}
		else if (a[x-i][y] == 2)
		{
			enemies++;
			break;
		}
		else break;
	}

	totalVal -= defensePoint[enemies];
	totalVal += attackPoint[allies];

	return totalVal;

}

long horizonAttackPoint(int x, int y,int a[][MAX])
{
	long totalVal = 0;
	int allies = 0;
	int enemies = 0;

	for (int i = 1; i < 6 && y + i < MAX; ++i)
	{
		if (a[x][y+i] == 1)
		{
			allies++;
		}
		else if (a[x][y+i] == 2)
		{
			enemies++;
			break;

		}
		else break;
	}
	for (int i = 1; i < 6 && y - i >= 0; i++)
	{
		if (a[x][y-i] == 1)
		{
			allies++;
		}
		else if (a[x][y-i] == 2)
		{
			enemies++;
			break;
		}
		else break;
	}

	totalVal -= defensePoint[enemies];
	totalVal += attackPoint[allies];

	return totalVal;
}
long mainDiagonalAttackPoint(int x, int y,int a[][MAX])
{
	long totalVal = 0;
	int allies = 0;
	int enemies = 0;

	for (int i = 1; i < 6 && x + i < MAX && y + i < MAX; i++)
	{

		if (a[x + i][y + i] == 1)
		{
			allies++;
		}
		else if (a[x + i][y + i] == 2)
		{
			enemies++;
			break;
		}
		else
		{

			break;
		}
	}

	for (int i = 1; i < 6 && x - i >= 0 && y - i >= 0; i++)
	{

		if (a[x - i][y - i] == 1)
		{
			allies++;
		}
		else if (a[x - i][y - i] == 2)
		{

			enemies++;
			break;
		}
		else
		{

			break;
		}
	}

	totalVal -= defensePoint[enemies + 1];
	totalVal += attackPoint[allies];

	return totalVal;
}

long semiDiagonalAttackPoint(int x, int y,int a[][MAX])
{
	long totalVal = 0;
	int allies = 0;
	int enemies = 0;
	for (int i = 1; i < 6 && x - i >= 0 && y + i < MAX; i++)
	{

		if (a[x - i][y + i] == 1)
		{
			allies++;
		}
		else if (a[x - i][y + i] == 2)
		{
			enemies++;
			break;
		}
		else
		{

			break;
		}
	}

	for (int i = 1; i < 6 && x + i >= 0 && y - i >= 0; i++)
	{

		if (a[x + i][y - i] == 1)
		{
			allies++;
		}
		else if (a[x + i][y - i] == 2)
		{

			enemies++;
			break;
		}
		else
		{

			break;
		}
	}

	totalVal -= defensePoint[enemies + 1];
	totalVal += attackPoint[allies];

	return totalVal;
}

long verticalDefensePoint(int x, int y,int a[][MAX])
{
	long totalVal = 0;
	int allies = 0;
	int enemies = 0;

	for (int i = 1; i < 6 && x + i < MAX; ++i)
	{
		if (a[x+i][y] == 1)
		{
			allies++;
			break;
		}
		else if (a[x+i][y] == 2)
		{
			enemies++;
		}
		else break;
	}
	for (int i = 1; i < 6 && x - i >= 0; i++)
	{
		if (a[x-i][y] == 1)
		{
			allies++;
			break;
		}
		else if (a[x-i][y] == 2)
		{
			enemies++;
		}
		else break;
	}

	totalVal += defensePoint[enemies];

	return totalVal;
}
long horizonDefensePoint(int x, int y,int a[][MAX])
{
	long totalVal = 0;
	int allies = 0;
	int enemies = 0;

	for (int i = 1; i < 6 && y + i < MAX; ++i)
	{
		if (a[x][y+i] == 1)
		{
			allies++;
			break;
		}
		else if (a[x][y+i] == 2)
		{
			enemies++;
		}
		else break;
	}
	for (int i = 1; i < 6 && y - i >= 0; i++)
	{
		if (a[x][y-i] == 1)
		{
			allies++;
			break;
		}
		else if (a[x][y-i] == 2)
		{
			enemies++;
		}
		else break;
	}

	totalVal += defensePoint[enemies];
	return totalVal;
}
long mainDiagonalDefensePoint(int x, int y,int a[][MAX])
{
	long totalVal = 0;
	int allies = 0;
	int enemies = 0;

	for (int i = 1; i < 6 && x + i < MAX && y + i < MAX; i++)
	{

		if (a[x + i][y + i] == 1)
		{
			allies++;
			break;
		}
		else if (a[x + i][y + i] == 2)
		{
			enemies++;
		}
		else
		{

			break;
		}
	}

	for (int i = 1; i < 6 && x - i >= 0 && y - i >= 0; i++)
	{

		if (a[x - i][y - i] == 1)
		{
			allies++;
			break;
		}
		else if (a[x - i][y - i] == 2)
		{

			enemies++;
		}
		else
		{

			break;
		}
	}

	totalVal += defensePoint[enemies + 1];
	return totalVal;
}
long semiDiagonalDefensePoint(int x, int y,int a[][MAX])
{
	long totalVal = 0;
	int allies = 0;
	int enemies = 0;
	for (int i = 1; i < 6 && x - i >= 0 && y + i < MAX; i++)
	{

		if (a[x - i][y + i] == 1)
		{
			allies++;
			break;
		}
		else if (a[x - i][y + i] == 2)
		{
			enemies++;
		}
		else
		{

			break;
		}
	}

	for (int i = 1; i < 6 && x + i < MAX && y - i >= 0; i++)
	{

		if (a[x + i][y - i] == 1)
		{
			allies++;
			break;
		}
		else if (a[x + i][y - i] == 2)
		{

			enemies++;
		}
		else
		{

			break;
		}
	}

	totalVal += defensePoint[enemies + 1];

	return totalVal;
}












void initializeBoard(int a[][MAX]){
    for( int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j){
            a[i][j] = 0;
        }
    }
}

void displayBoard(int a[][MAX]){
    //system("cls");
    for( int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j){
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void inputPlayer(int a[][MAX], int &x, int &y, int count){
    if(count%2 == 0){
        a[x][y] == 1;
    }
    else a[x][y] = 2;
}

bool validMove(int x, int y, int a[][MAX]){
    if(a[y][x] == 0 && x <= 15 && y <= 15) return true;
    else return false;
}

bool checkXWinBlock(int a[][MAX]){
    // check hang ngang
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1){
                if(a[i][j+1] == 1 && a[i][j+2] == 1 && a[i][j+3] == 1 && a[i][j+4] == 1 && (a[i][j+5] == 0 || a[i][j-1] == 0)) return true;
                if(a[i][j+1] == 1 && a[i][j+2] == 1 && a[i][j+3] == 1 && a[i][j-1] == 1 && (a[i][j+4] == 0 || a[i][j-2] == 0)) return true;
                if(a[i][j+1] == 1 && a[i][j+2] == 1 && a[i][j-1] == 1 && a[i][j-2] == 1 && (a[i][j+3] == 0 || a[i][j-3] == 0)) return true;
                if(a[i][j+1] == 1 && a[i][j-1] == 1 && a[i][j-2] == 1 && a[i][j-3] == 1 && (a[i][j+2] == 0 || a[i][j-4] == 0)) return true;
                if(a[i][j-1] == 1 && a[i][j-2] == 1 && a[i][j-3] == 1 && a[i][j-4] == 1 && (a[i][j+1] == 0 || a[i][j-5] == 0)) return true;
            }
        }
    }
    //check hang doc
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1){
                if(a[i+1][j] == 1 && a[i+2][j] == 1 && a[i+3][j] == 1 && a[i+4][j] == 1 && (a[i-1][j] == 0 || a[i+5][j] == 0)) return true;
                if(a[i-1][j] == 1 && a[i+1][j] == 1 && a[i+2][j] == 1 && a[i+3][j] == 1 && (a[i-2][j] == 0 || a[i+4][j] == 0)) return true;
                if(a[i-2][j] == 1 && a[i-1][j] == 1 && a[i+1][j] == 1 && a[i+2][j] == 1 && (a[i-3][j] == 0 || a[i+3][j] == 0)) return true;
                if(a[i-3][j] == 1 && a[i-2][j] == 1 && a[i-1][j] == 1 && a[i+1][j] == 1 && (a[i-4][j] == 0 || a[i+2][j] == 0)) return true;
                if(a[i-4][j] == 1 && a[i-3][j] == 1 && a[i-2][j] == 1 && a[i-1][j] == 1 && (a[i-5][j] == 0 || a[i+1][j] == 0)) return true;
            }
        }
    }
    // check hang cheo 1
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1){
                if(a[i+1][j+1] == 1 && a[i+2][j+2] == 1 && a[i+3][j+3] == 1 && a[i+4][j+4] == 1 && (a[i-1][j-1] == 0 || a[i+5][j+5] == 0)) return true;
                if(a[i-1][j-1] == 1 && a[i+1][j+1] == 1 && a[i+2][j+2] == 1 && a[i+3][j+3] == 1 && (a[i-2][j-2] == 0 || a[i+4][j+4] == 0)) return true;
                if(a[i-2][j-2] == 1 && a[i-1][j-1] == 1 && a[i+1][j+1] == 1 && a[i+2][j+2] == 1 && (a[i-3][j-3] == 0 || a[i+3][j+3] == 0)) return true;
                if(a[i-3][j-3] == 1 && a[i-2][j-2] == 1 && a[i-1][j-1] == 1 && a[i+1][j+1] == 1 && (a[i-4][j-4] == 0 || a[i+2][j+2] == 0)) return true;
                if(a[i-4][j-4] == 1 && a[i-3][j-3] == 1 && a[i-2][j-2] == 1 && a[i-1][j-1] == 1 && (a[i-5][j-5] == 0 || a[i+1][j+1] == 0)) return true;
            }
        }
    }

    // check hang cheo 2
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1){
                if(a[i+1][j-1] == 1 && a[i+2][j-2] == 1 && a[i+3][j-3] == 1 && a[i+4][j-4] == 1 && (a[i-1][j+1] == 0 || a[i+5][j-5] == 0)) return true;
                if(a[i+1][j-1] == 1 && a[i+2][j-2] == 1 && a[i+3][j-3] == 1 && a[i-1][j+1] == 1 && (a[i-2][j+2] == 0 || a[i+4][j-4] == 0)) return true;
                if(a[i+2][j-2] == 1 && a[i+2][j-2] == 1 && a[i-1][j+1] == 1 && a[i-2][j+2] == 1 && (a[i-3][j+3] == 0 || a[i+3][j-3] == 0)) return true;
                if(a[i+1][j-1] == 1 && a[i-1][j+1] == 1 && a[i-2][j+2] == 1 && a[i-3][j+3] == 1 && (a[i-4][j+4] == 0 || a[i+2][j-2] == 0)) return true;
                if(a[i-1][j+1] == 1 && a[i-2][j+2] == 1 && a[i-3][j+3] == 1 && a[i-4][j+4] == 1 && (a[i-5][j+5] == 0 || a[i+1][j-1] == 0)) return true;
            }
        }
    }
    return false;

}

bool checkOWinBlock(int a[][MAX]){
    // check hang ngang
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2){
                if(a[i][j+1] == 2 && a[i][j+2] == 2 && a[i][j+3] == 2 && a[i][j+4] == 2 && (a[i][j+5] == 0 || a[i][j-1] == 0)) return true;
                if(a[i][j+1] == 2 && a[i][j+2] == 2 && a[i][j+3] == 2 && a[i][j-1] == 2 && (a[i][j+4] == 0 || a[i][j-2] == 0)) return true;
                if(a[i][j+1] == 2 && a[i][j+2] == 2 && a[i][j-1] == 2 && a[i][j-2] == 2 && (a[i][j+3] == 0 || a[i][j-3] == 0)) return true;
                if(a[i][j+1] == 2 && a[i][j-1] == 2 && a[i][j-2] == 2 && a[i][j-3] == 2 && (a[i][j+2] == 0 || a[i][j-4] == 0)) return true;
                if(a[i][j-1] == 2 && a[i][j-2] == 2 && a[i][j-3] == 2 && a[i][j-4] == 2 && (a[i][j+1] == 0 || a[i][j-5] == 0)) return true;
            }
        }
    }
    //check hang doc
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2){
                if(a[i+1][j] == 2 && a[i+2][j] == 2 && a[i+3][j] == 2 && a[i+4][j] == 2 && (a[i-1][j] == 0 || a[i+5][j] == 0)) return true;
                if(a[i-1][j] == 2 && a[i+1][j] == 2 && a[i+2][j] == 2 && a[i+3][j] == 2 && (a[i-2][j] == 0 || a[i+4][j] == 0)) return true;
                if(a[i-2][j] == 2 && a[i-1][j] == 2 && a[i+1][j] == 2 && a[i+2][j] == 2 && (a[i-3][j] == 0 || a[i+3][j] == 0)) return true;
                if(a[i-3][j] == 2 && a[i-2][j] == 2 && a[i-1][j] == 2 && a[i+1][j] == 2 && (a[i-4][j] == 0 || a[i+2][j] == 0)) return true;
                if(a[i-4][j] == 2 && a[i-3][j] == 2 && a[i-2][j] == 2 && a[i-1][j] == 2 && (a[i-5][j] == 0 || a[i+1][j] == 0)) return true;
            }
        }
    }
    // check hang cheo 1
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2){
                if(a[i+1][j+1] == 2 && a[i+2][j+2] == 2 && a[i+3][j+3] == 2 && a[i+4][j+4] == 2 && (a[i-1][j-1] == 0 || a[i+5][j+5] == 0)) return true;
                if(a[i-1][j-1] == 2 && a[i+1][j+1] == 2 && a[i+2][j+2] == 2 && a[i+3][j+3] == 2 && (a[i-2][j-2] == 0 || a[i+4][j+4] == 0)) return true;
                if(a[i-2][j-2] == 2 && a[i-1][j-1] == 2 && a[i+1][j+1] == 2 && a[i+2][j+2] == 2 && (a[i-3][j-3] == 0 || a[i+3][j+3] == 0)) return true;
                if(a[i-3][j-3] == 2 && a[i-2][j-2] == 2 && a[i-1][j-1] == 2 && a[i+1][j+1] == 2 && (a[i-4][j-4] == 0 || a[i+2][j+2] == 0)) return true;
                if(a[i-4][j-4] == 2 && a[i-3][j-3] == 2 && a[i-2][j-2] == 2 && a[i-1][j-1] == 2 && (a[i-5][j-5] == 0 || a[i+1][j+1] == 0)) return true;
            }
        }
    }

    // check hang cheo 2
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2){
                if(a[i+1][j-1] == 2 && a[i+2][j-2] == 2 && a[i+3][j-3] == 2 && a[i+4][j-4] == 2 && (a[i-1][j+1] == 0 || a[i+5][j-5] == 0)) return true;
                if(a[i+1][j-1] == 2 && a[i+2][j-2] == 2 && a[i+3][j-3] == 2 && a[i-1][j+1] == 2 && (a[i-2][j+2] == 0 || a[i+4][j-4] == 0)) return true;
                if(a[i+2][j-2] == 2 && a[i+2][j-2] == 2 && a[i-1][j+1] == 2 && a[i-2][j+2] == 2 && (a[i-3][j+3] == 0 || a[i+3][j-3] == 0)) return true;
                if(a[i+1][j-1] == 2 && a[i-1][j+1] == 2 && a[i-2][j+2] == 2 && a[i-3][j+3] == 2 && (a[i-4][j+4] == 0 || a[i+2][j-2] == 0)) return true;
                if(a[i-1][j+1] == 2 && a[i-2][j+2] == 2 && a[i-3][j+3] == 2 && a[i-4][j+4] == 2 && (a[i-5][j+5] == 0 || a[i+1][j-1] == 0)) return true;
            }
        }
    }
    return false;
}

