#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
�����������飬��дһ���������������ǵĽ�����

ʾ�� 1:

����: nums1 = [1,2,2,1], nums2 = [2,2]
���: [2]
ʾ�� 2:

����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
���: [9,4]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/intersection-of-two-arrays
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

//˼· 1.������ �ٱȶ� ��ʱΪ����״̬ 2.��p1��p2˭С˭����� ֻ���������п����ҵ���ͬ��
int cmp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int* p1 = nums1, *p2 = nums2;
	int min = nums1Size <= nums2Size ? nums1Size : nums2Size;
	int j = 0;
	int* ret = (int*)malloc(sizeof(int)*min);
	qsort(nums1, nums1Size, sizeof(int), cmp);
	qsort(nums2, nums2Size, sizeof(int), cmp);
	while (p1 < nums1 + nums1Size&&p2 < nums2 + nums2Size){
		if (*p1 == *p2){
			ret[j++] = *p1;
			while (p1 < nums1 + nums1Size - 1 && *p1 == *(p1 + 1)){
				p1++;
			}
			p1++;
			p2++;
		}
		else{
			if (*p1 < *p2){
				p1++;
			}
			else if (*p1>*p2){
				p2++;
			}
		}
	}
	*returnSize = j;
	return ret;
}

/*
����һ������?n ������������?nums?�� һ��Ŀ��ֵ?target���ҳ�?nums?�е�����������ʹ�����ǵĺ���?target?��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�

���磬�������� nums = [-1��2��1��-4], �� target = 1.

�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/3sum-closest
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
//int cmp(const void* a, const void* b){
//	return *(int*)a - *(int*)b;
//}
int threeSumClosest(int* nums, int numsSize, int target){
	int i = 0, p = i+1, q = numsSize - 1;
	int ret = nums[i] + nums[p] + nums[q];
	qsort(nums, numsSize, sizeof(int), cmp);
	while (i < numsSize){
		if (p>q || p == q){
			i++;
			if (i > numsSize - 2){ //С��������
				break;
			}
			p = i + 1;
			q = numsSize-1;
			if (p == q){
				continue;
			}
		}
		//���������͸ı�ret��ֵ
		if (abs(nums[i] + nums[p] + nums[q] - target) < abs(ret - target)){ 
			ret = nums[i] + nums[p] + nums[q];
		}
        if (nums[i] + nums[p] + nums[q]<target){
			p++;
		}
        else if (nums[i] + nums[p] + nums[q]>target){
			q--;
		}
		else{
			return ret;
		}
	}
	return ret;
}
int main(){
	int a[4] = { 0,-4,1,-5 };
	threeSumClosest(a, 4, 0);
	return 0;
}