#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*

*/
int findUnsortedSubarray(int* nums, int numsSize){
	/*
	˼·������ѡ�������˼��  �ж�nums[i]������״̬���Ƿ������λ�� ������ Ӧ�����ĸ�λ��  l��¼�������Ҫ������λ��
	r��¼�����ұ���Ҫ������λ��  ���ս����Ϊr-l+1
	*/
	int i = 0, j = 0, l = numsSize, r = 0;//l �� r������������ұ߽� һ��ʼl=n r =0������һ��ʼĬ����Ϊ����
	for (i = 0; i < numsSize - 1; i++){
		for (j = i + 1; j<numsSize; j++){
			if (nums[j]<nums[i]){
				l = i < l ? i : l; //����i��l��С��ֵ ��Ϊ����߽�
				r = j > r ? j : r;//����j��r�нϴ��ֵ ��Ϊ���ұ߽�
			} 
		}
	}
	return r - l < 0 ? 0 : r - l + 1;
}
int main(){
	int a[] = { 1,2,3,4 };
	findUnsortedSubarray(a, 4);
	
	return 0;
}