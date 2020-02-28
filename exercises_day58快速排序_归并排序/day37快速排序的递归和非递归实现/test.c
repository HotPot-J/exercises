#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 ���������˼�룺��ȡ������Ԫ�������е�ĳԪ����Ϊ��׼ֵ�����ո������뽫�����򼯺Ϸָ���������У�
 ��������������Ԫ�ؾ�С�ڻ�׼ֵ����������������Ԫ�ؾ����ڻ�׼ֵ��Ȼ���������������ظ��ù��̣�ֱ
 ������Ԫ�ض���������Ӧλ����Ϊֹ��
*/
void swap(int* a, int*b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//�ɸ�˼������Ƴ����������׼��ֵԽ�����м� ������ָ��Խ���� Ч��Խ�� ������д��һ����������ȡ��λ���ĺ���
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
//hoare����ÿ�ζ�ѡ������������һ��Ԫ����Ϊkey  ����ÿ�ηָ���±�
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

//�鲢����
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