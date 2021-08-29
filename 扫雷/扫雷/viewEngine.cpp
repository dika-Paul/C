#include"viewEngine.h"
#include"game.h"
#include<iostream>

#define FOR(A, B, C) for(int (C) = (A); (C) < (B); (C)++)

extern bool Boom_m[ROW][COL];//存放炸弹所在位置
extern int num_m[ROW][COL];//计算地图上应出现的数字
extern bool Click_m[ROW][COL];//记忆某个区域是否被点击过
extern bool flag_m[ROW][COL];//插旗

using namespace std;

void menu()
{
	cout << "######################\n";
	cout << "####### 1.start ######\n";
	cout << "######################\n";
	cout << "####### 2. exit ######\n";
	cout << "######################\n";
}

void menu2()
{
	cout << "######################\n";
	cout << "####### 1. 查看 ######\n";
	cout << "######################\n";
	cout << "####### 2. 插旗 ######\n";
	cout << "######################\n";
}

void map_view()
{
	cout << " ";
	FOR(0, ROW, i)
	{
		cout << " " << i + 1;
	}
	cout << endl;
	FOR(0, ROW, i)
	{
		cout << i + 1;
		FOR(0, COL, j)
		{
			if (Click_m[i][j])
			{
				if (flag_m[i][j])
				{
					cout << " !";
				}
				else if (Boom_m[i][j])
				{
					cout << " @";
				}
				else
				{
					cout << " " << num_m[i][j];
				}
			}
			else
			{
				cout << " #";
			}
		}
		cout << endl;
	}
}
