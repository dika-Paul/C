#include<bits/stdc++.h>

using namespace std;

class A{
	public:
		A(){
			cout << "A构造" << endl;
		}
		~A(){
			cout << "A析构" << endl;
		}
};

class B{
	public:
		B(){
			cout << "B构造" << endl;
		}
		~B(){
			cout << "B析构" << endl;
		}
	private:
		A a;
};

int main()
{
	B b;
	return 0;
}
