#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

#include<stdio.h>
#include<cstdlib>
#include<cstring>


typedef struct member_Inf
{
	char name[LENTH];
	char ph_num[30];
	SEX sex;
	char addr[LENTH];
	int age;
}mem_I;

typedef struct inf_Link
{
	struct inf_Link* pre;
	mem_I* mem_Inf;
	struct inf_Link* next;
}inf_L;

int member = 0;
inf_L* star_Member[MAXN];
inf_L* head = nullptr;

void clean_mem(mem_I* m_ptr)
{
	memset(m_ptr->name, 0, sizeof(m_ptr->name));
	memset(m_ptr->addr, 0, sizeof(m_ptr->addr));
	memset(m_ptr->ph_num, 0, sizeof(m_ptr->ph_num));
	m_ptr->age = 0;
	m_ptr->sex = UN;
	return;
}
void clean_list(inf_L* l_Ptr)
{
	l_Ptr->pre = nullptr;
	l_Ptr->next = nullptr;
	clean_mem(l_Ptr->mem_Inf);
	return;
}
inf_L* build_M()
{
	inf_L* l_Ptr = nullptr;
	mem_I* m_Ptr = nullptr;
	l_Ptr = (inf_L*)malloc(sizeof(inf_L));
	m_Ptr = (mem_I*)malloc(sizeof(mem_I));
	memset(l_Ptr, 0, sizeof(l_Ptr));
	memset(m_Ptr, 0, sizeof(m_Ptr));
	l_Ptr->mem_Inf = m_Ptr;
	clean_list(l_Ptr);
	return l_Ptr;
}

bool judg_M_N(inf_L* ptr, const char* name)
{
	if (ptr == nullptr)	return true;
	char* this_name = ptr->mem_Inf->name;
	int judg_Tem = strcmp(this_name, name);
	return judg_Tem == 0 ? true : false;
}
inf_L* find_M_N(const char* name)
{
	inf_L* beacon = head->next;
	while (!judg_M_N(beacon, name)) { beacon = beacon->next; }
	return beacon;
}

bool judg_M_P(inf_L* ptr, const char* phone)
{
	if (ptr == nullptr)	return true;
	char* this_phone = ptr->mem_Inf->ph_num;
	int judg_Tem = strcmp(this_phone, phone);
	return judg_Tem == 0 ? true : false;
}
inf_L* find_M_P(const char* phone)
{
	inf_L* beacon = head->next;
	while (!judg_M_P(beacon, phone)) { beacon = beacon->next; }
	return beacon;
}

void end_Put(inf_L* list, inf_L* ptr)
{
	while (list->next != nullptr)	{ list = list->next; }
	list->next = ptr;
	ptr->pre = list;
	return;
}
void inf_P(const char* name, const char* phone, const SEX sex, const char* addr, const int age, mem_I* ptr)
{
	strcpy(ptr->name, name);
	strcpy(ptr->ph_num, phone);
	ptr->sex = sex;
	strcpy(ptr->addr, addr);
	ptr->age = age;
	return;
}
int add_M(const char* name, const char* phone, const SEX sex, const char* addr, const int age)
{
	if (member > MAXN) { return 0; }
	if (member == 0) { head = build_M(); }	
	inf_L* ptr = build_M();
	inf_L* beacon = head;
	end_Put(beacon, ptr);
	mem_I* tem = ptr->mem_Inf;
	inf_P(name, phone, sex, addr, age, tem);
	member++;
	return 1;
}

int del_M_N(const char* name)
{
	inf_L* ptr = find_M_N(name);
	if (ptr == nullptr) { printf("查无此人\n"); return 0; }
	inf_L* tem_n = ptr->next;
	inf_L* tem_p = ptr->pre;
	clean_list(ptr);
	free(ptr);
	ptr == nullptr;
	member--;
	tem_p->next = tem_n;
	if (tem_n != nullptr) { tem_n->pre = tem_p; }
	return 1;
}

int del_M_P(const char* phone)
{
	inf_L* ptr = find_M_N(phone);
	if (ptr == nullptr) { printf("查无此人\n"); return 0; }
	inf_L* tem_n = ptr->next;
	inf_L* tem_p = ptr->pre;
	clean_list(ptr);
	free(ptr);
	ptr == nullptr;
	member--;
	tem_p->next = tem_n;
	if (tem_n != nullptr) { tem_n->pre = tem_p; }
	return 1;
}

int change_M_N(const char* pre_Name, const char* name, const char* phone, const SEX sex, const char* addr, const int age)
{
	inf_L* ptr = find_M_N(pre_Name);
	if (ptr == nullptr) { return 0; }
	inf_P(name, phone, sex, addr, age, ptr->mem_Inf);
	return 1;
}

int change_M_P(const char* pre_Phone, const char* name, const char* phone, const SEX sex, const char* addr, const int age)
{
	inf_L* ptr = find_M_P(pre_Phone);
	if (ptr == nullptr) { return 0; }
	inf_P(name, phone, sex, addr, age, ptr->mem_Inf);
	return 1;
}

void mem_OUT(mem_I* ptr)
{
	printf("姓名：%s\n", ptr->name);
	printf("电话：%s\n", ptr->ph_num);
	switch (ptr->sex)
	{
	case UN:
		printf("性别：未知\n");
		break;
	case MALE:
		printf("性别：男\n");
		break;
	case FEMALE:
		printf("性别：女\n");
		break;
	default:
		break;
	}
	printf("年龄：%d\n", ptr->age);
	printf("住址：%s\n", ptr->addr);
	return;
}
void print_M_N(const char* name)
{
	inf_L* ptr = find_M_N(name);
	if (ptr == nullptr) { printf("查无此人\n"); return; }
	mem_OUT(ptr->mem_Inf);
	return;
}
void print_M_P(const char* phone)
{
	inf_L* ptr = find_M_P(phone);
	if (ptr == nullptr) { printf("查无此人\n"); return; }
	mem_OUT(ptr->mem_Inf);
	return;
}


