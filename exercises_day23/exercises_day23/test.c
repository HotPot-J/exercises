#define _CRT_SECURE_NO_WARNINGS 1
/*
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

����Լ������������ظ�Ԫ�ء�
*/
int searchInsert(int* nums, int numsSize, int target){
	int i = 0;
	//���targetΪ�����������/��С������ ��Ӧ���뵽��������/��ǰ 
	int flag = 0;
	if (target > nums[0]){
		flag = numsSize;
	}
	for (i = 0; i < numsSize; i++){
		if (nums[i] == target){
			return i;
		}
		if (i + 1 <= numsSize - 1){//��ֹԽ�����
			if (target >= nums[i] && target <= nums[i + 1]){
				flag = i + 1;
			}
		}
	}
	return flag;
}