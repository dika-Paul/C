/*
* 关于深浅拷贝的探究
* 浅拷贝：对对象的值进行复制，无论是值或指针都进行复制，可能导致在析构时重复释放同一片空间
* 深拷贝：将对象的内容进行复制，值复制，若是指针，则重新申请空间复制指针指向的内容，防止重复释放的发生
*/
#include<iostream>

using namespace std;

class Temp
{
public:
	Temp();
	~Temp();
	Temp(const int _data);
	Temp(const Temp& T); 

	int* _DATA;

};

Temp::Temp()
{
	cout << "默认构造" << endl;
}

Temp::~Temp()
{
	if (_DATA != nullptr)
	{
		delete _DATA;
	}
	_DATA = nullptr;
	cout << "默认析构" << endl;
}

Temp::Temp(const int _data)
{
	_DATA = new int(_data);
}

Temp::Temp(const Temp& T)//深拷贝
{
	_DATA = new int(*T._DATA);
}

//Temp::Temp(const Temp& T)//浅拷贝
//{
//	_DATA = T._DATA;
//}

void test()//浅拷贝尝试
{
	Temp temp(10);
	Temp temp2(temp);//在此处使用浅拷贝，直接获取temp中的_DATA地址，导致在析构时重复释放同一片内存空间
}

int main()
{
	test();
	return 0;
}