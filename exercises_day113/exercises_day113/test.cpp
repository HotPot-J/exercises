#define _CRT_SECURE_NO_WARNINGS 1

/*
1、牛客 树根
*/

/*
思路：递归
*/

#include<iostream>
#include<string>
using namespace std;

string func(string& n){
	if (n.size()==1){
		return n;
	}
	long long tmp = 0;
	int i = n.size();
	while (i){
		tmp += (n[i-1]-'0');
		--i;
	}
	n.clear();
	n = to_string(tmp);
	return func(n);
}

int main(){
	string n;
	while (cin >> n){
		cout << func(n) << endl;
	}
	return 0;
}