#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*K 次取反后最大化的数组和
给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个个索引 i 并将 A[i] 替换为 - A[i]，然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。）
以这种方式修改数组后，返回数组可能的最大和。

示例 1：
输入：A = [4, 2, 3], K = 1
输出：5
解释：选择索引(1, ) ，然后 A 变为[4, -2, 3]。
示例 2：
输入：A = [3, -1, 0, 2], K = 3
输出：6
解释：选择索引(1, 2, 2) ，然后 A 变为[3, 1, 0, 2]。
示例 3：
输入：A = [2, -3, -1, 5, -4], K = 2
输出：13
解释：选择索引(1, 4) ，然后 A 变为[2, 3, -1, 5, 4]。

提示：
1 <= A.length <= 10000
1 <= K <= 10000
- 100 <= A[i] <= 100
*/

//思路：贪心算法  尽可能把最大的负数变为正数  
//若将负数都变为正数还有剩余次数  两种情况: 
//次数剩余为偶数 直接返回当前数组之和
//若为奇数选择当前最小的正数变为负数
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
		//该数组全为正数
		tmp = K % 2;
		if (tmp){
			//说明必须有一个数设置成负数，则设最小的为负数
			A[0] = -A[0];
		}
	}
	else if (flag == A + ASize){
		//该数组全为负数
		while (K&&i<ASize){  //将最小的负数一次改为正数
			A[i] = -A[i++];
			K--;
		}
		if (K){
			//K有剩余
			tmp = K % 2;
			if (tmp){
				A[ASize - 1] = -A[ASize - 1];
			}
		}
	}
	else{
		//有正有负
		while (A[i] < 0){
			A[i] = -A[i++];
			K--;
		}
		if (K){
			//还有剩余的K
			tmp = K % 2;
			if (tmp){
				//必须使一个正数变为负数 则将最小的正数变为负数
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