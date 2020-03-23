#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
53. ��������
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
ʾ��:
����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
*/
/*˼·��֮ǰһ�����˷��η���Ѱ�� ��Ȼ�����߳�  �����ѧϰ��̬�滮�� ���Գ����ö�̬�滮ʵ�֣�
  �������Ƕ���һ��d[i]�������Ե�i���±��β����������к� �Է���ȥ�жϵ�ǰ����Ӧ�ü��뻹��Ӧ������Ϊ����
  ����d[i-1]+nums[i]>nums[i] ����nums[i]���� ��֮����nums[i]������i��β���������к�
  ���ѵõ�״̬ת�Ʒ��̣�d[i] = max(d[i-1]+nums[i],nums[i])
  
  Ϊ�˽�ʡ�ռ� ���ǿ���ԭ����nums[i]�����浱ǰ��������к�
  ��״̬ת�Ʒ��� ���ǿ�֪��i = 0ʱ d[i] = 0;

  ʱ�临�Ӷ�ΪO(n) �ռ临�Ӷ�O(1)
*/
int my_max(int a, int b){
	return a > b ? a : b;
}
int maxSubArray(int* nums, int numsSize){
	if (numsSize == 1){
		return nums[0];
	}
	int max = nums[0];
	for (int i = 1; i < numsSize; i++){
		nums[i] = my_max(nums[i - 1] + nums[i], nums[i]);
		if (nums[i]>max){
			//�������������к�
			max = nums[i];
		}
	}
	return max;
}