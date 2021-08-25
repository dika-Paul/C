#ifndef CONTACT_H
#define CONTACT_H

#define MAXN 10001
#define LENTH 151

enum SEX
{
	UN, MALE, FEMALE
};

int add_M(const char* name, const char* phone, const SEX sex, const char* addr, const int age);
int del_M_N(const char* name);
int del_M_P(const char* phone);
int change_M_N(const char* pre_Name, const char* name, const char* phone, const SEX sex, const char* addr, const int age);
int change_M_P(const char* pre_Phone, const char* name, const char* phone, const SEX sex, const char* addr, const int age);
void print_M_N(const char* name);
void print_M_P(const char* phone);

#endif // !CONTACT_H



