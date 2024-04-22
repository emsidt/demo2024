#include <ctime>
#include "constant.h"
#include <iostream>
#include "media.h"
#include "game_func.h"



bool Board::horizonBlockX(int a[][MAX])
{
    bool ok = false;
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            if (a[i][j] == 0)
            {
                int x1 = 0;
                int x2 = 0;
                for (int k = j - 1; k >= 0; k--)
                {
                    if (a[i][k] == 2)
                    {
                        x1 = k;
                        break;
                    }
                }
                for (int k = j + 1; k < MAX; k++)
                {
                    if (a[i][k] == 2)
                    {
                        x2 = k;
                        break;
                    }
                }
                if (abs(x1 - x2) <= 6 && abs(x1 - x2) > 0)
                {
                    ok = true;
                    // std::cout << "horizon true";
                }
            }
        }
    }
    return ok;
}

bool Board::verticalBlockX(int a[][MAX])
{
    bool ok = false;
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            if (a[i][j] == 0)
            {
                int x1 = 0;
                int x2 = 0;
                for (int k = i - 1; k >= 0; k--)
                {
                    if (a[k][j] == 2)
                    {
                        x1 = k;
                        break;
                    }
                }
                for (int k = i + 1; k < MAX; k++)
                {
                    if (a[k][j] == 2)
                    {
                        x2 = k;
                        break;
                    }
                }
                if (abs(x1 - x2) <= 6 && abs(x1 - x2) > 0)
                {
                    ok = true;
                    // std::cout << "vertical true";
                }
            }
        }
    }
    return ok;
}

bool Board::mainDiagonaBlockX(int a[][MAX])
{
    bool ok = false;
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            if (a[i][j] == 0)
            {
                int x1 = 0;
                int x2 = 0;
                for (int k = i + 1; k < MAX; k++)
                {
                    if (a[k][k] == 2)
                    {
                        x1 = k;
                        break;
                    }
                }
                for (int k = i - 1; k >= 0; k--)
                {
                    if (a[k][k] == 2)
                    {
                        x2 = k;
                        break;
                    }
                }
                if (abs(x1 - x2) <= 6 && abs(x1 - x2) > 0)
                {
                    ok = true;
                    // std::cout << "main diagonal true";
                }
            }

        }
    }
    return ok;
}


bool Board::semiDiagonaBlockX(int a[][MAX])
{
    bool ok = false;
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            if (a[i][j] == 0)
            {
                int x1 = 0;
                int x2 = 0;
                for (int k = 1; k <= 5; k++)
                {
                    if (a[i - k][j + k] == 2)
                    {
                        x1 = k;
                        break;
                    }
                }
                for (int k = 1; k <= 5; k++)
                {
                    if (a[i + k][j - k] == 2)
                    {
                        x2 = k;
                        break;
                    }
                }
                if (abs(x1 - x2) <= 6 && abs(x1 - x2) > 0)
                {
                    ok = true;
                    // std::cout << "semi diagonal true";
                }
            }
        }
    }
    return ok;
}

long Board::verticalAttackPoint(int x, int y, int a[][MAX])
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
	if (verticalBlockX(a) && enemies == 2)
    {
        totalVal = 0;
    }
    else
    {
        totalVal -= defensePoint[enemies];
        totalVal += attackPoint[allies + 1];
    }



	return totalVal;

}

long Board::horizonAttackPoint(int x, int y,int a[][MAX])
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
    if (horizonBlockX(a) && enemies == 2)
    {
        totalVal = 0;
    }
    else
    {
        totalVal -= defensePoint[enemies];
        totalVal += attackPoint[allies + 1];
    }


	return totalVal;
}
long Board::mainDiagonalAttackPoint(int x, int y,int a[][MAX])
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
    if (mainDiagonaBlockX(a) && enemies == 2)
    {
        totalVal = 0;
    }
    else
    {
        totalVal -= defensePoint[enemies];
        totalVal += attackPoint[allies + 1];
    }

	return totalVal;
}

long Board::semiDiagonalAttackPoint(int x, int y,int a[][MAX])
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
	if (semiDiagonaBlockX(a) && enemies == 2)
    {
        totalVal = 0;
    }
    else
    {
        totalVal -= defensePoint[enemies];
        totalVal += attackPoint[allies + 1];
    }

	return totalVal;
}

long Board::verticalDefensePoint(int x, int y,int a[][MAX])
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

	totalVal += defensePoint[enemies + 1];

	return totalVal;
}
long Board::horizonDefensePoint(int x, int y,int a[][MAX])
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

	totalVal += defensePoint[enemies + 1];
	return totalVal;
}
long Board::mainDiagonalDefensePoint(int x, int y,int a[][MAX])
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
long Board::semiDiagonalDefensePoint(int x, int y,int a[][MAX])
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













void Board::initializeBoard(int a[][MAX]){
    for( int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j){
            a[i][j] = 0;
        }
    }
}

void Board::displayBoard(int a[][MAX]){
    //system("cls");
    for( int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j){
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


bool Board::validMove(int x, int y, int a[][MAX]){
    if(a[y][x] == 0 && x <= 15 && y <= 15) return true;
    else return false;
}

bool Board::checkXWinBlock(int a[][MAX]){
    // check hang ngang
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1
                && a[i][j+1] == 1
                && a[i][j+2] == 1
                && a[i][j+3] == 1
                && a[i][j+4] == 1
                && (a[i][j+5] == 0 || a[i][j-1] == 0))

                return true;
        }
    }
    //check hang doc
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1
                && a[i+1][j] == 1
                && a[i+2][j] == 1
                && a[i+3][j] == 1
                && a[i+4][j] == 1
                && (a[i-1][j] == 0 || a[i+5][j] == 0))
                return true;
        }
    }
    // check hang cheo 1
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1
                && a[i+1][j+1] == 1
                && a[i+2][j+2] == 1
                && a[i+3][j+3] == 1
                && a[i+4][j+4] == 1
                && (a[i-1][j-1] == 0 || a[i+5][j+5] == 0))
                return true;
        }
    }

    // check hang cheo 2
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 1
                && a[i+1][j-1] == 1
                && a[i+2][j-2] == 1
                && a[i+3][j-3] == 1
                && a[i+4][j-4] == 1
                && (a[i-1][j+1] == 0 || a[i+5][j-5] == 0))
                return true;
        }
    }
    return false;

}

bool Board::checkOWinBlock(int a[][MAX]){
    // check hang ngang
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2
                && a[i][j+1] == 2
                && a[i][j+2] == 2
                && a[i][j+3] == 2
                && a[i][j+4] == 2
                && (a[i][j+5] == 0 || a[i][j-1] == 0))
                return true;
        }
    }
    //check hang doc
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2
                && a[i+1][j] == 2
                && a[i+2][j] == 2
                && a[i+3][j] == 2
                && a[i+4][j] == 2
                && (a[i-1][j] == 0 || a[i+5][j] == 0))
                return true;
        }
    }
    // check hang cheo 1
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2
                && a[i+1][j+1] == 2
                && a[i+2][j+2] == 2
                && a[i+3][j+3] == 2
                && a[i+4][j+4] == 2
                && (a[i-1][j-1] == 0 || a[i+5][j+5] == 0))
                return true;

        }
    }

    // check hang cheo 2
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j] == 2
                && a[i+1][j-1] == 2
                && a[i+2][j-2] == 2
                && a[i+3][j-3] == 2
                && a[i+4][j-4] == 2
                && (a[i-1][j+1] == 0 || a[i+5][j-5] == 0))
                return true;

        }
    }
    return false;
}

