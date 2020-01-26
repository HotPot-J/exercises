#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int* plusOne(int* digits, int digitsSize, int* returnSize){
	int* ret = (int*)malloc(sizeof(digits[0])*(digitsSize + 1));
	int i = digitsSize - 1;
	digits[i] += 1;
	for (i; i > 0; i--){
		if (digits[i] >= 10){
			digits[i - 1] += 1;
			digits[i] = 0;
		}
	}
	if (digits[0] >= 10){
		ret[0] = 1;
		ret[1] = 0;
		for (i = 1; i<digitsSize; i++){
			ret[i + 1] = digits[i];
		}
		*returnSize = digitsSize + 1;
	}
	else{
		for (i = 0; i<digitsSize; i++){
			ret[i] = digits[i];
		}
		*returnSize = digitsSize;
	}
	return ret;
}

/*
给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

示例 1:

输入: [3, 2, 1]

输出: 1

解释: 第三大的数是 1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/third-maximum-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
思想：排序 然后去重 返回倒数第三个数据即可
*/
int cmp(const void *a, const void *b){
	return  (*(int *)a - *(int *)b);
}

int thirdMax(int* nums, int numsSize){
	int top = 0, tail = 1;
	int i = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	while (tail<numsSize){
		if (nums[top] == nums[tail]){
			tail++;
		}
		else{
			top++;
			nums[top] = nums[tail];
			tail++;
		}
	}
	if (top<2){
		return nums[top];
	}
	else{
		return nums[top-2];
	}
}
int main(){
	int a[3] = { 2, 1, 1 };
	int returnSize = 0;
	thirdMax(a, 3);
	return 0;
}