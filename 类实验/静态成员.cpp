#include<bits/stdc++.h>

using namespace std;

class Temp{
	public:
		static void print(){
			_num++;
			cout << _num << endl;
			、、_num_a = 10;//静态成员函数无法调用非静态成员变量，无法区分是哪个对象的成员变量 
			cout << "静态成员函数调用" << endl;
		}
	private:	
		static int _num; 
		int _num_a;
};

int Temp::_num = 0;//静态成员要在类外初始化 

int main()
{
	Temp A;
	A.print();
	Temp::print();//静态成员函数可以不通过对象直接调用； 
	return 0;
}
