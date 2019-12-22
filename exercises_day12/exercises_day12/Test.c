#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//问题描述
//Fibonacci数列的递推公式为：Fn = Fn - 1 + Fn - 2，其中F1 = F2 = 1。
//
//当n比较大时，Fn也非常大，现在我们想知道，Fn除以10007的余数是多少。
//
//输入格式
//输入包含一个整数n。
//输出格式
//输出一行，包含一个整数，表示Fn除以10007的余数。
//说明：在本题中，答案是要求Fn除以10007的余数，因此我们只要能算出这个余数即可，而不需要先计算出Fn的准确值，再将计算的结果除以10007取余数，直接计算余数往往比先算出原数再取余简单。
//
//样例输入
//10
//样例输出
//55
//样例输入
//22
//样例输出
//7704
//数据规模与约定
//1 <= n <= 1, 000, 000。
int main(){
	int ret = 0;
	int n = 0;
	int i = 0;
	int *Fibonacci = NULL;
	scanf("%d", &n);
	Fibonacci = (int *)malloc(n*sizeof(int));
	Fibonacci[0] = 1;
	if (n > 1){
		Fibonacci[1] = 1;
		for (i = 2; i < n; i++){
			Fibonacci[i] = (Fibonacci[i - 1] + Fibonacci[i - 2]) % 10007;//当斐波那契数小于10007时对代码中的斐波那契数没影响
		}                                                      //当其n阶斐波那契数大于10007时 F[n] = n*10007+余数部分 
	}                                                          //所以F[n]%10007 = 余数部分%10007 所以此时只用在数组中保存余数即可
	printf("%d", Fibonacci[n - 1]);
	free(Fibonacci);
	Fibonacci = NULL;
	return 0;
}
