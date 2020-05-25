
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

/*
1359. ��Ч�Ŀ��������Ŀ
���� n �ʶ�����ÿ�ʶ�������Ҫ��ݷ���

����ͳ��������Ч�� �ռ�/���� ���е���Ŀ��ȷ���� i ����Ʒ�����ͷ��� delivery(i) ���������ռ����� pickup(i) ֮��

���ڴ𰸿��ܴܺ��뷵�ش𰸶� 10^9 + 7 ȡ��Ľ����



ʾ�� 1��

���룺n = 1
�����1
���ͣ�ֻ��һ������ (P1, D1)����Ʒ 1 �����ͷ���D1������Ʒ 1 ���ռ�����P1����
ʾ�� 2��

���룺n = 2
�����6
���ͣ����п��ܵ����а�����
(P1,P2,D1,D2)��(P1,P2,D2,D1)��(P1,D1,P2,D2)��(P2,P1,D1,D2)��(P2,P1,D2,D1) �� (P2,D2,P1,D1)��
(P1,D2,P2,D1) ��һ����Ч�����У���Ϊ��Ʒ 2 ���ռ�����P2����Ӧ����Ʒ 2 �����ͷ���D2��֮��
ʾ�� 3��

���룺n = 3
�����90
*/

using LL = long long;

class Solution {
private:
	static constexpr int mod = 1000000007;

public:
	int countOrders(int n) {
		if (n == 1) {
			return 1;
		}
		int ans = 1;
		for (int i = 2; i <= n; ++i) {
			ans = (LL)ans * (i * 2 - 1) % mod * i % mod;
		}
		return ans;
	}
};

