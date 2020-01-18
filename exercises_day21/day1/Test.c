#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
void rotate(int* nums, int numsSize, int k){
	int* top = nums;
	int* tail = nums + numsSize - 1;
	int i = 0, num = *tail;
	while (k--){
		for (i = numsSize - 1; i >= 0; i--){
			nums[i] = nums[i - 1];
		}
		*top = num;
		num = *tail;
	}
}
*/
void revresal(int* nums, int size){
int* top = nums;
int* tail = nums + size - 1;
int tmp = 0;
while (top<tail){
tmp = *top;
*top = *tail;
*tail = tmp;
top++;
tail--;
}
}
void rotate(int* nums, int numsSize, int k){
	if (numsSize != 1 && numsSize != 0){
		if (k >= numsSize){
			while (k--){
				revresal(nums, numsSize);
			}
		}
		else{
			revresal(nums, numsSize - k);//翻转前半部分
			revresal(nums + numsSize - k, k);//翻转后半部分
			revresal(nums, numsSize);
		}
	}
}
int main(){
	int arr[7] = { 1, 2, 3};
	int i = 0;
	rotate(arr, 3, 3);
	return 0;
}
