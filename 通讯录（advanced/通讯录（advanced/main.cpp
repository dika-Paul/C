#include<iostream>
#include"operate.h"
#include"contact_book.h"

using namespace addr_data;

using std::cin;
using std::cout;

void menu()
{
	cout << "**********************\n";
	cout << "*****1.插入联系人*****\n";
	cout << "*****2.查找联系人*****\n";
	cout << "*****3.展示通讯录*****\n";
	cout << "*****4.修改联系人*****\n";
	cout << "*****5.删除联系人*****\n";
	cout << "****6.格式化通讯录****\n";
	cout << "********7.退出********\n";
	cout << "**********************\n";
}

int main()
{
	int key;
	data_import();
	while (1)
	{
		menu();
		cin >> key;
		switch (key)
		{
		case 1:
			AddContactMember();
			break;
		case 2:
			FindContactMember();
			break;
		case 3:
			ShowContactMember();
			break;
		case 4:
			ChangeContaceMember();
			break;
		case 5:
			DelContactMember();
			break;
		case 6:
			FormatContactMember();
			break;
		case 7:
			cout << "感谢使用";
			data_export();
			return 0;
		default:
			cout << "输入无效";
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}