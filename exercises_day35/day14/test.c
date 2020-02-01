#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
问题描述
　　FJ在沙盘上写了这样一些字符串：
  　　A1 = “A”
	　　A2 = “ABA”
	  　　A3 = “ABACABA”
		　　A4 = “ABACABADABACABA”
		  　　… …
			　　你能找出其中的规律并写所有的数列AN吗？
			  输入格式
			  　　仅有一个数：N ≤ 26。
				输出格式
				　　请输出相应的字符串AN，以一个换行符结束。输出中不得含有多余的空格或换行、回车符。
				  样例输入
				  3
				  样例输出
				  ABACABA
*/
void FJ(int k){
  //规律就是 每次再本行字符的 前面和后面打上 上一次的字符
		if (!k){
			;
		}
		else{
			FJ(k - 1);
			printf("%c", 'A' + k - 1);
			FJ(k - 1);
		}

}
int main(){
	int k = 0;
	scanf("%d", &k);
	FJ(k);
	return 0;
}