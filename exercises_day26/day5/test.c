#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入 : [1, 2, 3, 1]
输出 : true
	 示例 2 :

 输入 : [1, 2, 3, 4]
  输出 : false
   示例 3 :

	输入 : [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
	 输出 : true

		  来源：力扣（LeetCode）
	  链接：https ://leetcode-cn.com/problems/contains-duplicate
	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
typedef int HPDataType;
typedef struct Heap {
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
void Swap(HPDataType* x1, HPDataType* x2){//交换数据函数
	HPDataType x = *x1;
	*x1 = *x2;
	*x2 = x;
}
void AdjustDwon(HPDataType* a, int n, int root){ //root是下标
	//构建小堆的向下调整->条件：root的左右子树都必须是小堆
	int parent = root;
	int child = root * 2 + 1;//默认为左孩子小 如果比对后右孩子小于左孩子 child++即可
	while (child<n){
		if (child + 1<n&&a[child + 1] < a[child]){ //child+1是怕越界访问  如果其没有右子树就不用++
			child++;
		}
		if (a[child] < a[parent]){
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}
/*
解题思路：如果采用传统的遍历比较 时间复杂度太高
        而采用堆排序  当一组数据有序是如果有重复的 则其肯定相邻  大大降低了时间复杂度
*/
void HeapSort(int* a, int n){
	int i = 0, end = n - 1;
	for (i = (n - 1 - 1) / 2; i >= 0; i--){
		AdjustDwon(a, n, i);
	}
	while (end>0){
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}
bool containsDuplicate(int* nums, int numsSize){
	int i = 0;
	if (numsSize <= 1){
		return false;
	}
	HeapSort(nums, numsSize);
	for (i = 0; i<numsSize - 1; i++){
		if (nums[i] == nums[i + 1]){
			return true;
		}
	}
	return false;
}

/*
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

 

 示例 1：

 输入：name = "alex", typed = "aaleex"
 输出：true
 解释：'alex' 中的 'a' 和 'e' 被长按。
 示例 2：

 输入：name = "saeed", typed = "ssaaedd"
 输出：false
 解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
 示例 3：

 输入：name = "leelee", typed = "lleeelee"
 输出：true
 示例 4：

 输入：name = "laiden", typed = "laiden"
 输出：true
 解释：长按名字中的字符并不是必要的。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/long-pressed-name
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
bool isLongPressedName(char * name, char * typed){
	char* n = name;
	char* t = typed;
	if (*t != *n){
		return false;
	}
	while (*t){
		if (*t == *n){
			t++;
			n++;
		}
		else if (*t != *n&&*t == *(n - 1)){
			t++;
		}
		else if (*t != *n&&*t != *(n - 1)){
			return false;
		}
	}
	if (*t == NULL&&*n == NULL){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	int a[2] = { 3,1 };
	containsDuplicate(a, 1);
	return 0;
}