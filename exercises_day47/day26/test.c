#define _CRT_SECURE_NO_WARNINGS 1
/*
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
 示例 1：

 输入：[-4,-1,0,3,10]
 输出：[0,1,9,16,100]
 示例 2：

 输入：[-7,-3,2,3,11]
 输出：[4,9,9,49,121]
 ?

  提示：

  1 <= A.length <= 10000
  -10000 <= A[i] <= 10000
  A?已按非递减顺序排序。

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<stdio.h>
#include<stdlib.h>
//思路：先遍历负数部分并将其平方  负数平方后为降序 P1记录当前最后一个负数位置  然后以相同的方法遍历正数部分 正数部分为
//升序 P2记录正数部分的第一个位置  再使用归并排序p1向前遍历  p2向后遍历 时间复杂度 O(2n) 
int* sortedSquares(int* A, int ASize, int* returnSize){
	int *ret = (int*)malloc(ASize*sizeof(int));
	int* p1 = A, *p2 = NULL;
	int i = 0;
	while (p1 < A + ASize){//负数部分
		if (*p1 < 0){
			*p1 *= *p1;
			p1++;
		}
		else{
			p2 = p1;
			break;
		}
	}
	p1 = p1 - 1;
	while (p2&&p2 < A + ASize){//若p2为空则说明没有正数 防止访问空指针
		*p2 *= *p2;
		p2++;
	}
	p2 = p1 + 1;
	//归并排序
	while (p1 >= A&&p2 < A + ASize){
		if (*p1 < *p2){
			ret[i++] = *p1;
			p1--;
		}
		else{
			ret[i++] = *p2;
			p2++;
		}
	}
	//剩下的直接放进结果数组即可
	while (p1 >= A){
		ret[i++] = *p1;
		p1--;
	}
	while (p2&&p2 < A + ASize){
		ret[i++] = *p2;
		p2++;
	}
	*returnSize = ASize;
	return ret;
}

/*
给定一个包含 n 个整数的数组?nums，判断?nums?中是否存在三个元素 a，b，c ，使得?a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
 示例：
 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

 满足要求的三元组集合为：
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/3sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//思路 ：先将数组排序  定义i固定一个数字开始遍历 当作固定的一个数字  left和right为机动的两个数字去寻找满足和i相加的数字
//定义left从i后一个数字数字开始遍历 定义right指向最大数字 逐步缩小范围 直至满足条件 当left>right i++ right = Asize-1
//left = i+1 寻找新的答案
int cmp(const void*a, const void*b){
	return *(int*)a - *(int*)b;         //升序
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	//特判
	if (numsSize < 3){
		*returnSize = 0;
		return NULL;
	}
	//开辟返回的二维数组空间
	int** ret = (int**)malloc(50000 * sizeof(int*));
	*returnColumnSizes = (int*)malloc(50000 * sizeof(int));
	int i = 0, left = 1, right = numsSize - 1;
	int j = 0;
	//排序
	qsort(nums, numsSize, sizeof(int), cmp);
	//遍历数组 寻找结果
	while (i < numsSize - 1){
		if (left>right || left == right){
			//没找到 i往后走 重新初始化left和right的位置 寻找新的正确结果
			while (nums[i] == nums[i + 1]){ //防止重复 如果后一个数字和当前相等则往后走 直到不相等
				i++;
				if (i >= numsSize-1){
					break;
				}
			}
			i++;
			left = i + 1, right = numsSize - 1;
		}
		else if (nums[i] + nums[left] + nums[right] == 0){//满足条件 放入结果数组中
			ret[j] = (int*)malloc(sizeof(int)* 3);
			ret[j][0] = nums[i];
			ret[j][1] = nums[left];
			ret[j][2] = nums[right];
			(*returnColumnSizes)[j] = 3;
			j++;
			while (left<right && nums[left] == nums[left + 1]) left++; // 去重
			while (left<right && nums[right] == nums[right - 1]) right--; // 去重
			left++;
			right--;
		}
		else if (nums[i] + nums[left] + nums[right] < 0){//和小于0 将left右移增大三数之和 缩小范围
			left++;
		}
		else if (nums[i] + nums[left] + nums[right] > 0){
			right--;
		}
	}
	*returnSize = j;
	return ret;
}
int main(){
	int a[5] = { -2, 0, 0, 2, 2};
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	free(threeSum(a, 5, &returnSize, &returnColumnSizes));
	return 0;
}