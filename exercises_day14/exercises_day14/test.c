#define _CRT_SECURE_NO_WARNINGS 1
// 一 、
//问题描述
//求1 + 2 + 3 + ... + n的值。
//输入格式
//输入包括一个整数n。
//输出格式
//输出一行，包括一个整数，表示1 + 2 + 3 + ... + n的值。
//样例输入
//4
//样例输出
//10
//样例输入
//100
//说明：有一些试题会给出多组样例输入输出以帮助你更好的做题。
//
//一般在提交之前所有这些样例都需要测试通过才行，但这不代表这几组样例
//数据都正确了你的程序就是完全正确的，潜在的错误可能仍然导致你的得分较低。
//
//样例输出
//5050
//数据规模与约定
//1 <= n <= 1, 000, 000, 000。
//#include<stdio.h>
////long long 位64字节
//int main(){
//	long long n = 0;
//	long long ret = 0;
//	scanf("%d", &n);
//	if (n >= 1 && n <= 1000000000){
//		ret = (n*(1 + n)) / 2;  //等差数列求和公式  sn  =  n(a1+an)/2
//		printf("%I64d", ret);
//	}
//
//	return 0;
//}

//测试一下各个数据类型的取值范围 
//#include <stdio.h> 
//int main(){
//	printf("%d", sizeof(int)); // 4字节  32位
//	printf("%d", sizeof(float)); // 4字节
//	printf("%d", sizeof(double)); // 8字节 64位
//	printf("%d", sizeof(long long));//8字节  输出格式：%I64d
//	printf("%d", sizeof(long));//4字节
//}

//二 、
/*
问题描述
　　给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
  输入格式
  　　第一行为一个整数n。
	　　第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
	  输出格式
	  　　输出一行，按从小到大的顺序输出排序后的数列。
		样例输入
		5
		8 3 6 4 9
		样例输出
		3 4 6 8 9
*/
#include<stdio.h>
#include<stdlib.h>
void fun(int* arr, int len){
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i<len; i++){
		for (j = i + 1; j<len; j++){
			if (arr[j]<arr[i]){
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	return arr;
}
int main(){
	int n = 0;
	int i = 0;
	int *arr = NULL;
	scanf("%d", &n);
	arr = (int*)malloc(n*sizeof(int));
	for (i = 0; i<n; i++){
		scanf("%d", arr + i);
	}
	fun(arr, n);
	for (i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}