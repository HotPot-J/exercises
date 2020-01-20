#define _CRT_SECURE_NO_WARNINGS 1
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。
*/
int searchInsert(int* nums, int numsSize, int target){
	int i = 0;
	//如过target为该数组中最大/最小的数字 则应插入到数组的最后/最前 
	int flag = 0;
	if (target > nums[0]){
		flag = numsSize;
	}
	for (i = 0; i < numsSize; i++){
		if (nums[i] == target){
			return i;
		}
		if (i + 1 <= numsSize - 1){//防止越界访问
			if (target >= nums[i] && target <= nums[i + 1]){
				flag = i + 1;
			}
		}
	}
	return flag;
}