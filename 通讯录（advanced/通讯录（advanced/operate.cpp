#define _CRT_SECURE_NO_WARNINGS

#include"operate.h"
#include"contact_book.h"
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<iostream>

using namespace std;
using addr_data::head;

bool data_import()
{
    FILE* data_in = fopen("contactBook.bin", "rb");
    assert(data_in != nullptr);
    head = build_node();
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    short sex;
    short age;
    char addr[ADDR_LEN];
    con_b* ptr = head;
    while (fscanf(data_in, "%s %s %hd %hd %s", name, phone, &sex, &age, addr) != EOF)
    {
        ptr->next = build_node();
        assert(ptr->next != nullptr);
        ptr = ptr->next;
        ptr->member = build_mem();
        ptr->member->per_info_read(name, phone, sex, age, addr);
    }
    ptr = nullptr;
    return true;
}
bool data_export()
{
    FILE* data_out = fopen("contactBook.bin", "wb");
    con_b* ptr = head;
    if (ptr == nullptr) { return false; }
    per_i* info;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
        info = ptr->member;
        fprintf(data_out, "%s %s %hd %hd %s\n", info->name, info->phone, info->sex, info->age, info->addr);
    }
    return true;
}

void AddContactMember()
{
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    short sex;
    short age;
    char addr[ADDR_LEN];
    cout << "����\n";
    cin >> name;
    cout << "�绰\n";
    cin >> phone;
    cout << "�Ա���Ϊ1��ŮΪ2��\n";
    cin >> sex;
    cout << "����\n";
    cin >> age;
    cout << "סַ\n";
    cin >> addr;
    per_i* info = build_mem();
    info->per_info_read(name, phone, sex, age, addr);
    member_insert(info);
    cout << "����ɹ�\n";
}
void FindContactMember()
{
    cout << "ͨ����������ѡ0��ͨ���绰����ѡ1\n";
    int flag;
    cin >> flag;
    cout << "�����������Ϣ\n";
    char str[400];
    cin >> str;
    con_b* ptr = member_find(str, flag);
    if (ptr == nullptr) { cout << "���޴���\n"; return; }
    member_print(ptr);
}
void ChangeContaceMember()
{
    cout << "ͨ����������ѡ0��ͨ���绰����ѡ1\n";
    int flag;
    cin >> flag;
    cout << "�����������Ϣ\n";
    char str[400];
    cin >> str;
    con_b* ptr = member_find(str, flag);
    if (ptr == nullptr) { cout << "���޴���\n"; return; }
    cout << "������Ҫ�޸ĵ���Ϣ\n";
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    short sex;
    short age;
    char addr[ADDR_LEN];
    cout << "����\n";
    cin >> name;
    cout << "�绰\n";
    cin >> phone;
    cout << "�Ա���Ϊ1��ŮΪ2��\n";
    cin >> sex;
    cout << "����\n";
    cin >> age;
    cout << "סַ\n";
    cin >> addr;
    per_i* info = build_mem();
    info->per_info_read(name, phone, sex, age, addr);
    member_change(ptr, info);
}
void ShowContactMember()
{
    member_show();
}
void DelContactMember()
{
    cout << "ͨ����������ѡ0��ͨ���绰����ѡ1\n";
    int flag;
    cin >> flag;
    cout << "�����������Ϣ\n";
    char str[400];
    cin >> str;
    con_b* ptr = member_find(str, flag);
    if (ptr == nullptr) { cout << "���޴���\n"; return; }
    cout << "��ȷ��Ҫɾ����Y/N...";
    char key;
    cin >> key;
    if (key == 'N') { return; }
    else
    {
        member_del(ptr);
        cout << "ɾ���ɹ�\n";
    }
}
void FormatContactMember()
{
    cout << "��ȷ��Ҫ��ʽ��ͨѶ¼��Y/N...\n";
    char key;
    cin >> key;
    if (key == 'N') { return; }
    else
    {
        member_clean();
        cout << "��ʽ���ɹ�\n";
    }
}
