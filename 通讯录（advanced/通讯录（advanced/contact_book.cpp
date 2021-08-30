#define _CRT_SECURE_NO_WARINGS
#define _CRT_SECURE_NO_DEPRECATE

#include"contact_book.h"
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>

namespace addr_data
{
	con_b* head = nullptr;
	unsigned long long num;
}
using namespace addr_data;

per_i* build_mem()
{
	per_i* ptr = (per_i*)malloc(sizeof(per_i));
	assert(ptr != nullptr);
	memset(ptr, 0, sizeof(ptr));
	memset(ptr->name, 0, sizeof(ptr->name));
	memset(ptr->phone, 0, sizeof(ptr->phone));
	memset(ptr->addr, 0, sizeof(ptr->addr));
	ptr->sex = 0;
	ptr->age = -1;
	return ptr;
}
con_b* build_node()
{
	con_b* ptr = (con_b*)malloc(sizeof(con_b));
	assert(ptr != nullptr);
	ptr->member = nullptr;
	ptr->next = nullptr;
	ptr->pre = nullptr;
	return ptr;
}

void member_insert(per_i* ptr)
{
	con_b* point = head;
	while (point->next != nullptr)	{ point = point->next; }
	con_b* node = build_node();
	point->next = node;
	node->pre = point;
	node->member = ptr;
	num++;
}
void member_del(con_b* ptr)
{
	assert(ptr != nullptr);
	con_b* ptr_pre = ptr->pre;
	con_b* ptr_next = ptr->next;
	ptr_pre->next = ptr_next;
	if (ptr_next != nullptr) { ptr_next->pre = ptr_pre; }
	ptr->pre = nullptr;
	ptr->pre = nullptr;
	ptr->member->per_info_del();
	free(ptr->member);
	free(ptr);
	num--;
}
void member_print(con_b* ptr)
{
	ptr->member->per_info_out();
}
void member_change(con_b* ptr, per_i* info)
{
	per_i* point = ptr->member;
	ptr->member = info;
	point->per_info_del();
	free(point);
	point = nullptr;
}
void member_show()
{
	if (head->next == nullptr)
	{
		printf("没有成员\n");
		return;
	}
	con_b* point = head->next;
	int no = 1;
	while (point != nullptr)
	{
		printf("\nNo.%d\n", no);
		point->member->per_info_out();
		point = point->next;
		no++;
	}
}
void member_clean()
{
	con_b* ptr = head->next;
	con_b* point;
	while (ptr != nullptr)
	{
		ptr->member->per_info_del();
		ptr->pre = nullptr;
		point = ptr->next;
		ptr->next = nullptr;
		free(ptr);
		ptr = point;
		num--;
	}
	num++;
	head = build_node();
}
con_b* member_find(char* str, int num)
{
	assert(num == 1 || num == 0);
	con_b* point = head->next;
	switch (num)
	{
	case 0:
		while ((point != nullptr) && (!point->member->cmp_by_name(str))) { point = point->next; }
		return point;
	case 1:
		while ((point != nullptr) && (!point->member->cmp_by_phone(str))) { point = point->next; }
		return point;
	default:
		break;
	}
}

void person_info::per_info_read(const char* Name, const char* Phone, const short Sex, const short Age, const char* Addr)
{
	strcpy(name, Name);
	strcpy(phone, Phone);
	sex = Sex;
	age = Age;
	strcpy(addr, Addr);
}
bool person_info::cmp_by_name(char* Name)
{
	bool judg_same;
	judg_same = (strcmp(name, Name) == 0) ? true : false;
	return judg_same;
}
bool person_info::cmp_by_phone(char* Phone)
{
	bool judg_same;
	judg_same = (strcmp(phone, Phone) == 0) ? true : false;
	return judg_same;
}
void person_info::per_info_out()
{
	printf("姓名：%s ", name);
	printf("电话：%s ", phone);
	switch (sex)
	{
	case 1:
		printf("性别：男 ");
		break;
	case 2:
		printf("性别：女 ");
		break;
	case 0:
		printf("性别：保密 ");
		break;
	default:
		break;
	}
	printf("年龄：%hd ", age);
	printf("住址：%s ", addr);
}
void person_info::per_info_del()
{
	memset(name, 0, sizeof(name));
	memset(phone, 0, sizeof(phone));
	memset(addr, 0, sizeof(addr));
	sex = 0;
	age = -1;
}

