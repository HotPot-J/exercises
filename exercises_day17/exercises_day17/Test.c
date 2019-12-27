#define _CRT_SECURE_NO_WARNINGS 1
/*
问题描述
　　给定一个N阶矩阵A，输出A的M次幂（M是非负整数）
  　　例如：
	　　A =
	  　　1 2  12   1+6  2+8
		　3 4  34   3+12 6+16
	    A的2次幂
		  7 10
		  15 22
	输入格式
		第一行是一个正整数N、M（1<=N<=30, 0<=M<=5），表示矩阵A的阶数和要求的幂数
	    接下来N行，每行N个绝对值不超过10的非负整数，描述矩阵A的值
	输出格式
		输出共N行，每行N个整数，表示A的M次幂所对应的矩阵。相邻的数之间用一个空格隔开
					  样例输入
					  2 2
					  1 2
					  3 4
					  样例输出
					  7 10
					  15 22
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
	int N = 0;
	int M = 0;
	int i = 0;
	int j = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int ret = 0;
	int **arr = NULL;
	int **arrRet = NULL;
	scanf("%d%d", &N, &M); 
	arr = (int**)malloc(N*sizeof(int));
	for (i = 0; i < N; i++){
		arr[i] = (int*)malloc(N*sizeof(int));
	}
	arrRet = (int**)malloc(N*sizeof(int));
	for (i = 0; i < N; i++){
		arrRet[i] = (int*)malloc(N*sizeof(int));
	}
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			scanf("%d", arr[i]+j);
		}
	}
	for (i = 0; i < N; i++){
		tmp1 = i;
		for (j = 0; j < N; j++){
			ret = ret + arr[i][j] * arr[tmp1][i];
			tmp1++;
		}
		arrRet[tmp3][tmp2] = ret;
		if (tmp2 < N-1){
			tmp2++;
		}
		else{
			tmp2 = 0;
			tmp3++;
		}
	}

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			printf("%d ", arrRet[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < N; i++){
		free(arr[i]);
	}
	free(arr);
	return 0;
}
