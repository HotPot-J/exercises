#define _CRT_SECURE_NO_WARNINGS 1
// һ ��
//��������
//��1 + 2 + 3 + ... + n��ֵ��
//�����ʽ
//�������һ������n��
//�����ʽ
//���һ�У�����һ����������ʾ1 + 2 + 3 + ... + n��ֵ��
//��������
//4
//�������
//10
//��������
//100
//˵������һЩ������������������������԰�������õ����⡣
//
//һ�����ύ֮ǰ������Щ��������Ҫ����ͨ�����У����ⲻ�����⼸������
//���ݶ���ȷ����ĳ��������ȫ��ȷ�ģ�Ǳ�ڵĴ��������Ȼ������ĵ÷ֽϵ͡�
//
//�������
//5050
//���ݹ�ģ��Լ��
//1 <= n <= 1, 000, 000, 000��
//#include<stdio.h>
////long long λ64�ֽ�
//int main(){
//	long long n = 0;
//	long long ret = 0;
//	scanf("%d", &n);
//	if (n >= 1 && n <= 1000000000){
//		ret = (n*(1 + n)) / 2;  //�Ȳ�������͹�ʽ  sn  =  n(a1+an)/2
//		printf("%I64d", ret);
//	}
//
//	return 0;
//}

//����һ�¸����������͵�ȡֵ��Χ 
//#include <stdio.h> 
//int main(){
//	printf("%d", sizeof(int)); // 4�ֽ�  32λ
//	printf("%d", sizeof(float)); // 4�ֽ�
//	printf("%d", sizeof(double)); // 8�ֽ� 64λ
//	printf("%d", sizeof(long long));//8�ֽ�  �����ʽ��%I64d
//	printf("%d", sizeof(long));//4�ֽ�
//}

//�� ��
/*
��������
��������һ������Ϊn�����У���������а���С�����˳�����С�1<=n<=200
  �����ʽ
  ������һ��Ϊһ������n��
	�����ڶ��а���n��������Ϊ�����������ÿ�������ľ���ֵС��10000��
	  �����ʽ
	  �������һ�У�����С�����˳��������������С�
		��������
		5
		8 3 6 4 9
		�������
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