#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

/*
1��ɾ�������ַ�
���������ַ�������2���ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ�
����:They are students �� aeiou ��ɾ��֮��ĵ�һ���ַ����Thy r stdnts
���룺
	ÿ����ʱ������������ַ���
���:
	���ɾ������ַ���
*/

/*
˼·����ϣ
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
//int main(){
//	string a;
//	string b;
//	while (getline(cin,a)){
//		cin >> b;
//		int aSize = a.size();
//		unordered_map<char, bool> map;
//		for (auto e : b){
//			map[e] = true;
//		}
//		string::iterator p = a.begin();
//		while (p != a.end()){
//			if (map[*p]){
//				p = a.erase(p);
//			}
//			else{
//				++p;
//			}
//		}
//		cout << a << endl;
//	}
//	return 0;
//}

/*
������������
һ��������N��Ԫ�أ����������������͡�����[-1,2,1]������������������Ϊ[2,1]����
��Ϊ3
��������:
	����Ϊ���С���һ��һ������n(1<=n<=100000)����ʾһ����n��Ԫ�أ��ڶ���n��������
	ÿ��Ԫ�أ�ÿ����������32Ϊint��Χ�ڡ��Կո�ָ���
�������:
	���������������е����ֵ
*/
/*
˼·����̬�滮
*/
//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//int main(){
//	int n = 0;
//	while (cin>>n){
//		vector<int> arr;
//		for (int i = 0; i < n; ++i){
//			int tmp = 0;
//			cin >> tmp;
//			arr.push_back(tmp);
//		}
//		int add = 0;
//		int max = INT_MIN;
//		for (int i = 0; i < n; ++i){
//			add = arr[i];
//			for (int j = i + 1; j < n; ++j){
//				if (add + arr[j]>0||add+arr[j]>add){
//					add += arr[j];
//				}
//
//				else{
//					break;
//				}
//				if (add>max){
//					max = add;
//				}
//			}
//			if (add>max){
//				max = add;
//			}
//		}
//		cout << max << endl;
//	}
//	return 0;
//}


