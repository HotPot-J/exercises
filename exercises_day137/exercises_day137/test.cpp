#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

/*
1、删除公共字符
输入两个字符串包含2个字符串，从第一字符串中删除第二个字符串中所有的字符
例子:They are students 和 aeiou 则删除之后的第一个字符变成Thy r stdnts
输入：
	每个此时输入包含两个字符串
输出:
	输出删除后的字符串
*/

/*
思路：哈希
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
二、连续最大和
一个数组有N个元素，求连续子数组最大和。例如[-1,2,1]，和最大的连续子数组为[2,1]，其
和为3
输入描述:
	输入为两行。第一行一个整数n(1<=n<=100000)，表示一共有n个元素，第二行n个数，即
	每个元素，每个整数都在32为int范围内。以空格分隔。
输出描述:
	所有连续子数组中的最大值
*/
/*
思路：动态规划
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


