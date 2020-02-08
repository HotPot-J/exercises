#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
问题描述
已知一个正整数N，问从1~N中任选出三个数，他们的最小公倍数最大可以为多少。

输入格式
输入一个正整数N。

输出格式
输出一个整数，表示你找到的最小公倍数。
样例输入
9
样例输出
504
数据规模与约定
1 <= N <= 106。
*/

//这是按照数学公式的实现 但是时间复杂度太大 无法通过测试 但是顺便实现了递归辗转相除求最大公约数 和求两数的最小公倍数

/*求几个自然数的最小公倍数，可以先求出其中两个数的最小公倍数，再求这个最小公倍数与第三个数的最小公倍数，
依次求下去，直到最后一个为止。最后所得的那个最小公倍数，就是所求的几个数的最小公倍数。
*/
int CommonDivisor(int a, int b){//辗转相除法求最大公约数
	if (a%b == 0){
		return b;
	}
	else{
		return CommonDivisor(b, a%b);
	}
}
int MinCommonMultiple(int a, int b){
	int max = a >= b ? a : b;
	int min = a < b ? a : b;
	if (max%min == 0){
		return max;
	}
	else{
		return max*min / CommonDivisor(max, min);//a与b的最小公倍数 = a*b / a与b的最大公约数   
	}
}
void MaxMinCommonMultiple(int n){//最大最小公倍数
	int i = 0, j = 0, tmp = 0;
	int ret = 0;
	for (i = 1; i <= n-2; i++){
		j = i + 1;
		for (j; j <= n - 1; j++){
			 tmp = MinCommonMultiple(i, j);
			 tmp = MinCommonMultiple(tmp, j + 1);
			 if (tmp > ret){
				 ret = tmp;
			 }
		}
	}
	printf("%d", ret);
}

//贪心算法实现：
/*
1.连续的数字中有两种情况 奇偶奇和偶奇偶
  ①当是奇偶奇的情况时   当n为奇数 最大的三个就是n n-1 n-2  由于n 和 n-2没有2这个因数 即使其中一个数字有因数3 由于这
  三个数字的变化范围不超过3 所以任意两个数之间不存在公约数3  
  ②当是偶奇偶的情况时   当n为偶数  如果将n-2改为n-3就又变成奇偶奇的情况了 此时是最大最小公倍数  
  但是 当n中含有因数3时 则n-3也会含有3这个因数 会导致公约数缩小三倍   这种情况需要调整为n-1 n-2 n-3就变为奇偶奇的情况
*/

//unsigned long long型输出使用 %llu   
unsigned long long MaxMinCommonMultiple1(unsigned long long n){
	if (n % 2 != 0){ //n为奇数 满足奇偶奇
		return n*(n - 1)*(n - 2);
	}
	else if (n % 3 != 0){  //n为偶数 但是不含有因数3
		return n*(n - 1)*(n - 3);
	}
	else{  //n为偶数 含有因数3
		return (n - 1)*(n - 2)*(n - 3);
	}
}
int main(){
	unsigned long long n = 0;
	scanf("%d", &n);
	printf("%llu", MaxMinCommonMultiple1(n));
	return 0;
}