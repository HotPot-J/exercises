#define _CRT_SECURE_NO_WARNINGS 1

/*
1、字符集合
输入一个字符串，求出该字符串包含的字符串集合

输入描述：每组数据输入一个字符串，字符串长度最大为100，且只包含字母，不可能为空串，区分大小写

输出描述：每组数据一行，按照字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母
不输出。

例子: 
 输入:abcqweracb
 输出:abcqwer
*/

/*
思路:哈希
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
//int main(){
//	string str;
//	unordered_map<char, bool> m;
//	while (getline(cin, str)){
//		for (auto a : str){
//			m[a] = true;
//		}
//		for (auto b : str){
//			if (m[b]){
//				cout << b;
//				m[b] = false;
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}

/*
2、元素查找
有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的位移
例如，原数组1，2，3，4，5，6 向左位移五个位置变为6，1，2，3，4，5 
现在对于移位后的数组，需要查找某个位置的元素，请设计一个复杂度为log级别的算法完成该任务
给定一个int数组A，为位移后的数组，同时给定数组大小n和需要查找元素的值x，请返回x的位置
（位置从0开始）。保证数组种元素互异
例： 【6 1 2 3 4 5】，6，6
*/

/*
思路:二分查找
*/

//递归版本 超出时间限制
class Finder {
public:
	int fun(vector<int> a, int i, int j,int x){
		int mid = (j - i) / 2;
		if (a[mid] == x){
			return mid;
		}
		if (a[mid] < x){
			if (a[mid]<a[i] && x>a[j]){
				//右边有序 但是x>a[j] 则x该区间在左边
				return fun(a, i, mid-1, x);
			}
			else{
				//向左边找
				return fun(a, mid+1, j, x);
			}
		}
		else{
			if (a[mid] > a[i] && x < a[i]){
				//左边有序，但x<a[i] 则x在右区间
				return fun(a, mid + 1, j, x);
			}
			else{
				return fun(a, i, mid - 1, x);
			}
		}
		return -1;
	}
	int findElement(vector<int> A, int n, int x) {
		return fun(A, 0, n - 1, x);
	}
};

//迭代版本 通过
class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		int i = 0, j = n - 1, mid;
		while (i <= j) {
			mid = (i + j) / 2;
			if (A[mid] == x)
				return mid;
			if (A[mid]<x) {
				if (A[mid]<A[i] && x>A[j]) {
					j = mid - 1;
				}
				else{
					i = mid + 1;
				}
			}
			else {
				if (A[mid]>A[i] && x<A[i]){
					i = mid + 1;
				}
				else{
					j = mid - 1;
				}
			}
		}
		return -1;
	}
};
int main(){
	vector<int> A = { 6, 1, 2, 3, 4, 5 };
	Finder a;
	a.findElement(A, 6, 6);
	return 0;
}