#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
��������
��������ȡ�������ؾ���ı�ȡ��������ǰ������������ȡ���Ѿ�ȡ��������ת90�ȡ�һ��ʼλ�ھ������Ͻǣ��������¡�
  �����ʽ
  ���������һ��������������200��������m, n����ʾ������к��С�������m��ÿ��n����������ʾ�������
	�����ʽ
	�������ֻ��һ�У���mn������Ϊ����������ȡ���õ��Ľ������֮����һ���ո�ָ�����ĩ��Ҫ�ж���Ŀո�
	  ��������
	  3 3
	  1 2 3
	  4 5 6
	  7 8 9
	  �������
	  1 4 7 8 9 6 3 2 5
*/
void RecoveryNumber(int arr[][200],int row,int col){
	int up = 0, down = row - 1, left = 0, right = col - 1;
	int i = 0, j = 0;
	while (left<=right&&up<=down){
		for (i = up; i <= down; i++){  //������
			printf("%d ", arr[i][left]);
		}
		left++;
		if (left > right||up > down){
			break;
		}
		for (i = left; i <= right; i++){//������
			printf("%d ", arr[down][i]);
		}
		down--;
		if (left > right||up > down){
			break;
		}
		for (i = down; i >= up; i--){//������
			printf("%d ", arr[i][right]);
		}
		right--;
		if (left > right||up > down){
			break;
		}
		for (i = right; i >= left; i--){
			printf("%d ", arr[up][i]);
		}
		up++;
		if (left > right||up > down){
			break;
		}
	}
}
int main(){
	int arr[200][200] = { 0 };
	int m = 0, n = 0, i = 0, j = 0;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	RecoveryNumber(arr, m, n);
	return 0;
}