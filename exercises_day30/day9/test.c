#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例 :

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回[0, 1]

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//暴力解法 O(n*n)
int* twoSum(int* nums, int numsSize, int target, int*returnSize){
	int i = 0, j = 0;
	int* ret = (int *)malloc(sizeof(int)* 2);
	*returnSize = 2;
	for (i = 0; i<numsSize; i++){
		for (j = i + 1; j<numsSize; j++){
			if (nums[i] + nums[j] == target){
				ret[0] = i;
				ret[1] = j;
				break;
			}
		}
	}
	return ret;
}
