#pragma once

#define ROW 9
#define COL 9
#define BOOM 10

enum State
{
	win, lose, goingon
};

void map_set();
State state_find(int x, int y);//�鿴��Ϸ״̬
void node_chose(int x, int y, int choice);//��ѡ��������ѡ�����Ϊ�����
void map_clean();
void click_remake();