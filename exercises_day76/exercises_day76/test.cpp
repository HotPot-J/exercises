#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
923. 三数之和的多种可能
给定一个整数数组 A，以及一个整数 target 作为目标值，返回满足 i < j < k 且 A[i] + A[j] + A[k] == target 的元组 i, j, k 的数量。

由于结果会非常大，请返回 结果除以 10^9 + 7 的余数。



示例 1：

输入：A = [1,1,2,2,3,3,4,4,5,5], target = 8
输出：20
解释：
按值枚举（A[i]，A[j]，A[k]）：
(1, 2, 5) 出现 8 次；
(1, 3, 4) 出现 8 次；
(2, 2, 4) 出现 2 次；
(2, 3, 3) 出现 2 次。
示例 2：

输入：A = [1,1,2,2,2,2], target = 5
输出：12
解释：
A[i] = 1，A[j] = A[k] = 2 出现 12 次：
我们从 [1,1] 中选择一个 1，有 2 种情况，
从 [2,2,2,2] 中选出两个 2，有 6 种情况。


提示：

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
