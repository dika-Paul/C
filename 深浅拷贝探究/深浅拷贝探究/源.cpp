/*
* ������ǳ������̽��
* ǳ�������Զ����ֵ���и��ƣ�������ֵ��ָ�붼���и��ƣ����ܵ���������ʱ�ظ��ͷ�ͬһƬ�ռ�
* ���������������ݽ��и��ƣ�ֵ���ƣ�����ָ�룬����������ռ临��ָ��ָ������ݣ���ֹ�ظ��ͷŵķ���
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
	cout << "Ĭ�Ϲ���" << endl;
}

Temp::~Temp()
{
	if (_DATA != nullptr)
	{
		delete _DATA;
	}
	_DATA = nullptr;
	cout << "Ĭ������" << endl;
}

Temp::Temp(const int _data)
{
	_DATA = new int(_data);
}

Temp::Temp(const Temp& T)//���
{
	_DATA = new int(*T._DATA);
}

//Temp::Temp(const Temp& T)//ǳ����
//{
//	_DATA = T._DATA;
//}

void test()//ǳ��������
{
	Temp temp(10);
	Temp temp2(temp);//�ڴ˴�ʹ��ǳ������ֱ�ӻ�ȡtemp�е�_DATA��ַ������������ʱ�ظ��ͷ�ͬһƬ�ڴ�ռ�
}

int main()
{
	test();
	return 0;
}