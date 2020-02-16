#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//打印输出数组 方便测试是否排序成功
void PrintArry(int* a, int size){
	int i = 0;
	for (i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
}
//升序

//插入排序 O(n^2)
/*
思想： 当插入一个数字i时 该序列之前的数字已经有序 此时用i去比对该序列并将其插入正确的位置 该位置的原有数字依次向后
移动一个单元   
将该序列的第一个数字定位有序 依次往后遍历直至a[size-2] 每次将a[i+1]向前插入
*/
void InsertSort(int* a, int size){
	int end = 0, tmp = 0, i = 0;
	for (i = 0; i < size - 1; i++){
		end = i;
		tmp = a[i + 1];
		//单趟排序 将tmp插入[0,end]的有序区间 依旧保持有序
		while (end >= 0){     
			if (a[end] > tmp){  //当前end指向的位置向后挪
				a[end + 1] = a[end--];
			}
			else{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//希尔排序(对插入排序的改进优化) O(N^1.3-N^2);
/*
思想： 预排序：接近有序  分组进行插入 
       插入排序 ：有序
*/
void ShellSort(int* a, int size){
	int distance = size, tmp = 0, end = 0, i = 0;
	while (distance > 1){   //当distance的间距大于1的时候就进行不断缩小间距的插入排序
		distance = distance / 3 + 1;  //+1巧妙的让所有的结果最终都满足间距为1 使整个序列有序
		for (i = 0; i<size - distance; i++){ //i++很巧妙的同时让分组进行排序
			end = i;
			tmp = a[i + distance];
			while (end >= 0){ //单趟分组插入排序
				if (a[end] > tmp){
					a[end + distance] = a[end];
					end -= distance;
				}
				else{
					break;
				}
			}
			a[end+ distance] = tmp;
		}
	}
}

int main(){
	int a[] = { 3, 4, 2, 6, 4, 3, 60, 1 };
	int size = sizeof(a) / sizeof(int);
	//InsertSort(a, size);
	ShellSort(a, size);
	PrintArry(a, size);

	return 0;
}