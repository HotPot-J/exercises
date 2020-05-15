#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
446. �Ȳ����л��� II - ������
���һ����������������Ԫ�أ�����������������Ԫ��֮����ͬ����Ƹ�����Ϊ�Ȳ����С�

���磬��������Ϊ�Ȳ�����:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
�������в��ǵȲ����С�

1, 1, 2, 5, 7


���� A ���� N �������������� 0 ��ʼ�������������н�����Ϊ�������� (P0, P1, ..., Pk)��P �� Q ������������ 0 �� P0 < P1 < ... < Pk < N��



������� A[P0]��A[P1]��...��A[Pk-1]��A[Pk] �ǵȲ�ģ���ô���� A �������� (P0��P1������PK) ��Ϊ�Ȳ����С�ֵ��ע����ǣ�����ζ�� k �� 2��

����Ҫ�������� A �����еȲ������еĸ�����

������� N ��������ÿ���������� -231 �� 231-1 ֮�䣬���� 0 �� N �� 1000����֤���С�� 231-1��



ʾ����



���룺[2, 4, 6, 8, 10]

�����7

���ͣ�
���еĵȲ�������Ϊ��
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
*/

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		vector<unordered_map<long long, int>> dp(A.size());
		long long result = 0;
		for (int i = 1; i < A.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				long long dlt = (long long)A[i] - (long long)A[j];
				dp[i][dlt] ++;
				if (dp[j].count(dlt)) {
					result += dp[j][dlt];
					dp[i][dlt] += dp[j][dlt];
				}
			}
		}
		return result;
	}
};

