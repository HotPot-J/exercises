#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
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
/*思路：分治的思想 若a为多数元素时，其满足个数大于 n/2    那么其必为左右连个子序列其中一个的多数元素
 证明： 假设a既不是l（左子序列长度）的中数，也不是r（右子序列的长度），那么a在l中出现的次数少于l/2
在r中出现的次数少于r/2次   那么 l/2 + r/2 < n/2 显然相互矛盾 所以上述结论成立

我们将数组递归分割成左右两个子序列  直到长度为1则多数元素就为其本身 再通过回溯去选出左右两边个数较多的多数元素
*/
int Fun_count(int* nums, int num, int l, int r){
	int count = 0;
	for (int i = l; i <= r; i++){
		if (nums[i] == num){
			count++;
		}
	}
	return count;
}
int _majorityElement(int* nums, int l, int r){
	//递归终止条件 当元素个数为1时，返回该元素数值 
	if (l == r){
		return nums[l];
	}
	//递归折半
	int mid = l + (r-l) / 2;
	int left = _majorityElement(nums, l, mid);
	int right = _majorityElement(nums, mid + 1, r);
	//比较左右两半谁的多位数个数多 返回个数多的元素
	if (left == right){
		//当左右两个数字一样则返回该元素即可
		return left;
	}
       //否则就数一下个数 进行对比	
		int countl = Fun_count(nums, left, l, r);
		int countr = Fun_count(nums, right, l, r);
		return countl > countr ? left : right;
}
int majorityElement(int* nums, int numsSize){
	return _majorityElement(nums, 0, numsSize - 1);
}
int main(){
	int nums[] = { 3, 2, 3 };
	int len = sizeof(nums) / sizeof(nums[0]);
	majorityElement(nums, len);
	return 0;
}