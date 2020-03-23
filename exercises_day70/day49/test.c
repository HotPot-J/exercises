#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
53. 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/
/*思路：之前一次用了分治法来寻找 显然代码冗长  最近在学习动态规划法 所以尝试用动态规划实现：
  首先我们定义一个d[i]来保存以第i个下标结尾的最大子序列和 以方便去判断当前数字应该加入还是应该自立为王？
  即：d[i-1]+nums[i]>nums[i] 这让nums[i]加入 反之则以nums[i]便是以i结尾最大的子序列和
  不难得到状态转移方程：d[i] = max(d[i-1]+nums[i],nums[i])
  
  为了节省空间 我们可以原地用nums[i]来保存当前最大字序列和
  由状态转移方程 我们可知：i = 0时 d[i] = 0;

  时间复杂度为O(n) 空间复杂度O(1)
*/
int my_max(int a, int b){
	return a > b ? a : b;
}
int maxSubArray(int* nums, int numsSize){
	if (numsSize == 1){
		return nums[0];
	}
	int max = nums[0];
	for (int i = 1; i < numsSize; i++){
		nums[i] = my_max(nums[i - 1] + nums[i], nums[i]);
		if (nums[i]>max){
			//保存最大的子序列和
			max = nums[i];
		}
	}
	return max;
}