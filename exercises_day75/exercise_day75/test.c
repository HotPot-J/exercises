#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;
/*
18. ����֮��
����һ������ n ������������ nums ��һ��Ŀ��ֵ target���ж� nums ���Ƿ�����ĸ�Ԫ�� a��b��c �� d ��ʹ�� a + b + c + d ��ֵ�� target ��ȣ��ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺

���в����԰����ظ�����Ԫ�顣

ʾ����

�������� nums = [1, 0, -1, 0, -2, 2]���� target = 0��

����Ҫ�����Ԫ�鼯��Ϊ��
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/

class Solution{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > res;
		if (nums.size()<4)
			return res;
		int a, b, c, d, _size = nums.size();
		for (a = 0; a <= _size - 4; a++){
			if (a>0 && nums[a] == nums[a - 1]) continue;      //ȷ��nums[a] �ı���
			for (b = a + 1; b <= _size - 3; b++){
				if (b>a + 1 && nums[b] == nums[b - 1])continue;   //ȷ��nums[b] �ı���
				c = b + 1, d = _size - 1;
				while (c<d){
					if (nums[a] + nums[b] + nums[c] + nums[d]<target)
						c++;
					else if (nums[a] + nums[b] + nums[c] + nums[d]>target)
						d--;
					else{
						res.push_back({ nums[a], nums[b], nums[c], nums[d] });
						while (c<d&&nums[c + 1] == nums[c])      //ȷ��nums[c] �ı���
							c++;
						while (c<d&&nums[d - 1] == nums[d])      //ȷ��nums[d] �ı���
							d--;
						c++;
						d--;
					}
				}
			}
		}
		return res;
	}
};
