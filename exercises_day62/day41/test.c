#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*K ��ȡ������󻯵������
����һ���������� A������ֻ�������·����޸ĸ����飺����ѡ��ĳ�������� i ���� A[i] �滻Ϊ - A[i]��Ȼ���ܹ��ظ�������� K �Ρ������ǿ��Զ��ѡ��ͬһ������ i����
�����ַ�ʽ�޸�����󣬷���������ܵ����͡�

ʾ�� 1��
���룺A = [4, 2, 3], K = 1
�����5
���ͣ�ѡ������(1, ) ��Ȼ�� A ��Ϊ[4, -2, 3]��
ʾ�� 2��
���룺A = [3, -1, 0, 2], K = 3
�����6
���ͣ�ѡ������(1, 2, 2) ��Ȼ�� A ��Ϊ[3, 1, 0, 2]��
ʾ�� 3��
���룺A = [2, -3, -1, 5, -4], K = 2
�����13
���ͣ�ѡ������(1, 4) ��Ȼ�� A ��Ϊ[2, 3, -1, 5, 4]��

��ʾ��
1 <= A.length <= 10000
1 <= K <= 10000
- 100 <= A[i] <= 100
*/

//˼·��̰���㷨  �����ܰ����ĸ�����Ϊ����  
//������������Ϊ��������ʣ�����  �������: 
//����ʣ��Ϊż�� ֱ�ӷ��ص�ǰ����֮��
//��Ϊ����ѡ��ǰ��С��������Ϊ����
int cmp(const void*a, const void*b){
	return *(int*)a>*(int*)b;
}
int sumArray(int*A, int Asize){
	int i = 0, ret = 0;
	for (i = 0; i < Asize; i++){
		ret += A[i];
	}
	return ret;
}
int largestSumAfterKNegations(int* A, int ASize, int K){
	int i = 0,tmp = 0, ret = 0,*flag = A;
	qsort(A, ASize, sizeof(int), cmp);
	while (flag<A + ASize&&*flag<0){
		flag++;
	}
	if (flag == A){
		//������ȫΪ����
		tmp = K % 2;
		if (tmp){
			//˵��������һ�������óɸ�����������С��Ϊ����
			A[0] = -A[0];
		}
	}
	else if (flag == A + ASize){
		//������ȫΪ����
		while (K&&i<ASize){  //����С�ĸ���һ�θ�Ϊ����
			A[i] = -A[i++];
			K--;
		}
		if (K){
			//K��ʣ��
			tmp = K % 2;
			if (tmp){
				A[ASize - 1] = -A[ASize - 1];
			}
		}
	}
	else{
		//�����и�
		while (A[i] < 0){
			A[i] = -A[i++];
			K--;
		}
		if (K){
			//����ʣ���K
			tmp = K % 2;
			if (tmp){
				//����ʹһ��������Ϊ���� ����С��������Ϊ����
				qsort(A, ASize, sizeof(int), cmp);
				A[0] = -A[0];
			}
		}
	}
	return sumArray(A, ASize);
}

int main(){
	int A[] = { 3,-1,0,2};
	int len = sizeof(A) / sizeof(A[0]);
	largestSumAfterKNegations(A, len, 3);
	return 0;
}