#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
169. ����Ԫ��
����һ����СΪ n �����飬�ҵ����еĶ���Ԫ�ء�����Ԫ����ָ�������г��ִ������� ? n/2 ? ��Ԫ�ء�
����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�
ʾ�� 1:
����: [3,2,3]
���: 3
ʾ�� 2:
����: [2,2,1,1,1,2,2]
���: 2
*/
//˼· ����ָ��
int cmp(const void* a, const void* b){
	return *(int*)a > *(int*)b;
}
int majorityElement(int* nums, int numsSize){
	int* tmp = nums;
	int flag = 1;
	if (numsSize == 1){
		return *nums;
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	while (tmp < nums + numsSize-1){
		if (flag>numsSize / 2){
			break;
		}
		if (*tmp == *(tmp+ 1)){
			flag++;
		} 
		else{
			if (flag > numsSize / 2){
				break;
			}
			else{
				flag = 1;
			}
		}
		tmp++;
	}
	return *(tmp - 1);
}
/*
������ 16.17. ��������
����һ���������飨�������и��������ҳ��ܺ������������У��������ܺ͡�
ʾ����
���룺 [-2,1,-3,4,-1,2,1,-5,4]
����� 6
���ͣ� ���������� [4,-1,2,1] �ĺ����Ϊ 6��
*/
//˼· ��̬�滮
int maxSubArray(int* nums, int numsSize){
	int *p = nums;
	int tmp = *p;
	int sum = tmp;
	p++;
	while (p < nums + numsSize){
		if (tmp>0){
			tmp += *p;
		}
		else{
			tmp = *p;
		}
		if(tmp>sum){
			sum = tmp;
		}
		p++;
	}
	return sum;
}