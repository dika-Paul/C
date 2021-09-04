#define _CRT_SECURE_NO_WARNINGS

#include"operate.h"
#include"contact_book.h"
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<iostream>

using namespace std;
using addr_data::head;
using addr_data::num;

bool data_import()
{
    FILE* data_in = fopen("contactBook.bin", "rb");
    assert(data_in != nullptr);
    head = build_node();
    con_b* ptr = head;
    con_b* point = ptr;
    per_i* per_info = build_mem();
    while (fread(per_info, sizeof(per_i), 1, data_in))
    {
        ptr->pre = point;
        ptr->member = per_info;
        num++;
        point = ptr;
        ptr = ptr->next;
        ptr = build_node();
        point->next = ptr;
        per_info = build_mem();
    }
    free(per_info);
    free(ptr);
    point->next = nullptr;
    return true;
}
bool data_export()
{
    FILE* data_out = fopen("contactBook.bin", "wb");
    con_b* ptr = head;
    if (ptr == nullptr) { return false; }
    while (ptr != nullptr)
    {
        fwrite(ptr->member, sizeof(per_i), 1, data_out);
        ptr = ptr->next;     
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
    cout << "姓名\n";
    cin >> name;
    cout << "电话\n";
    cin >> phone;
    cout << "性别（男为1，女为2）\n";
    cin >> sex;
    cout << "年龄\n";
    cin >> age;
    cout << "住址\n";
    cin >> addr;
    per_i* info = build_mem();
    info->per_info_read(name, phone, sex, age, addr);
    member_insert(info);
    cout << "插入成功\n";
}
void FindContactMember()
{
    cout << "通过姓名查找选0，通过电话查找选1\n";
    int flag;
    cin >> flag;
    cout << "请输入查找信息\n";
    char str[400];
    cin >> str;
    con_b* ptr = member_find(str, flag);
    if (ptr == nullptr) { cout << "查无此人\n"; return; }
    member_print(ptr);
}
void ChangeContaceMember()
{
    cout << "通过姓名查找选0，通过电话查找选1\n";
    int flag;
    cin >> flag;
    cout << "请输入查找信息\n";
    char str[400];
    cin >> str;
    con_b* ptr = member_find(str, flag);
    if (ptr == nullptr) { cout << "查无此人\n"; return; }
    cout << "请输入要修改的信息\n";
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    short sex;
    short age;
    char addr[ADDR_LEN];
    cout << "姓名\n";
    cin >> name;
    cout << "电话\n";
    cin >> phone;
    cout << "性别（男为1，女为2）\n";
    cin >> sex;
    cout << "年龄\n";
    cin >> age;
    cout << "住址\n";
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
    cout << "通过姓名查找选0，通过电话查找选1\n";
    int flag;
    cin >> flag;
    cout << "请输入查找信息\n";
    char str[400];
    cin >> str;
    con_b* ptr = member_find(str, flag);
    if (ptr == nullptr) { cout << "查无此人\n"; return; }
    cout << "你确定要删除吗？Y/N...";
    char key;
    cin >> key;
    if (key == 'N') { return; }
    else
    {
        member_del(ptr);
        cout << "删除成功\n";
    }
}
void FormatContactMember()
{
    cout << "你确定要格式化通讯录吗？Y/N...\n";
    char key;
    cin >> key;
    if (key == 'N') { return; }
    else
    {
        member_clean();
        cout << "格式化成功\n";
    }
}
