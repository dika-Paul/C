#ifndef _CONTACT_H
#define _CONTACT_H

#define NAME_LEN 51
#define PHONE_LEN 31
#define ADDR_LEN 51

typedef struct person_info{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	short sex;
	short age;
	char addr[ADDR_LEN];
	//个人数据类功能实现
	void per_info_read(const char* Name, const char* Phone, const short Sex, const short Age, const char* Addr);
	bool cmp_by_name(char* Name);
	bool cmp_by_phone(char* Phone);
	void per_info_out();
	void per_info_del();
}per_i;

typedef struct contact_book {
	struct contact_book* pre;
	struct contact_book* next;
	per_i* member;
}con_b;

namespace addr_data
{
	extern unsigned long long num;
	extern con_b* head;
}

per_i* build_mem();//个人数据的建立
con_b* build_node();//链表节点的建立

//链表类功能实现
void member_insert(per_i* ptr);
con_b* member_find(char* str, int num);
void member_del(con_b* ptr);
void member_print(con_b* ptr);
void member_change(con_b* ptr, per_i* info);
void member_show();
void member_clean();
#endif // !_CONTACT_H