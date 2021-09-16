#include<bits/stdc++.h>

using namespace std;

class Temp{
	public:
		Temp():
			a(1),
			b(2)
			{
			}
		//常函数 
		void func()
		{
		} 
		void print() const//此const等价于将原本的this：Temp* const this 变为 const Temp* const this 
		{
//			b = 10;
			cout << a << endl;
			a = 10;
			cout << "该函数为常函数，不可修改成员变量" << endl; 
			cout << a << endl;
		}
	private:
		int b;  
		mutable int a;//使用mutable修饰的变量可以在常函数，常对象中更改值 
};

int main()
{
	const Temp B;//常对象不能调用除常函数以外的成员函数 
//	B.func();
	Temp A;
	A.print();
	return 0;
}
