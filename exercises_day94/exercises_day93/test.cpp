#define _CRT_SECURE_NO_WARNINGS 1

/*
�����������ַ������򷽷�:
	1.�����ֵ���������:
		car<carriage<cats<doggies<koala
	2.�����ַ����ĳ�������:
		car<cats<koala<doggies<carriage
������֪���Լ���Щ�ַ�������˳���Ƿ��������������򷽷��������æ��
����������
	�����һ��Ϊ�ַ�������n(n<=100)
	��������n�У�ÿ��һ���ַ������ַ�������С��100������Сд��ĸ���
�������:
	�����Щ�ַ����Ǹ����ֵ���������ǳ������:
		lexicographically
	���ݳ��ȶ������ֵ�:
		lengths
	���߱�:
		both 
	�����߱���
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
				//���� ���������Ա�
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
������������С������
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