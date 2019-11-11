#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*

1.标题：递增三元组

给定三个整数数组
A = [A1, A2, ... AN],
B = [B1, B2, ... BN],
C = [C1, C2, ... CN]，
请你统计有多少个三元组(i, j, k) 满足：
1. 1 <= i, j, k <= N
2. Ai < Bj < Ck

【输入格式】
第一行包含一个整数N。
第二行包含N个整数A1, A2, ... AN。
第三行包含N个整数B1, B2, ... BN。
第四行包含N个整数C1, C2, ... CN。

对于30%的数据，1 <= N <= 100
对于60%的数据，1 <= N <= 1000
对于100%的数据，1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000

【输出格式】
一个整数表示答案

【样例输入】
3
1 1 1
2 2 2
3 3 3

【样例输出】
27


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
*/
//int fun(int N ,int *A, int *B, int *C){
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	int flag = 0;
//	for (i = 0; i < N; i++){
//		for (j = 0; j < N; j++){
//			for (k = 0; k < N; k++){
//				if (A[i] < B[j] && A[i] < C[k] && B[j] < C[k]){
//					flag++;
//				}
//			}
//		}
//	}
//	return flag;
//}
//int main(){
//	int N = 0;
//	int i = 0;
//	int *A;
//	int *B;
//	int *C;
//	scanf("%d", &N);
//	A = (int*)malloc(N*sizeof(int));
//	B= (int*)malloc(N*sizeof(int));
//	C = (int*)malloc(N*sizeof(int));
//	if (N <= 100000 && N >= 1){
//		for (i = 0; i < N;i++){
//			scanf("%d", &A[i]);
//		}
//		for (i = 0; i < N; i++){
//			scanf("%d", &B[i]);
//		}
//		for (i = 0; i < N; i++){
//			scanf("%d", &C[i]);
//		}
//	}
//	printf("\n%d", fun(N, A, B, C));
//	
//	free(A);
//	free(B);
//	free(C);
//	return 0;
//}

/*
标题：螺旋折线

如图p1.png所示的螺旋折线经过平面上所有整点恰好一次。
对于整点(X, Y)，我们定义它到原点的距离dis(X, Y)是从原点到(X, Y)的螺旋折线段的长度。

例如dis(0, 1)=3, dis(-2, -1)=9

给出整点坐标(X, Y)，你能计算出dis(X, Y)吗？

【输入格式】
X和Y

对于40%的数据，-1000 <= X, Y <= 1000
对于70%的数据，-100000 <= X， Y <= 100000
对于100%的数据, -1000000000 <= X, Y <= 1000000000

【输出格式】
输出dis(X, Y)


【样例输入】
0 1

【样例输出】
3
*/
/*
推导：
     把每一个螺旋看成一个正方形   则每一个正方形长度比后一个正方形长度少8
	                              起点均为：（-n,-(n-1)）  
	                              末尾均为：（-n,-n）
								  起点值B为前一个正方形的长度O+1  
								  末尾值L为起点+自身长度N-1
*/
int length(n){ //计算当前正方形长度
	if (n == 0){
		return 0;
	}
	else{
		return length(n - 1) + 8;
	}
}

int dis(int x, int y){ 
	int a = 0; int b = 0;
	int O = 0; int N = 0; //O N 分别代表前一个正方形长度和当前正方形长度；
	int start; int end;//起点和终点
	int start_length = 0;
	int end_length = 0;
	int n = 0; //存放a b中较大的值
	int mid2 = 0; //分别记录第2 . 1 .4象限的拐点长度;
	int mid1 = 0;
	int mid4 = 0;
	if (x<0){  
		 a = x*(-1);
	}
	else{
		a = x;
	}
	if (y<0){
		b = y*(-1);
	}
	else{
		b = y;
	}
	if (a > b){ //判断其是属于第几个正方形中的  a与b谁大就是第几个正方形
		n = a;
		N = length(a);
		O = N - 8;
	}
	else{
		n = b;
		N = length(b);
		O = N - 8;
	}
	start = n - 1;//起始纵坐标绝对值
	end = n; //末尾纵坐标绝对值
	start_length = O + 1;
	end_length = start_length + N - 1;
	if (x == (-n) && y == -(n - 1)){  //如果该点为起点或终点 直接返回起点终点的长度即可
		return start_length;
	}
	if (x == (-n) && y == (-n)){
		return end_length;
	}
	//第三象限
	if (x <= 0 && y <= 0){
		if (x == -n){
			return start - b + start_length;
		}
		else{
			return end_length - (n - a);
		}
	}
	//第二象限
	mid2 = start_length + (2 * n - 1);
	 if (x<=0 && y>=0){
		if (x == -n){
			return start + b + start_length;
		}
		else{
			return mid2 +( n - a);
		}
	}
	//第一象限
	mid1 = mid2 + 2 * n;
	if (x>=0 && y>=0){
		if (x == n){
			return mid1 + (n - b);
		}
		else{
			return mid2 + (n - a);
		}
	}

	//第四象限
	mid4 = mid1 + 2 * n;
	if (x >= 0 && y <= 0){
		if (x == n){
			return mid4 - (n - b);
		}
		else{
			return mid4 + (n - a);
		}
	}

}
int main(){
	int x = 0;
	int y = 0;
	scanf("%d%d", &x, &y);
	printf("%d",dis(x, y));
	return 0;
}
