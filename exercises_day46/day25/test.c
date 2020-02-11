#define _CRT_SECURE_NO_WARNINGS 1
/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例?1:

给定数组 nums = [1,1,2],

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。

你不需要考虑数组中超出新长度后面的元素。
示例?2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//思路：采用一前一后双指针  若相同则top指针不动 用tail指针当前的值覆盖top指针所指向的地址空间的值 tail++
//                          若不同则top++     用tail指针当前的值覆盖top指针所指向的地址空间的值 tail++
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize){
	int* top = nums;
	int* tail = nums + 1;
	int i = 0, size = 1;
	if (numsSize == 0){
		return 0;
	}
	while (tail < nums + numsSize){
		if (*top == *tail){//相等
			*top = *tail;
			tail++;
		}
		else{//不相等
			top++;
			size++;
			*top = *tail;
			tail++;
		}
	}
	return size;
}
/*
删除重复数字的进阶版本 ：使每个元素最多出现两次
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例?1:

给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//思路: 运用覆盖法覆盖多余的数字 top永远指向需要覆盖的位置 tail往后遍历直到tail遍历完整个数组（有点快慢指针的意思--、）
int removeDuplicatesPlus(int* nums, int numsSize){
	int* top = nums+1;
	int* tail = nums+1;
	int size = 1, count = 1;
	while (tail < nums + numsSize){
		if (*tail == *(tail - 1)){
			count++;
		}
		else{
			count = 1;
		}
		if (count <= 2){
			*top = *tail;
			top++;
			size++;
		}
		tail++;
	}
	return size;
}
int main(){
	int a[9] = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
	removeDuplicatesPlus(a, 9);
	return 0;
}