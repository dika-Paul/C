#include<iostream>
#include<string>
#include<regex>
using namespace std;
int main()
{
	string str = "adsfaxsdfas沙发上案发地方";
	regex signal("[(a-z)(A-Z)]+");
	smatch result;
	regex_search(str, result, signal);
	cout << result.str();
	
	return 0;
}