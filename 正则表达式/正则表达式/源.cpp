#include<iostream>
#include<string>
#include<regex>
using namespace std;
int main()
{
	string str = "adsfaxsdfasɳ���ϰ����ط�";
	regex signal("[(a-z)(A-Z)]+");
	smatch result;
	regex_search(str, result, signal);
	cout << result.str();
	
	return 0;
}