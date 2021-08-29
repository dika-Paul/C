#define _CRT_SECURE_NO_WARNINGS

#include"game.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

#define FOR(A, B, C) for(int (C) = (A); (C) < (B); (C)++)

using std::cout;

bool Boom_m[ROW][COL];//存放炸弹所在位置
int num_m[ROW][COL];//计算地图上应出现的数字
bool Click_m[ROW][COL];//记忆某个区域是否被点击过
bool flag_m[ROW][COL];

void map_set()
{
    srand((unsigned)time(NULL));
    int x = 0;
    int y = 0;
    FOR(0, BOOM, i)
    {
        do
        {
            x = rand() % ROW;
            y = rand() % COL;
        } while (Boom_m[x][y]);
        Boom_m[x][y] = true;
        int a = 0;
        int b = 0;
        FOR(-1, 2, j)
        {
            FOR(-1, 2, k)
            {
                a = x + j;
                b = y + k;
                if (a >= 0 && a < ROW && b >= 0 && b < COL)
                {
                    num_m[a][b]++;
                }
            }
        }
    }
}

State state_find(int x, int y)
{
    if (Boom_m[x][y] && !flag_m[x][y]) return lose;
    else
    {
        FOR(0, ROW, i)
        {
            FOR(0, COL, j)
            {
                if (!Click_m[i][j])
                {
                    return goingon;
                }
            }
        }
        return win;
    }
}

void node_click(int x, int y);
void node_chose(int x, int y, int choice)
{
    if (choice == 1)
    {
        node_click(x, y);
    }
    else if (choice == 2)
    {
        Click_m[x][y] = true;
        flag_m[x][y] = true;
    }
    else
    {
        cout << "错误的选项，请重新输入。\n";
        system("pause");
    }
}
void node_click(int x, int y)
{
    if (x >= ROW || x < 0 || y >= COL || y < 0)
    {
        return;
    }
    else if (Click_m[x][y])
    {
        return;
    }
    else if (Boom_m[x][y] || num_m[x][y] != 0)
    {
        Click_m[x][y] = true;
        return;
    }
    else
    {
        Click_m[x][y] = true;
        FOR(x - 1, x + 2, i)
        {
            FOR(y - 1, y + 2, j)
            {
                node_click(i, j);
            }
        }
    }
}

void map_clean()
{
    FOR(0, ROW, i)
    {
        FOR(0, COL, j)
        {
            Boom_m[i][j] = false;
            num_m[i][j] = 0;
            flag_m[i][j] = false;
        }
    }
}

void click_remake()
{
    FOR(0, ROW, i)
    {
        FOR(0, COL, j)
        {
            Click_m[i][j] = false;
        }
    }
}
