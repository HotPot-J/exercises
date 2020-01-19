#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeElement(int* nums, int numsSize, int val){
	int k = 0, i = 0;
	for (i = 0; i<numsSize; i++){
		if (nums[i] != val){
			nums[k] = nums[i];
			k++;
		}
	}
	return k;
}
int removeElement(int* nums, int numsSize, int val){
	int*top = nums;
	int*tail = nums;
	int size = 0;
	while (tail < nums + numsSize){
		if (*tail == val){
				tail++;
		}
		else{
			*top = *tail;
			top++;
			size++;
			tail++;
		}
	}
	return size;
}
int main(){
	int nums[2] = { 4,5 };
	removeElement(nums, 2, 5);
	return 0;
}