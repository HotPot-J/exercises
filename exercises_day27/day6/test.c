#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

 

 示例 1：

 输入：[-4,-1,0,3,10]
 输出：[0,1,9,16,100]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一 ：这是最易想到的方法 平方后排序   
int cmp(const void *a, const void *b){
	return (*(int *)a - *(int *)b);//升序
}
int* sortedSquares1(int* A, int ASize, int* returnSize){
	int i = 0;
	returnSize = (int*)malloc(sizeof(int)*ASize);
	for (i = 0; i<ASize; i++){
		returnSize[i] = A[i] * A[i];
	}
	qsort(returnSize, ASize, sizeof(A[0]), cmp);
	return returnSize;
}

//方法二：
//这种思路是： 既然是升序的 就分为负数部分和非负数部分 负数平方后逆序/正数平方后即为升序
//使用双指针的技巧 将其放入malloc 的数组中
int* sortedSquares(int* A, int ASize, int* returnSize){
	int i = 0, j = 0, t = 0;
	returnSize = (int*)malloc(sizeof(A[0])*ASize);
		while (A[j] < 0){
			if (j>ASize - 1){
				break;
			}
			A[j] = -1*A[j];
			j++;
		}
		i = j - 1;
		while (i >= 0 && j < ASize){
			if (A[i] < A[j]){
				returnSize[t++] = A[i]*A[i];
				i--;
			}
			else{
				returnSize[t++] = A[j]*A[j];
				j++;
			}
		}
		while (i >= 0){
			returnSize[t++] = A[i]*A[i];
			i--;
		}
		while (j < ASize){
			returnSize[t++] = A[j] * A[j];
			j++;
		}
		return returnSize;
}

int main(){
	//int arr[5] = { -4, -1, 0, 3, 10 };
	//int* returnSize = NULL;
	//returnSize = sortedSquares(arr, 5, returnSize);

	return 0;
}