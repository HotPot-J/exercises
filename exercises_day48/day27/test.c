#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//思路 1.先排序 再比对 此时为升序状态 2.当p1和p2谁小谁向后走 只有这样才有可能找到相同的
int cmp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int* p1 = nums1, *p2 = nums2;
	int min = nums1Size <= nums2Size ? nums1Size : nums2Size;
	int j = 0;
	int* ret = (int*)malloc(sizeof(int)*min);
	qsort(nums1, nums1Size, sizeof(int), cmp);
	qsort(nums2, nums2Size, sizeof(int), cmp);
	while (p1 < nums1 + nums1Size&&p2 < nums2 + nums2Size){
		if (*p1 == *p2){
			ret[j++] = *p1;
			while (p1 < nums1 + nums1Size - 1 && *p1 == *(p1 + 1)){
				p1++;
			}
			p1++;
			p2++;
		}
		else{
			if (*p1 < *p2){
				p1++;
			}
			else if (*p1>*p2){
				p2++;
			}
		}
	}
	*returnSize = j;
	return ret;
}

/*
给定一个包括?n 个整数的数组?nums?和 一个目标值?target。找出?nums?中的三个整数，使得它们的和与?target?最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//int cmp(const void* a, const void* b){
//	return *(int*)a - *(int*)b;
//}
int threeSumClosest(int* nums, int numsSize, int target){
	int i = 0, p = i+1, q = numsSize - 1;
	int ret = nums[i] + nums[p] + nums[q];
	qsort(nums, numsSize, sizeof(int), cmp);
	while (i < numsSize){
		if (p>q || p == q){
			i++;
			if (i > numsSize - 2){ //小于三个数
				break;
			}
			p = i + 1;
			q = numsSize-1;
			if (p == q){
				continue;
			}
		}
		//满足条件就改变ret的值
		if (abs(nums[i] + nums[p] + nums[q] - target) < abs(ret - target)){ 
			ret = nums[i] + nums[p] + nums[q];
		}
        if (nums[i] + nums[p] + nums[q]<target){
			p++;
		}
        else if (nums[i] + nums[p] + nums[q]>target){
			q--;
		}
		else{
			return ret;
		}
	}
	return ret;
}
int main(){
	int a[4] = { 0,-4,1,-5 };
	threeSumClosest(a, 4, 0);
	return 0;
}