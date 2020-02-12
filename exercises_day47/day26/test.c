#define _CRT_SECURE_NO_WARNINGS 1
/*
����һ�����ǵݼ�˳��������������� A������ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳������
 ʾ�� 1��

 ���룺[-4,-1,0,3,10]
 �����[0,1,9,16,100]
 ʾ�� 2��

 ���룺[-7,-3,2,3,11]
 �����[4,9,9,49,121]
 ?

  ��ʾ��

  1 <= A.length <= 10000
  -10000 <= A[i] <= 10000
  A?�Ѱ��ǵݼ�˳������

  ��Դ�����ۣ�LeetCode��
  ���ӣ�https://leetcode-cn.com/problems/squares-of-a-sorted-array
  ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include<stdio.h>
#include<stdlib.h>
//˼·���ȱ����������ֲ�����ƽ��  ����ƽ����Ϊ���� P1��¼��ǰ���һ������λ��  Ȼ������ͬ�ķ��������������� ��������Ϊ
//���� P2��¼�������ֵĵ�һ��λ��  ��ʹ�ù鲢����p1��ǰ����  p2������ ʱ�临�Ӷ� O(2n) 
int* sortedSquares(int* A, int ASize, int* returnSize){
	int *ret = (int*)malloc(ASize*sizeof(int));
	int* p1 = A, *p2 = NULL;
	int i = 0;
	while (p1 < A + ASize){//��������
		if (*p1 < 0){
			*p1 *= *p1;
			p1++;
		}
		else{
			p2 = p1;
			break;
		}
	}
	p1 = p1 - 1;
	while (p2&&p2 < A + ASize){//��p2Ϊ����˵��û������ ��ֹ���ʿ�ָ��
		*p2 *= *p2;
		p2++;
	}
	p2 = p1 + 1;
	//�鲢����
	while (p1 >= A&&p2 < A + ASize){
		if (*p1 < *p2){
			ret[i++] = *p1;
			p1--;
		}
		else{
			ret[i++] = *p2;
			p2++;
		}
	}
	//ʣ�µ�ֱ�ӷŽ�������鼴��
	while (p1 >= A){
		ret[i++] = *p1;
		p1--;
	}
	while (p2&&p2 < A + ASize){
		ret[i++] = *p2;
		p2++;
	}
	*returnSize = ASize;
	return ret;
}

/*
����һ������ n ������������?nums���ж�?nums?���Ƿ��������Ԫ�� a��b��c ��ʹ��?a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣
ע�⣺���в����԰����ظ�����Ԫ�顣
 ʾ����
 �������� nums = [-1, 0, 1, 2, -1, -4]��

 ����Ҫ�����Ԫ�鼯��Ϊ��
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 ��Դ�����ۣ�LeetCode��
 ���ӣ�https://leetcode-cn.com/problems/3sum
 ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

//˼· ���Ƚ���������  ����i�̶�һ�����ֿ�ʼ���� �����̶���һ������  left��rightΪ��������������ȥѰ�������i��ӵ�����
//����left��i��һ���������ֿ�ʼ���� ����rightָ��������� ����С��Χ ֱ���������� ��left>right i++ right = Asize-1
//left = i+1 Ѱ���µĴ�
int cmp(const void*a, const void*b){
	return *(int*)a - *(int*)b;         //����
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	//����
	if (numsSize < 3){
		*returnSize = 0;
		return NULL;
	}
	//���ٷ��صĶ�ά����ռ�
	int** ret = (int**)malloc(50000 * sizeof(int*));
	*returnColumnSizes = (int*)malloc(50000 * sizeof(int));
	int i = 0, left = 1, right = numsSize - 1;
	int j = 0;
	//����
	qsort(nums, numsSize, sizeof(int), cmp);
	//�������� Ѱ�ҽ��
	while (i < numsSize - 1){
		if (left>right || left == right){
			//û�ҵ� i������ ���³�ʼ��left��right��λ�� Ѱ���µ���ȷ���
			while (nums[i] == nums[i + 1]){ //��ֹ�ظ� �����һ�����ֺ͵�ǰ����������� ֱ�������
				i++;
				if (i >= numsSize-1){
					break;
				}
			}
			i++;
			left = i + 1, right = numsSize - 1;
		}
		else if (nums[i] + nums[left] + nums[right] == 0){//�������� ������������
			ret[j] = (int*)malloc(sizeof(int)* 3);
			ret[j][0] = nums[i];
			ret[j][1] = nums[left];
			ret[j][2] = nums[right];
			(*returnColumnSizes)[j] = 3;
			j++;
			while (left<right && nums[left] == nums[left + 1]) left++; // ȥ��
			while (left<right && nums[right] == nums[right - 1]) right--; // ȥ��
			left++;
			right--;
		}
		else if (nums[i] + nums[left] + nums[right] < 0){//��С��0 ��left������������֮�� ��С��Χ
			left++;
		}
		else if (nums[i] + nums[left] + nums[right] > 0){
			right--;
		}
	}
	*returnSize = j;
	return ret;
}
int main(){
	int a[5] = { -2, 0, 0, 2, 2};
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	free(threeSum(a, 5, &returnSize, &returnColumnSizes));
	return 0;
}