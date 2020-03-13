#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
169. 多数元素
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ? n/2 ? 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
示例 1:
输入: [3,2,3]
输出: 3
示例 2:
输入: [2,2,1,1,1,2,2]
输出: 2
*/
//思路 控制指针
int cmp(const void* a, const void* b){
	return *(int*)a > *(int*)b;
}
int majorityElement(int* nums, int numsSize){
	int* tmp = nums;
	int flag = 1;
	if (numsSize == 1){
		return *nums;
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	while (tmp < nums + numsSize-1){
		if (flag>numsSize / 2){
			break;
		}
		if (*tmp == *(tmp+ 1)){
			flag++;
		} 
		else{
			if (flag > numsSize / 2){
				break;
			}
			else{
				flag = 1;
			}
		}
		tmp++;
	}
	return *(tmp - 1);
}
/*
面试题 16.17. 连续数列
给定一个整数数组（有正数有负数），找出总和最大的连续数列，并返回总和。
示例：
输入： [-2,1,-3,4,-1,2,1,-5,4]
输出： 6
解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/
//思路 动态规划
int maxSubArray(int* nums, int numsSize){
	int *p = nums;
	int tmp = *p;
	int sum = tmp;
	p++;
	while (p < nums + numsSize){
		if (tmp>0){
			tmp += *p;
		}
		else{
			tmp = *p;
		}
		if(tmp>sum){
			sum = tmp;
		}
		p++;
	}
	return sum;
}