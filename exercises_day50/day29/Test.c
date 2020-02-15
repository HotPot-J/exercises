#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
�����������飬��дһ���������������ǵĽ�����

ʾ�� 1:

����: nums1 = [1,2,2,1], nums2 = [2,2]
���: [2,2]
ʾ�� 2:

����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
���: [4,9]
˵����
��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ֵĴ���һ�¡�
���ǿ��Բ�������������˳��
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
//˼·�� ������ ����˫ָ����� ��flag����¼����ͬ�ĸ����Ƿ����
int cmp(const void*a, const void*b){
	return *(int*)a - *(int*)b;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int*p1 = nums1, *p2 = nums2;
	int flag1 = 0, flag2 = 0, tmp = 0,min = 0;
	int size = nums1Size > nums2Size ? nums1Size : nums2Size;
	int* ret = (int*)malloc(sizeof(int)*size);
	qsort(nums1, nums1Size, sizeof(int), cmp);
	qsort(nums2, nums2Size, sizeof(int), cmp);
	size = 0;
	while (p1 < nums1 + nums1Size&&p2 < nums2 + nums2Size){
		if (*p1 == *p2){
			tmp = *p1;
			while (p1 < nums1 + nums1Size&&*p1 == tmp){
				flag1++;
				p1++;
			}
			while (p2 < nums2 + nums2Size&&*p2 == tmp){
				flag2++;
				p2++;
			}
			if (flag1 == flag2){
				while (flag1--){
					ret[size++] = tmp;
				}
			}
			else{
				min = flag1<flag2 ? flag1 : flag2;
				while (min--){
					ret[size++] = tmp;
				}
			}
			flag1 = flag2 = 0;
		}
		else if (*p1>*p2){
			p2++;
		}
		else{
			p1++;
		}
	}
	*returnSize = size;
	return ret;
}
int main(){
	unsigned int a[4] = { -2147483648, 1, 2, 3 };
	unsigned int b[3] = { 1, -2147483648, -2147483648 };
	int size = 0;
	unsigned int *ret = intersect(a, 4, b, 3, &size);
	free(ret);
	
	return 0;
}
