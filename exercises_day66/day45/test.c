#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<limits.h>
/*
53. ��������
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
ʾ��:
����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
*/
//˼·������˼��  ������ֳ���������  �ҵ���ߴ��м�����߼�������� �ҵ����м����ұߵ����� �ڼ�������м�������
//�������е�����   ѡ�������������нϴ�� ���� �������Ŀ��
int my_max(int a, int b){
	return a > b ? a : b;
}
int num_fun(int* nums, int left, int right, int mid){
	int left_num = INT_MIN;
	int right_num = INT_MIN;
	int tmp = 0;
	//���������mid�����������ֵ  С�����Ƕ���mid�ֱ���������ȥ���� �����ĺ� �Ӷ���֤�������� 
	//����-2 1 -3 4  ����mid����-3  ��ô���ұ�����mid�ҵ�������Ϊ-2+1 = 1  ��mid+1�����ҵ�������Ϊ4 ��ô������������Ϊ1+4 = 5  ���ý��ӦΪ1��-2��4������ӵĽ��  
	//���ⲻ��������  ���������������� ������mid��ʼ���� ������ıܿ������ִ������� 
	for (int i = mid; i >=left; i--){  
		tmp += nums[i];
		if (tmp > left_num){
			left_num = tmp;
		}
	}
	tmp = 0;
	for (int i = mid+1; i <=right; i++){
		tmp += nums[i];
		if (tmp > right_num){
			right_num = tmp;
		}
	}
	return left_num + right_num;
}
int _maxSubArray(int* nums, int left, int right){
	if (left == right){
		return nums[left];
	}
	int mid = left+(right-left) / 2; 
	int num_left = _maxSubArray(nums, left, mid);
	int num_right = _maxSubArray(nums, mid + 1, right);
	int Subnum = num_fun(nums, left, right, mid);
	return my_max(Subnum, my_max(num_left , num_right));
}
int maxSubArray(int* nums, int numsSize){
	return _maxSubArray(nums, 0, numsSize - 1);
}
int main(){
	int nums[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int len = sizeof(nums) / sizeof(nums[0]);
	maxSubArray(nums, len);
	return 0;
}