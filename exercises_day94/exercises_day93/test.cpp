#define _CRT_SECURE_NO_WARNINGS 1

/*
考拉有两种字符串排序方法:
	1.根据字典序列排序:
		car<carriage<cats<doggies<koala
	2.根据字符串的长度排序:
		car<cats<koala<doggies<carriage
考拉想知道自己这些字符串排列顺序是否满足这两种排序方法，请你帮忙。
输入描述：
	输入第一行为字符串个数n(n<=100)
	接下来的n行，每行一个字符串，字符串长度小于100，均由小写字母组成
输出描述:
	如果这些字符串是根据字典排序而不是长度输出:
		lexicographically
	根据长度而不是字典:
		lengths
	都具备:
		both 
	都不具备：
		none
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<string> str;
bool dictionary(){
	if (str.size() <= 1){
		return true;
	}
	for (int i = 0; i < str.size()-1; ++i){
		char* p1 = (char*)str[i].c_str();
		char* p2 = (char*)str[i + 1].c_str();
		while (*p1&&*p2)
		{
			if (*p1 == *p2){
				++p1;
				++p2;
			}
			else if(*p1<*p2){
				//满足 换下两个对比
				break;
			}
			else{
				return false;
			}
		}
		if (*p1&&!*p2){
			return false;
		}
	}
	return true;
}

bool length(){
	if (str.size() <= 1){
		return true;
	}
	for (int i = 0; i < str.size() - 1; ++i){
		if (str[i].size()>str[i + 1].size()){
			return false;
		}
	}
	return true;
}
int main(){
	int n = 0;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i){
		cin>>s;
		str.push_back(s);
	}
	bool a = dictionary();
	bool b = length();
	if (a&&b){
		cout << "both" << endl;
	}
	else if (a&&!b){
		cout << "lexicographically" << endl;
	}
	else if (!a&&b){
		cout << "lengths" << endl;
	}
	else{
		cout << "none" << endl;
	}
	return 0;
}

/*
求两个数的最小公倍数
*/

#include<stdio.h>
int main()
{
	int a, b, i, t;
	scanf("%d %d", &a, &b);
	if (a<b)
	{
		t = a;
		a = b;
		b = t;
	}
	for (i = a; i <= a*b; i += a)

	if (i%b == 0)
		break;

	printf("%d\n", i);
	return 0;
}