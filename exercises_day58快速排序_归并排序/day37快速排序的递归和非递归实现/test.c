#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 快速排序的思想：任取待排序元素序列中的某元素作为基准值，按照该排序码将待排序集合分割成两子序列，
 左子序列中所有元素均小于基准值，右子序列中所有元素均大于基准值，然后最左右子序列重复该过程，直
 到所有元素都排列在相应位置上为止。
*/
void swap(int* a, int*b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//由该思想可以推出：当这个基准存值越处于中间 则将数组分割的越均匀 效率越高 所以先写出一个三个数字取中位数的函数
int midSum(int* arr, int front, int back){
	int mid = (back - front + 1) / 2;
	if (((arr[front] >= arr[mid] || arr[front] >= arr[back])) && ((arr[front] <= arr[mid] || arr[front] <= arr[back]))){
		return front;
	}
	else if (((arr[mid] >= arr[front] || arr[mid] >= arr[back])) && ((arr[mid] <= arr[front] || arr[mid] <= arr[back]))){
		return mid;
	}
	else{
		return back;
	}
}
//hoare法：每次都选择子数组的最后一个元素最为key  返回每次分割的下标
int pointer(int*arr,int front,int back){
	int mid = midSum(arr, front, back);
	swap(&arr[mid], &arr[back]);
	int key = back;
	while (front < back){
		while (front<back&&arr[front] <= arr[key]){
			front++;
		}
		while (front<back&&arr[back] >= arr[key]){
			back--;
		}
		swap(&arr[front], &arr[back]);
	}
	swap(&arr[front], &arr[key]);
	return front;
}

void quickSort(int *arr, int pront, int back){
	int mid = back+1;
	if (pront>= back){
		return;
	}
	else{
		mid = pointer(arr, pront, back);
		quickSort(arr, pront, mid - 1);
		quickSort(arr, mid + 1, back);
	}
}

//归并排序
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);

	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}
void MergeSort(int* a, int n)
{

	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
int main(){
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, size);
	return 0;
}