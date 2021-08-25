#include<iostream>
#include<cstdio>
#define For(i, a, b) for(int i = (a); i < (b); i++)

using namespace std;

int all_num;
void Sort(int num[], int lenth);
void reput(int num[], int lenth, int mid);

int main(){
	int num[100];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	Sort(num, n);
	for(int i = 0;i < n;i++){
		cout << num[i] << " ";
	}
	cout << all_num;
	return 0;
}

void Sort(int num[], int lenth){
	if(lenth == 1)return;
	int len = lenth / 2;
	Sort(num, len);
	if(lenth % 2 == 1){
		Sort(num+len, len+1);
	}
	else{
		Sort(num+len, len);
	}
	reput(num, lenth, len);
	return;
}
void reput(int num[], int lenth, int len){
	int L[len], R[lenth-len];
	For(i, 0, len){
		L[i] = num[i];
	}
	For(i, 0, lenth-len){
		R[i] = num[len+i];
	}
	int flagl = 0;
	int flagr = 0;
	int logo = 0;
	while(flagl != len && flagr != lenth-len){
		if(L[flagl] <= R[flagr]){
			num[logo] = L[flagl];
			flagl++;
		}
		else{
			num[logo] = R[flagr];
			flagr++;
			all_num += len-flagl;
		}
		logo++;
	}
	if(flagl != len){
		for(int i = logo; i < lenth; i++){
			num[i] = L[flagl];
			flagl++;
		}
	}
	else{
		for(int i = logo; i < lenth; i++){
			num[i] = R[flagr];
			flagr++;
		}
	}
	return;
}
