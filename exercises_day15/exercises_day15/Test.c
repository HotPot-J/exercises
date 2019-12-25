#define _CRT_SECURE_NO_WARNINGS 1
/*
问题描述
　　给定一个以秒为单位的时间t，要求用“<H>:<M>:<S>”的格式来表示这个时间。<H>表示时间，<M>表示分钟，而<S>表示秒，它们都是整数且没有前导的“0”。例如，若t=0，则应输出是“0:0:0”；若t=3661，则输出“1:1:1”。
  输入格式
  　　输入只有一行，是一个整数t（0<=t<=86399）。
	输出格式
	　　输出只有一行，是以“<H>:<M>:<S>”的格式所表示的时间，不包括引号。
	  样例输入
	  0
	  样例输出
	  0:0:0
	  样例输入
	  5436
	  样例输出
	  1:30:36
*/
#include<stdio.h>
int fun(int tmp){
	int flag= 0;
	while (tmp){
		flag++;
		tmp = tmp / 10;
	}
	return flag;
}

 int main(){
	 int n = 0;
	 int tmp = 0;
	 int tmp1 = 0;
	 int tmp2 = 0; //记录小时
	 int tmp3 = 0; //记录分钟
	 int r = 0;
	 int i = 0;
	 int size1 = 0;
	 int size2 = 0;
	 int size3 = 0;
	 char arr[100] = { '0' };
	 scanf("%d", &n); 
	 if (n == 0){
		 arr[0] = '0';
		 arr[1] = ':';
		 arr[2] = '0';
		 arr[3] = ':';
		 arr[4] = '0';
		 for (i = 0; i < 5; i++){
			 printf("%c", arr[i]);
		 }
		 printf("\n");
	 }
	 else{
		 tmp = n / 3600;
		 tmp2 = tmp;
		 size1 = fun(tmp);
		 r = size1 - 1;
		 for (i = 0; i < size1; i++){
			 arr[r--] = tmp % 10 + '0';
			 tmp = tmp / 10;
		 }//111222
		 arr[size1] = ':';  

		 tmp = (n- size1*3600)/60;
		 tmp3 = tmp;
		 size2 = fun(tmp);
		 r = size1+size2;
		 for (i = 0; i < size2 ; i++){
			 arr[r--] = (tmp % 10)+'0';
			 tmp = tmp / 10;
		 }
		 arr[size1+size2+1] = ':';

		 tmp = n - tmp2* 3600-tmp3*60;
		 size3 = fun(tmp);
		 r = size1 + size2 +size3+1 ;
		 for (i = 0; i < size3; i++){
			 arr[r--] = tmp % 10 + '0';
			 tmp = tmp / 10;
		 }
		 for (i = 0; i < (size1+size2+size3+2); i++){
			 printf("%c", arr[i]);
		 }
	 }
     return 0;
	
}
