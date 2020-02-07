#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a, const void*b){
	return(*(int*)b - *(int* )a); //ÄæÐò
}

void TopK(int* a,int asize,int b[][3],int bsize){
	int ret[1000] = { 0 };
	int rsize = 0, i = 0, j = 0;
	for (i = 0; i < bsize; i++){
		rsize = b[i][1] - b[i][0] + 1; 
		memcpy(ret, a + b[i][0] - 1, sizeof(int)*rsize);
		qsort(ret, rsize, sizeof(int), cmp);
		printf("%d\n", ret[b[i][2]-1]);
	}
}
int main(){
	int asize = 0, bsize = 0, i = 0, j = 0;
	int a[1000] = { 0 };
	int b[1000][3] = { 0 };
	scanf("%d", &asize);
	for (i = 0; i < asize; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &bsize);
	for (i = 0; i < bsize; i++){
		for (j = 0; j < 3; j++){
			scanf("%d", &b[i][j]);
		}
	}
	TopK(a, asize, b, bsize);
	return 0;
}