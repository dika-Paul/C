#pragma once

#define ROW 9
#define COL 9
#define BOOM 10

enum State
{
	win, lose, goingon
};

void map_set();
State state_find(int x, int y);//查看游戏状态
void node_chose(int x, int y, int choice);//将选择过后的所选区域变为点击过
void map_clean();
void click_remake();