#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
问题描述
　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。一开始位于矩阵左上角，方向向下。
  输入格式
  　　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。
	输出格式
	　　输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。
	  样例输入
	  3 3
	  1 2 3
	  4 5 6
	  7 8 9
	  样例输出
	  1 4 7 8 9 6 3 2 5
*/
void RecoveryNumber(int arr[][200],int row,int col){
	int up = 0, down = row - 1, left = 0, right = col - 1;
	int i = 0, j = 0;
	while (left<=right&&up<=down){
		for (i = up; i <= down; i++){  //向下走
			printf("%d ", arr[i][left]);
		}
		left++;
		if (left > right||up > down){
			break;
		}
		for (i = left; i <= right; i++){//向右走
			printf("%d ", arr[down][i]);
		}
		down--;
		if (left > right||up > down){
			break;
		}
		for (i = down; i >= up; i--){//向上走
			printf("%d ", arr[i][right]);
		}
		right--;
		if (left > right||up > down){
			break;
		}
		for (i = right; i >= left; i--){
			printf("%d ", arr[up][i]);
		}
		up++;
		if (left > right||up > down){
			break;
		}
	}
}
int main(){
	int arr[200][200] = { 0 };
	int m = 0, n = 0, i = 0, j = 0;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	RecoveryNumber(arr, m, n);
	return 0;
}