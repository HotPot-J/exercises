#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
215. �����еĵ�K�����Ԫ��
��δ������������ҵ��� k ������Ԫ�ء���ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
ʾ�� 1:
����: [3,2,1,5,6,4] �� k = 2
���: 5
ʾ�� 2:
����: [3,2,3,1,2,4,5,5,6] �� k = 4
���: 4
*/
int cmp(const void* a, const void* b){
	return *(int*)a < *(int*)b;
}
int findKthLargest(int* nums, int numsSize, int k){
	qsort(nums, numsSize, sizeof(int), cmp);
	return nums[k - 1];
}
