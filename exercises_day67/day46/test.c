#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
932. 漂亮数组
对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：
对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。
那么数组 A 是漂亮数组。
给定 N，返回任意漂亮数组 A（保证存在一个）。
示例 1：
输入：4
输出：[2,1,4,3]
示例 2：
输入：5
输出：[3,1,2,5,4]
*/
/**
* Note: The returned array must be malloced, assume caller calls free().
*/

/*
思路 ：递归 分治
   这个题技巧性很强，首先 该题的漂亮公式是需要数组满足：当i<j  i<k<j的时候  2*A[k]!=A[i]*A[j]
   观察公式可只 式子左边为偶数 右边为奇数 所以若要该式恒成立 我们将数组分为左右两半，左边全放奇数 而右边
   全放偶数即可
   N = 1 : 1
   N = 2 : 1 2
   N = 3 : 1 3 2
   N = 4 : 1 3 2 4
   N = 5 : 1 3 5 2 4
   N = 6 : 1 5 3 2 6 4   奇数部分：N3*2-1  偶数部分N3*2
   N = 7 : 1 5 3 7 2 6 4   奇数部分： N4*2-1 偶数部分N3*2
   N = 8 : 1 5 3 7 2 6 4 8 奇数部分：N4*2-1 偶数部分N4*2
   可得到递推公式: 当N>=6  奇数部分：N（(N+1)/2）*2-1  偶数部分N（N/2）*2
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