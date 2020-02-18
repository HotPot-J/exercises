#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void printarr(int* arr, int size){
	int i = 0;
	for (i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}
void swap(int*a, int*b){
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
ѡ������ 
˼�룺��begin-end����ÿ��ѡ��һ����Сֵ��һ�����ֵ ����begin��end��ָ��λ���� ������С����
*/
void selectSort(int* arr,int size){
	int i = 0, begin = 0, end = size - 1;
	int mini = 0, maxi = 0;
	while (begin < end){
		mini = begin; maxi = begin;
		for (i = begin; i <= end; i++){
			if (arr[i]>arr[maxi]){
				maxi = i;
			}
			if (arr[i] < arr[mini]){
				mini = i;
			}
		}
		swap(&arr[begin], &arr[mini]);
		if (begin == maxi){//���������max������mini���λ��ȥ�� 
			maxi = mini;
		}
		swap(&arr[end], &arr[maxi]);
		begin++; end--;
	}
}

//������

void adjustdwon(int* arr, int size, int root){
	//��������µ����㷨
	int parent = root;
	int child = parent * 2 + 1;
	while (child < size){
		if (child+1<size  && arr[child + 1]>arr[child]){
			++child;
		}
		if (arr[child]>arr[parent]){
			swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}
void HeapSort(int* arr, int size){
	int i = 0;
	//���� �����
	for (i = (size - 1 - 1) / 2; i >= 0; i--){
		adjustdwon(arr, size, i);
	}
	int end = size - 1;
	while (end > 0){
		swap(&arr[0], &arr[end]);
		adjustdwon(arr, end, 0);
		end--;
	}

}


int main(){
	int arr[] = { 3, 2, 4, 5, 1, 0, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	//selectSort(arr, size);
	printarr(arr, size);
	return 0;
}