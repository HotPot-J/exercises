#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<limits.h>
/*
53. 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/
//思路：分治思想  将数组分成左右两半  找到左边从中间往左边计算的最大和 找到从中间往右边的最大和 在计算包含中间索引的
//整个序列的最大和   选出该三个最大和中较大的 返回 则完成了目标
int my_max(int a, int b){
	return a > b ? a : b;
}
int num_fun(int* nums, int left, int right, int mid){
	int left_num = INT_MIN;
	int right_num = INT_MIN;
	int tmp = 0;
	//这里求包含mid的子序列最大值  小技巧是都从mid分别向左向右去遍历 找最大的和 从而保证了连续性 
	//比如-2 1 -3 4  若是mid等于-3  那么从右遍历到mid找到的最大和为-2+1 = 1  从mid+1到左找到的最大和为4 那么该子序列最大和为1+4 = 5  而该结果应为1，-2，4序列相加的结果  
	//但这不符合题意  不是连续的子序列 而都从mid开始遍历 就巧妙的避开了这种错误的情况 
	for (int i = mid; i >=left; i--){  
		tmp += nums[i];
		if (tmp > left_num){
			left_num = tmp;
		}
	}
	tmp = 0;
	for (int i = mid+1; i <=right; i++){
		tmp += nums[i];
		if (tmp > right_num){
			right_num = tmp;
		}
	}
	return left_num + right_num;
}
int _maxSubArray(int* nums, int left, int right){
	if (left == right){
		return nums[left];
	}
	int mid = left+(right-left) / 2; 
	int num_left = _maxSubArray(nums, left, mid);
	int num_right = _maxSubArray(nums, mid + 1, right);
	int Subnum = num_fun(nums, left, right, mid);
	return my_max(Subnum, my_max(num_left , num_right));
}
int maxSubArray(int* nums, int numsSize){
	return _maxSubArray(nums, 0, numsSize - 1);
}
int main(){
	int nums[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int len = sizeof(nums) / sizeof(nums[0]);
	maxSubArray(nums, len);
	return 0;
}