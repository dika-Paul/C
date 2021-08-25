#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdlib>
#include<Windows.h>
#include"view_Engine.h"
#include"read_Engine.h"

using namespace std;

void test();


int main()
{
	test();
	return 0;
}

void test()
{
	int a;
	while (1)
	{
		menu_Main();
		cin >> a;
		switch (a)
		{
		case 1:
			menu_add();
			read_add();
			break;
		case 2:
			menu_del();
			read_del();
			break;
		case 3:
			menu_change();
			read_change();
			break;
		case 4:
			menu_find();
			read_find();
			break;
		case 5:
			cout << "感谢你的使用!\n";
			Sleep(3000);
			return;
			break;
		default:
			cout << "输入无效，请重新输入\n";
			
			break;
		}
		system("pause");
		system("cls");
	}
}