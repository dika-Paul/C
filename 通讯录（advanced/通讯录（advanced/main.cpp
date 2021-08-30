#include<iostream>
#include"operate.h"
#include"contact_book.h"

using namespace addr_data;

using std::cin;
using std::cout;

void menu()
{
	cout << "**********************\n";
	cout << "*****1.������ϵ��*****\n";
	cout << "*****2.������ϵ��*****\n";
	cout << "*****3.չʾͨѶ¼*****\n";
	cout << "*****4.�޸���ϵ��*****\n";
	cout << "*****5.ɾ����ϵ��*****\n";
	cout << "****6.��ʽ��ͨѶ¼****\n";
	cout << "********7.�˳�********\n";
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
			cout << "��лʹ��";
			data_export();
			return 0;
		default:
			cout << "������Ч";
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}