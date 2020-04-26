#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
/*
1025. ��������
����˿�ͱ���һ������Ϸ�����������ж�������˿���ֿ��֡�
������ڰ�����һ������ N ����ÿ����ҵĻغϣ������Ҫִ�����²�����
ѡ����һ x������ 0 < x < N �� N % x == 0 ��
�� N - x �滻�ڰ��ϵ����� N ��
�������޷�ִ����Щ�������ͻ������Ϸ��
ֻ���ڰ���˿����Ϸ��ȡ��ʤ��ʱ�ŷ��� True�����򷵻� false������������Ҷ������״̬������Ϸ��
ʾ�� 1��

���룺2
�����true
���ͣ�����˿ѡ�� 1�������޷����в�����
ʾ 2��
���룺3
�����false
���ͣ�����˿ѡ�� 1������Ҳѡ�� 1��Ȼ����˿�޷����в���
*/
class Solution {
public:

	bool divisorGame(int N) {
		if (N == 1) return false;
		int dp[N + 1];
		memset(dp, 0, sizeof(dp));
		dp[2] = 1;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j < i / 2; j++){
				if (i % j == 0 && dp[i - j] == 0){
					dp[i] = 1;
					break;
				}
			}
		}
		return dp[N] == 1;
	}

	/*
	����һ���������� ?nums��������������?i?��?j??(i?��?j) ��Χ��Ԫ�ص��ܺͣ�����?i,? j?���㡣

ʾ����

���� nums = [-2, 0, 3, -5, 2, -1]����ͺ���Ϊ sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
˵��:

����Լ������鲻�ɱ䡣
���ε���?sumRange?������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/range-sum-query-immutable
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
	*/
	class NumArray {
	public:
		NumArray(vector<int>& nums) : m_nums(nums)
		{
			partial_sum(m_nums.begin(), m_nums.end(), back_inserter(m_partial));
		}

		int sumRange(int i, int j)
		{
			return m_partial[j] - m_partial[i] + m_nums[i];
		}

	private:
		vector<int> m_nums;
		vector<int> m_partial;
	};