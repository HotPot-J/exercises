#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
973. 最接近原点的 K 个点
我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。
（这里，平面上两点之间的距离是欧几里德距离。）
你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。
例 1：
输入：points = [[1,3],[-2,2]], K = 1
输出：[[-2,2]]
解释：
(1, 3) 和原点之间的距离为 sqrt(10)，
(-2, 2) 和原点之间的距离为 sqrt(8)，
由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
示例 2：
输入：points = [[3,3],[5,-1],[-2,4]], K = 2
输出：[[3,3],[-2,4]]
（答案 [[-2,4],[3,3]] 也会被接受。）
*/
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
//思路：进行升序排序 将前K个元素放入结果中 时间复杂度O（n*logn）
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