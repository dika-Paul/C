#include<bits/stdc++.h>

using namespace std;

class Temp{
	public:
		static void print(){
			_num++;
			cout << _num << endl;
			����_num_a = 10;//��̬��Ա�����޷����÷Ǿ�̬��Ա�������޷��������ĸ�����ĳ�Ա���� 
			cout << "��̬��Ա��������" << endl;
		}
	private:	
		static int _num; 
		int _num_a;
};

int Temp::_num = 0;//��̬��ԱҪ�������ʼ�� 

int main()
{
	Temp A;
	A.print();
	Temp::print();//��̬��Ա�������Բ�ͨ������ֱ�ӵ��ã� 
	return 0;
}
