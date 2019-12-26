#define _CRT_SECURE_NO_WARNINGS 1
/*
问题描述
　　求出区间[a,b]中所有整数的质因数分解。
  输入格式
  　　输入两个整数a，b。
	输出格式
	　　每行输出一个数的分解，形如k=a1*a2*a3...(a1<=a2<=a3...，k也是从小到大的)(具体可看样例)
	  样例输入
	  3 10
	  样例输出
	  3=3
	  4=2*2
	  5=5
	  6=2*3
	  7=7
	  8=2*2*2
	  9=3*3
	  10=2*5
	  提示
	  　　先筛出所有素数，然后再分解。
*/
#include<stdio.h>
int fun(int tmp){
	int i = 0;
	int flag = 0;
	if (tmp==1||tmp==2||tmp==3){
		return 1;
	}
	for (i = 2; i <= (tmp / 2); i++){
		if (tmp%i == 0){
			return 0; //不是素数
		}
	}
	return 1;//是素数
}
int fun1(char* arr,int tmp){
	int i = 0;
	for (i = 2; i <= (tmp / 2); i++){
		if (tmp%i == 0){
			break;
		}
	}
	return i;
}

int fun2(char *arr, int tmp){
		int i = 0;
		int j = 2;
		int tmp1 = 0;
		while (1){
			tmp1 =  fun1(arr, tmp);
			arr[j++] = tmp1+'0';
			arr[j++] = '*';
			tmp = tmp / tmp1;
			if (fun(tmp)){ //如果tmp是素数
				arr[j] = tmp+'0';
				break;
			}
		}
		return j;
	}



int main(){
	int a = 0, b = 0;
	int i = 0, tmp = 0, j = 0, ret = 0;
	char arr[100000] = { '0' };
	scanf("%d%d", &a,&b);
	
	for (i = a; i <= b; i++){
		tmp = i;
		if (fun(tmp)){//是素数
			printf("%d=%d\n", tmp,tmp);
		}
		else{
			arr[0] = tmp;
			arr[1] = '=';
			ret = fun2(arr, tmp);
			for (j = 0; j <= ret; j++){ //将arr置新
				printf("%c", arr[j]);
			}
			printf("\n");
			for (j = 0; j <= ret; j++){ //将arr置新
				arr[j] = '0';
			}
		}
	}
	return 0;
}