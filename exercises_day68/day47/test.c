#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
973. ��ӽ�ԭ��� K ����
������һ����ƽ���ϵĵ���ɵ��б� points����Ҫ�����ҳ� K ������ԭ�� (0, 0) ����ĵ㡣
�����ƽ��������֮��ľ�����ŷ����¾��롣��
����԰��κ�˳�򷵻ش𰸡����˵������˳��֮�⣬��ȷ����Ψһ�ġ�
�� 1��
���룺points = [[1,3],[-2,2]], K = 1
�����[[-2,2]]
���ͣ�
(1, 3) ��ԭ��֮��ľ���Ϊ sqrt(10)��
(-2, 2) ��ԭ��֮��ľ���Ϊ sqrt(8)��
���� sqrt(8) < sqrt(10)��(-2, 2) ��ԭ�������
����ֻ��Ҫ����ԭ������� K = 1 ���㣬���Դ𰸾��� [[-2,2]]��
ʾ�� 2��
���룺points = [[3,3],[5,-1],[-2,4]], K = 2
�����[[3,3],[-2,4]]
���� [[-2,4],[3,3]] Ҳ�ᱻ���ܡ���
*/
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
//˼·�������������� ��ǰK��Ԫ�ط������� ʱ�临�Ӷ�O��n*logn��
int cmp(const void* a, const void*b){
	int** s = (int**)a;
	int** t = (int**)b;
	return (*s)[0] * (*s[0]) + (*s)[1] * (*s)[1] > (*t)[0] * (*t)[0] + (*t)[1] * (*t)[1];
}
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
	int** ret = (int**)malloc(sizeof(int*)*K);
	*returnSize = K;
	*returnColumnSizes = (int*)malloc(sizeof(int)*K);
	qsort(points, pointsSize, sizeof(int)* 2, cmp);
	for (int i = 0; i < K; i++){
		ret[i] = (int *)malloc(sizeof(int)* 2);
		ret[i][0] = points[i][0];
		ret[i][1] = points[i][1];
		(returnColumnSizes)[i] = 2;
	}
	return ret;
}