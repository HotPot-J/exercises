#define _CRT_SECURE_NO_WARNINGS 1
/*
��������
��������һ��N�׾���A�����A��M���ݣ�M�ǷǸ�������
  �������磺
	����A =
	  ����1 2  12   1+6  2+8
		��3 4  34   3+12 6+16
	    A��2����
		  7 10
		  15 22
	�����ʽ
		��һ����һ��������N��M��1<=N<=30, 0<=M<=5������ʾ����A�Ľ�����Ҫ�������
	    ������N�У�ÿ��N������ֵ������10�ķǸ���������������A��ֵ
	�����ʽ
		�����N�У�ÿ��N����������ʾA��M��������Ӧ�ľ������ڵ���֮����һ���ո����
					  ��������
					  2 2
					  1 2
					  3 4
					  �������
					  7 10
					  15 22
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
	int N = 0;
	int M = 0;
	int i = 0;
	int j = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int ret = 0;
	int **arr = NULL;
	int **arrRet = NULL;
	scanf("%d%d", &N, &M); 
	arr = (int**)malloc(N*sizeof(int));
	for (i = 0; i < N; i++){
		arr[i] = (int*)malloc(N*sizeof(int));
	}
	arrRet = (int**)malloc(N*sizeof(int));
	for (i = 0; i < N; i++){
		arrRet[i] = (int*)malloc(N*sizeof(int));
	}
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			scanf("%d", arr[i]+j);
		}
	}
	for (i = 0; i < N; i++){
		tmp1 = i;
		for (j = 0; j < N; j++){
			ret = ret + arr[i][j] * arr[tmp1][i];
			tmp1++;
		}
		arrRet[tmp3][tmp2] = ret;
		if (tmp2 < N-1){
			tmp2++;
		}
		else{
			tmp2 = 0;
			tmp3++;
		}
	}

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			printf("%d ", arrRet[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < N; i++){
		free(arr[i]);
	}
	free(arr);
	return 0;
}
