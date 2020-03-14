#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
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
/*˼·�����ε�˼�� ��aΪ����Ԫ��ʱ��������������� n/2    ��ô���Ϊ������������������һ���Ķ���Ԫ��
 ֤���� ����a�Ȳ���l���������г��ȣ���������Ҳ����r���������еĳ��ȣ�����ôa��l�г��ֵĴ�������l/2
��r�г��ֵĴ�������r/2��   ��ô l/2 + r/2 < n/2 ��Ȼ�໥ì�� �����������۳���

���ǽ�����ݹ�ָ����������������  ֱ������Ϊ1�����Ԫ�ؾ�Ϊ�䱾�� ��ͨ������ȥѡ���������߸����϶�Ķ���Ԫ��
*/
int Fun_count(int* nums, int num, int l, int r){
	int count = 0;
	for (int i = l; i <= r; i++){
		if (nums[i] == num){
			count++;
		}
	}
	return count;
}
int _majorityElement(int* nums, int l, int r){
	//�ݹ���ֹ���� ��Ԫ�ظ���Ϊ1ʱ�����ظ�Ԫ����ֵ 
	if (l == r){
		return nums[l];
	}
	//�ݹ��۰�
	int mid = l + (r-l) / 2;
	int left = _majorityElement(nums, l, mid);
	int right = _majorityElement(nums, mid + 1, r);
	//�Ƚ���������˭�Ķ�λ�������� ���ظ������Ԫ��
	if (left == right){
		//��������������һ���򷵻ظ�Ԫ�ؼ���
		return left;
	}
       //�������һ�¸��� ���жԱ�	
		int countl = Fun_count(nums, left, l, r);
		int countr = Fun_count(nums, right, l, r);
		return countl > countr ? left : right;
}
int majorityElement(int* nums, int numsSize){
	return _majorityElement(nums, 0, numsSize - 1);
}
int main(){
	int nums[] = { 3, 2, 3 };
	int len = sizeof(nums) / sizeof(nums[0]);
	majorityElement(nums, len);
	return 0;
}