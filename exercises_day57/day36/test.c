#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
̩����������?Tn?�������£�?

T0 = 0, T1 = 1, T2 = 1, ���� n >= 0?�������� Tn+3 = Tn + Tn+1 + Tn+2

��������?n���뷵�ص� n ��̩��������?Tn ��ֵ��

?

 ʾ�� 1��

 ���룺n = 4
 �����4
 ���ͣ�
 T_3 = 0 + 1 + 1 = 2
 T_4 = 1 + 1 + 2 = 4

 ��Դ�����ۣ�LeetCode��
 ���ӣ�https://leetcode-cn.com/problems/n-th-tribonacci-number
 ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
/*
1.��̬�滮 ÿ�α���ôν�� ����ݹ鵽n-1 ��dp[n-1]֮ǰ�Ѿ������� ֱ���ü��ɱ����ظ�����
*/
int res;
int dp[38] = { 0 };
int tribonacci(int n){
	if (dp[n] != 0){
		return dp[n];
	}
	if (n == 0){
		return 0;
	}
	else if (n == 1 || n == 2){
		return 1;
	}
	else{
		res = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
		dp[n] = res;
		return res;
	}
}
int main(){
	tribonacci(4);
	return 0;
}