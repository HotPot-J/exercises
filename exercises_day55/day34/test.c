#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
第三大的数字 若没有 则返回最大数字
*/
//思路： 排序 去重 判断
int cmp(const void*a, const void*b){
	return *(int*)a > *(int*)b;
}
int thirdMax(int* nums, int numsSize){
	int *top = nums, *tail = nums + 1;
	int Newsize = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	//去重
	while (tail < nums + numsSize){
		if (*top != *tail){
			top++;
			*top = *tail;
			Newsize++;
		}
		tail++;
	}
	if (Newsize < 2){
		return nums[Newsize];
	}
	else{
		return nums[Newsize - 2];
	}
}
int main(){
	int a[] = { 1, 2, 3 };
	int len = sizeof(a) / sizeof(a[0]);
	thirdMax(a, len);
	return 0;
}