#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
923. ����֮�͵Ķ��ֿ���
����һ���������� A���Լ�һ������ target ��ΪĿ��ֵ���������� i < j < k �� A[i] + A[j] + A[k] == target ��Ԫ�� i, j, k ��������

���ڽ����ǳ����뷵�� ������� 10^9 + 7 ��������



ʾ�� 1��

���룺A = [1,1,2,2,3,3,4,4,5,5], target = 8
�����20
���ͣ�
��ֵö�٣�A[i]��A[j]��A[k]����
(1, 2, 5) ���� 8 �Σ�
(1, 3, 4) ���� 8 �Σ�
(2, 2, 4) ���� 2 �Σ�
(2, 3, 3) ���� 2 �Ρ�
ʾ�� 2��

���룺A = [1,1,2,2,2,2], target = 5
�����12
���ͣ�
A[i] = 1��A[j] = A[k] = 2 ���� 12 �Σ�
���Ǵ� [1,1] ��ѡ��һ�� 1���� 2 �������
�� [2,2,2,2] ��ѡ������ 2���� 6 �������


��ʾ��

3 <= A.length <= 3000
0 <= A[i] <= 100
0 <= target <= 300
*/


class Solution {
public:
	const long M = 1e9 + 7;
	int threeSumMulti(vector<int>& A, int target) {
		sort(A.begin(), A.end());
		int N = A.size();
		long res = 0;
		for (int i = 0; i < N - 2; ++i) {
			int t = target - A[i];
			if (t < 2 * A[i]) break;
			int l = i + 1;
			int r = N - 1;
			while (A[l] < A[r]) {
				if (A[l] + A[r] > t) {
					--r;
				}
				else if (A[l] + A[r] < t) {
					++l;
				}
				else {
					int tl = l;
					int tr = r;
					while (A[++l] == A[tl]);
					while (A[--r] == A[tr]);
					res += (l - tl) * (tr - r);
					res %= M;
				}
			}
			if (A[l] == A[r] && A[l] + A[r] == t) {
				int d = r - l + 1;
				res += d * (d - 1) / 2;
				res %= M;
			}
		}
		return res;
	}
};
