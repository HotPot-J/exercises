#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a, const void*b){
	return (*(int*)b - *(int*)a); //此为逆序
}

int Huffuman(int* a,int n){
	int ret = 0, tmp = 0;
	int size = n;
	while (size>1){
		qsort(a, size, sizeof(int), cmp);
			tmp = a[size - 1] + a[size - 2];//最小的两个数相加 ‘费用’
			a[size - 2] = tmp;
		    ret = ret + tmp;
		    size--;
	}
	return ret;
}
int main(){
	int n = 0, i = 0;
	int a[100] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	printf("%d", Huffuman(a, n));
	return 0;
}