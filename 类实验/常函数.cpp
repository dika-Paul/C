#include<bits/stdc++.h>

using namespace std;

class Temp{
	public:
		Temp():
			a(1),
			b(2)
			{
			}
		//������ 
		void func()
		{
		} 
		void print() const//��const�ȼ��ڽ�ԭ����this��Temp* const this ��Ϊ const Temp* const this 
		{
//			b = 10;
			cout << a << endl;
			a = 10;
			cout << "�ú���Ϊ�������������޸ĳ�Ա����" << endl; 
			cout << a << endl;
		}
	private:
		int b;  
		mutable int a;//ʹ��mutable���εı��������ڳ��������������и���ֵ 
};

int main()
{
	const Temp B;//�������ܵ��ó�����������ĳ�Ա���� 
//	B.func();
	Temp A;
	A.print();
	return 0;
}
