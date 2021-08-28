#define MAXN 10001
#define LENTH 151

enum SEX
{
	UN, MALE, FEMALE
};

#ifndef CONTACT_H
#define CONTACT_H
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
#endif

int add_M(const char* name, const char* phone, const SEX sex, const char* addr, const int age);
int del_M_N(const char* name);
int del_M_P(const char* phone);
int change_M_N(const char* pre_Name, const char* name, const char* phone, const SEX sex, const char* addr, const int age);
int change_M_P(const char* pre_Phone, const char* name, const char* phone, const SEX sex, const char* addr, const int age);
void print_M_N(const char* name);
void print_M_P(const char* phone);

 // !CONTACT_H



