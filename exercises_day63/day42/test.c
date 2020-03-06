#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
��˾�ƻ����� 2N �ˡ��� i �˷��� A �еķ���Ϊ costs[i][0]������ B �еķ���Ϊ costs[i][1]��
���ؽ�ÿ���˶��ɵ�ĳ�����е���ͷ��ã�Ҫ��ÿ�����ж��� N �˵ִ

 ʾ����
 ���룺[[10,20],[30,200],[400,50],[30,20]]
 �����110
 ���ͣ�
 ��һ����ȥ A �У�����Ϊ 10��
 �ڶ�����ȥ A �У�����Ϊ 30��
 ��������ȥ B �У�����Ϊ 50��
 ���ĸ���ȥ B �У�����Ϊ 20��
 ����ܷ���Ϊ 10 + 30 + 50 + 20 = 110��ÿ�����ж���һ����������ԡ�
  ��ʾ��
  1 <= costs.length <= 100
  costs.length Ϊż��
  1 <= costs[i][0], costs[i][1] <= 1000
  ��Դ�����ۣ�LeetCode��
  ���ӣ�https://leetcode-cn.com/problems/two-city-scheduling
  ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
  */
//˼·: ̰��   ��һ����ȥa�ػ���ȥb�� ����۲�ֵԽ��a-b���Խ�� ��ôԽӦ��ȥ�������ֵԽС�ĵط� �����Ĵ�������С�� 
int cmp(const void*a, const void*b){
	int *ap = *(int **)a;
	int *bp = *(int **)b;
	int t1 = ap[0] - ap[1];
	int t2 = bp[0] - bp[1];
	return t1 > t2;
}
int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
	qsort(costs, costsSize, sizeof(int**), cmp);
	int sum = 0;
	for (int i = 0; i<costsSize; i++){
		if (i<costsSize / 2){
			sum += costs[i][0];
		}
		else{
			sum += costs[i][1];
		}
	}
	return sum;
}
