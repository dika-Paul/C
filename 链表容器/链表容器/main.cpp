#include"list.h"
#include<iostream>

int main()
{
	list<int>* a = new list<int>;
	/*a->DataInsert_head(2);
	a->DataInsert_head(1);
	a->DataInsert(3, 3);
	a->DataInsert_head(0);
	a->DataInsert_tail(4);
	a->ListPrint();
	std::cout << std::endl;
	a->DataChange(4, 2);
	a->DataDel(1);
	a->ListPrint();
	std::cout << std::endl;
	a->DataDel_head();
	a->ListPrint();
	std::cout << std::endl;
	a->DataDel_tail();
	a->ListPrint();
	std::cout << std::endl;
	std::cout << a->DataFind(3) <<std::endl;
	std::cout << a->size();
	std::cout << std::endl;
	a->ListFormat();
	a->DataInsert_tail(4);
	a->ListPrint();*/
	delete a;
	return 0;
}