#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

 

 示例：

 输入：[3,1,2,4]
 输出：[2,4,3,1]
 输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/sort-array-by-parity
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//思想就是从后往前赋值奇数 从前往后赋值偶数
int* sortArrayByParity(int* A, int ASize, int* returnSize){
	int i = 0, top = 0, tail = ASize - 1;
	int* ret = (int*)malloc(ASize*sizeof(int));
	*returnSize = ASize;
	for (i = 0; i<ASize; i++){
		if (top>tail){
			break;
		}
		if (A[i] % 2 == 0){
			ret[top++] = A[i];
		}
		else{
			ret[tail--] = A[i];
		}
	}
	return ret;
}

/*
给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。

我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。

如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。

示例 1:

输入:
nums = [1, 7, 3, 6, 5, 6]
输出: 3
解释:
索引3 (nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
同时, 3 也是第一个符合要求的中心索引。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-pivot-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//思路： 设数组的总和为s，左边和为leftsum，当前索引位置为nums[i]  则如果该索引左右相等 则有： leftsum = s-nums[i]-leftsum成立
//而从左往右遍历该数组 正好利用leftsum+=nums[i] 动态计算左边之和 
int sum(int* a,int size){
	int i = 0, sum = 0;
	for (i = 0; i < size; i++){
		sum += a[i];
	}
	return sum;
}
int pivotIndex(int* nums, int numsSize){
	int s = sum(nums, numsSize);
	int leftsum = 0, i = 0, ret = -1;
	for (i = 0; i < numsSize; i++){
		if (leftsum == s - nums[i] - leftsum){
			if (ret==-1||ret>i){
				ret = i;
			}
		}
		leftsum += nums[i];
	}
	return ret;
}
int main(){
	int arr[6] = { -1, -1, 0, 0, -1, -1 };
	pivotIndex(arr, 6);
	return 0;
}