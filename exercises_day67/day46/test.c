#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
932. Ư������
����ĳЩ�̶��� N��������� A ������ 1, 2, ..., N ��ɵ����У�ʹ�ã�
����ÿ�� i < j���������� k ���� i < k < j ʹ�� A[k] * 2 = A[i] + A[j]��
��ô���� A ��Ư�����顣
���� N����������Ư������ A����֤����һ������
ʾ�� 1��
���룺4
�����[2,1,4,3]
ʾ�� 2��
���룺5
�����[3,1,2,5,4]
*/
/**
* Note: The returned array must be malloced, assume caller calls free().
*/

/*
˼· ���ݹ� ����
   ����⼼���Ժ�ǿ������ �����Ư����ʽ����Ҫ�������㣺��i<j  i<k<j��ʱ��  2*A[k]!=A[i]*A[j]
   �۲칫ʽ��ֻ ʽ�����Ϊż�� �ұ�Ϊ���� ������Ҫ��ʽ����� ���ǽ������Ϊ�������룬���ȫ������ ���ұ�
   ȫ��ż������
   N = 1 : 1
   N = 2 : 1 2
   N = 3 : 1 3 2
   N = 4 : 1 3 2 4
   N = 5 : 1 3 5 2 4
   N = 6 : 1 5 3 2 6 4   �������֣�N3*2-1  ż������N3*2
   N = 7 : 1 5 3 7 2 6 4   �������֣� N4*2-1 ż������N3*2
   N = 8 : 1 5 3 7 2 6 4 8 �������֣�N4*2-1 ż������N4*2
   �ɵõ����ƹ�ʽ: ��N>=6  �������֣�N��(N+1)/2��*2-1  ż������N��N/2��*2
*/
int* GetBeautifulArray(int num, int* size)
{
	int* outArray = NULL;
	int* leftArray = NULL;
	int* rightArray = NULL;
	int leftSize = 0;
	int rightSize = 0;
	int i;

	if (num == 1) {
		outArray = (int *)malloc(sizeof(int));
		outArray[0] = 1;
		*size = 1;
		return outArray;
	}

	leftArray = GetBeautifulArray((num + 1) / 2, &leftSize);
	rightArray = GetBeautifulArray(num / 2, &rightSize);
	*size = leftSize + rightSize;
	outArray = (int *)malloc(sizeof(int)* (*size));
	for (i = 0; i < leftSize; i++) {
		outArray[i] = leftArray[i] * 2 - 1;
	}
	for (i = 0; i < rightSize; i++) {
		outArray[i + leftSize] = rightArray[i] * 2;
	}
	free(leftArray);
	free(rightArray);
	return outArray;
}

int* beautifulArray(int N, int* returnSize)
{
	return GetBeautifulArray(N, returnSize);
}
int main(){
	int N = 5;
	int returnSize = 0;
	int* ret = beautifulArray(N, &returnSize);
	free(ret);
	return 0;
}