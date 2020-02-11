#define _CRT_SECURE_NO_WARNINGS 1
/*
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�

ʾ��?1:

�������� nums = [1,1,2],

����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
ʾ��?2:

���� nums = [0,0,1,1,1,2,2,3,3,4],

����Ӧ�÷����µĳ��� 5, ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

//˼·������һǰһ��˫ָ��  ����ͬ��topָ�벻�� ��tailָ�뵱ǰ��ֵ����topָ����ָ��ĵ�ַ�ռ��ֵ tail++
//                          ����ͬ��top++     ��tailָ�뵱ǰ��ֵ����topָ����ָ��ĵ�ַ�ռ��ֵ tail++
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize){
	int* top = nums;
	int* tail = nums + 1;
	int i = 0, size = 1;
	if (numsSize == 0){
		return 0;
	}
	while (tail < nums + numsSize){
		if (*top == *tail){//���
			*top = *tail;
			tail++;
		}
		else{//�����
			top++;
			size++;
			*top = *tail;
			tail++;
		}
	}
	return size;
}
/*
ɾ���ظ����ֵĽ��װ汾 ��ʹÿ��Ԫ������������
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ�����������Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�

ʾ��?1:

���� nums = [1,1,1,2,2,3],

����Ӧ�����³��� length = 5, ����ԭ�����ǰ���Ԫ�ر��޸�Ϊ 1, 1, 2, 2, 3 ��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

//˼·: ���ø��Ƿ����Ƕ�������� top��Զָ����Ҫ���ǵ�λ�� tail�������ֱ��tail�������������飨�е����ָ�����˼--����
int removeDuplicatesPlus(int* nums, int numsSize){
	int* top = nums+1;
	int* tail = nums+1;
	int size = 1, count = 1;
	while (tail < nums + numsSize){
		if (*tail == *(tail - 1)){
			count++;
		}
		else{
			count = 1;
		}
		if (count <= 2){
			*top = *tail;
			top++;
			size++;
		}
		tail++;
	}
	return size;
}
int main(){
	int a[9] = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
	removeDuplicatesPlus(a, 9);
	return 0;
}