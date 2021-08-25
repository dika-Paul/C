#include "read_Engine.h"
#include"contact.h"

#include<iostream>
#include<cstdlib>
#include<Windows.h>

using namespace std;


SEX sex_chose(int num)
{
	if (num == 0) { return UN; }
	else if (num == 1) { return MALE; }
	else if (num == 2) { return FEMALE; }
}
void read_add()
{
	char name[LENTH] = { 0 };
	char phone[30] = { 0 };
	SEX sex = UN;
	int Sex = 0;
	char addr[LENTH] = { 0 };
	int age = 0;
	cin >> name >> phone >> Sex >> addr >> age;
	sex = sex_chose(Sex);
	add_M(name, phone, sex, addr, age);
}

void read_del()
{
	int point = 0;
	cin >> point;
	switch (point)
	{
	case 1:
	{
		char name[LENTH] = { 0 };
		cin >> name;
		del_M_N(name);
		break;
	}
	case 2:
	{
		char phone[30] = { 0 };
		cin >> phone;
		del_M_N(phone);
		break;
	}
	default:
		cout << "输入非法,请重新输入\n";
		read_del();
		break;
	}
	return;
}

void read_find()
{
	int point = 0;
	cin >> point;
	switch (point)
	{
	case 1:
	{
		char name[LENTH] = { 0 };
		cin >> name;
		print_M_N(name);
		break;
	}
	case 2:
	{
		char phone[30] = { 0 };
		cin >> phone;
		print_M_P(phone);
		break;
	}
	default:
		cout << "输入非法,请重新输入\n";
		read_del();
		break;
	}
	return;
}

void read_change()
{
	int point = 0;
	cin >> point;
	switch (point)
	{
	case 1:
	{
		char pre_name[LENTH] = { 0 };
		char name[LENTH] = { 0 };
		char phone[30] = { 0 };
		SEX sex = UN;
		int Sex = 0;
		char addr[LENTH] = { 0 };
		int age = 0;
		cin >> pre_name >> name >> phone >> Sex >> addr >> age;
		sex = sex_chose(Sex);
		change_M_N(pre_name, name, phone, sex, addr, age);
		break;
	}
	case 2:
	{
		char pre_phone[30] = { 0 };
		char name[LENTH] = { 0 };
		char phone[30] = { 0 };
		SEX sex = UN;
		int Sex = 0;
		char addr[LENTH] = { 0 };
		int age = 0;
		cin >> pre_phone >> name >> phone >> Sex >> addr >> age;
		sex = sex_chose(Sex);
		change_M_P(pre_phone, name, phone, sex, addr, age);
		break;
	}
	default:
		cout << "输入非法,请重新输入\n";
		read_del();
		break;
	}
	return;
}
