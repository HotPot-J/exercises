#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。
返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。

 示例：
 输入：[[10,20],[30,200],[400,50],[30,20]]
 输出：110
 解释：
 第一个人去 A 市，费用为 10。
 第二个人去 A 市，费用为 30。
 第三个人去 B 市，费用为 50。
 第四个人去 B 市，费用为 20。
 最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。
  提示：
  1 <= costs.length <= 100
  costs.length 为偶数
  1 <= costs[i][0], costs[i][1] <= 1000
  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/two-city-scheduling
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
  */
//思路: 贪心   当一个人去a地或者去b地 其代价差值越大即a-b结果越大 那么越应该去两个里边值越小的地方 这样的代价是最小的 
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
