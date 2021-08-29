#define _CRT_SECURE_NO_WARNINGS

#include"game.h"
#include"viewEngine.h"
#include"start.h"
#include<iostream>
#include<cstdlib>

using std::cin;
using std::cout;

void test();

int main()
{
	test();
	return 0;
}

void test()
{
	int input = 0;
	do
	{
		menu();
		cin >> input;
		switch (input)
		{
		case 1:
			game_start();
			break;
		case 2:
			return;
			break;
		default:
			cout << "错误的选择，请重新输入。\n";
			break;
		}
		system("pause");
		system("cls");
	} while (1);
}