#define _CRT_SECURE_NO_WARNINGS 1

/*
1、剪花布条（牛客）
一块花布条，里面有些图案另有一块直接可用的小布条，里面也有一些图案。对于给定的花布条
和小饰条，计算一下能从画布条中尽可能剪出几块小饰条来？
*/

/*
 思路：找子串  用指针遍历匹配即可
*/

#include<iostream>
#include<string>
using namespace std;

//int main(){
//	string str;
//	string tmp;
//	while (cin >> str >> tmp){
//		int len1 = str.size();
//		int len2 = tmp.size();
//		int j = 0, res = 0;
//		for (int i = 0; i < len1; ++i){
//			int k = i;
//			for (j = 0; j < len2; ++j){
//				if (k < len1&&str[k] == tmp[j]){
//					++k;
//				}
//				else{
//					break;
//				}
//			}
//			if (j == len2){
//				++res;
//				i = k-1;
//			}
//		}
//		cout << res << endl;
//	}
//	return 0;
//}

/*
2、客似云来（牛客）
*/

/*
思路: 又是斐波那契数...
*/

#include<iostream>
using namespace std;
int main(){
	//根据题目范围 先打表 
	long long arr[81] = { 0 };
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i < 81; ++i){
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	int from = 0, to = 0;
	while (cin >> from >> to){
		long long res = 0;
		for (int i = from; i <= to; ++i){
			res += arr[i];
		}
		cout << res << endl;
	}
	return 0;
}