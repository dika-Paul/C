#include"start.h"
#include"game.h"
#include"viewEngine.h"
#include<iostream>
#include<cstdlib>

#define FOR(A, B, C) for(int (C) = (A); (C) < (B); (C)++)

using namespace std;

extern bool Boom_m[ROW][COL];
extern int num_m[ROW][COL];
extern bool Click_m[ROW][COL];

bool judg(int x, int y);

void game_start()
{
	int x = 0;
	int y = 0;
	int choice = 0;
	bool boom_point = false;
	map_clean();
	map_set();
	click_remake();
	map_view();
	while (1)
	{
		cout << "������Ҫѡ���λ�ã� ";
		cin >> x >> y;
		x--;
		y--;
		if (!judg(x, y)) continue;
		menu2();
		cin >> choice;
		system("cls");
		node_chose(x, y, choice);
		map_view();
		switch (state_find(x, y))
		{
		case win:
			cout << "��Ӯ�ˣ�����\n";
			return;
			break;
		case lose:
			cout << "��ȵ��˵��ס�\n";
			return;
			break;
		default:
			cout << "��Ϸ����\n";
			break;
		}
	}
}
bool judg(int x, int y)
{
	if (x >= ROW || y >= COL || Click_m[x][y])
	{
		cout << "�˴�����ѡ��������ѡ��\n";
		return false;
	}
	else
	{
		return true;
	}
}