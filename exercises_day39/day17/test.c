#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
问题描述
　　给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。现在要向棋盘中放入n个黑皇后和n个白皇后，使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？n小于等于8。
  输入格式
  　　输入的第一行为一个整数n，表示棋盘的大小。
	　　接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后。
	  输出格式
	  　　输出一个整数，表示总共有多少种放法。
		样例输入
		4
		1 1 1 1
		1 1 1 1
		1 1 1 1
		1 1 1 1
		样例输出
		2
*/
//写一个check函数判断当前位置是否可行  
//同一行有下过棋的不可行 同一列有下过棋的不可行 对角线有下过棋的不可行
int arr[8][8] = { 0 };
int ret = 0, n = 0;

int check( int i, int j ,int s){
	int k = 0, itmp = 0, jtmp = 0, tmp = 0;
	if (arr[i][j] == 0){  //该位置不可放皇后
		return 0;
	}
	for (k = 0; k < n; k++){//判断这一行有没有已经下过的
		if (arr[i][k] == s){
			return 0;
		}
	}
	for (k = 0; k < n; k++){ //判断该位置对应的这一列有没有已经下过的
		if (arr[k][j] == s){
			return 0;
		}
	}
	//判断对角线
   //计算出当前位置最左上角或者最右上角的位置 开始检查  最左上角itmp = i-min(i,j) jtmp = j-min(i,j)
	tmp = i >= j ? j : i;  //从左上角到右下角
	itmp = i - tmp;
	jtmp = j - tmp;
	while (itmp < n&&jtmp < n){ 
		if (arr[itmp][jtmp] == s){
			return 0;
		}
		itmp++;
		jtmp++;
	}

	tmp = i >= (n - 1 - j) ? (n - 1 - j) : i;
	itmp = i - tmp;
	jtmp = j + tmp;
	while (itmp < n&&jtmp >= 0){
		if (arr[itmp][jtmp] == s){
			return 0;
		}
		itmp++;
		jtmp--;
	}
	return 1;
}

int queen(int i,int s){
	int j;
	if (i == n){//代表放完了某一种皇后
		if (s == 2){//白皇后放完了  
			queen(0,3);//放黑皇后
		}
		else{
			ret++; //黑皇后也放完了
		}
		return 0;
	}
	for (j = 0; j < n; j++){
		if (arr[i][j] != 1){
			continue;
		}
		if (check(i, j,s)){//可以放
			arr[i][j] = s;
		}
		else{ //不可以放
			continue;
		}
		queen(i + 1, s);//判断下一行
		arr[i][j] = 1;  //回溯的时候将棋盘还原；
	}
		return 0;  //进行回溯 重置棋盘
	
}
int main(){
	int i = 0, j = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	queen(0, 2);
	printf("%d", ret);
	return 0;
}

