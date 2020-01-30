#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*

*/
int findUnsortedSubarray(int* nums, int numsSize){
	/*
	思路：按照选择排序的思想  判断nums[i]在有序状态下是否在这个位置 若不在 应该在哪个位置  l记录最左边需要调整的位置
	r记录在最右边需要调整的位置  最终结果即为r-l+1
	*/
	int i = 0, j = 0, l = numsSize, r = 0;//l 和 r代表无序的左右边界 一开始l=n r =0，代表一开始默认其为有序
	for (i = 0; i < numsSize - 1; i++){
		for (j = i + 1; j<numsSize; j++){
			if (nums[j]<nums[i]){
				l = i < l ? i : l; //返回i和l较小的值 因为是左边界
				r = j > r ? j : r;//返回j和r中较大的值 因为是右边界
			} 
		}
	}
	return r - l < 0 ? 0 : r - l + 1;
}
int main(){
	int a[] = { 1,2,3,4 };
	findUnsortedSubarray(a, 4);
	
	return 0;
}