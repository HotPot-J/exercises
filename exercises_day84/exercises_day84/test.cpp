#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
1399. 统计最大组的数目
给你一个整数 n 。请你先求出从 1 到 n 的每个整数 10 进制表示下的数位和（每一位上的数字相加），然后把数位和相等的数字放到同一个组中。

请你统计每个组中的数字数目，并返回数字数目并列最多的组有多少个。



示例 1：

输入：n = 13
输出：4
解释：总共有 9 个组，将 1 到 13 按数位求和后这些组分别是：
[1,10]，[2,11]，[3,12]，[4,13]，[5]，[6]，[7]，[8]，[9]。总共有 4 个组拥有的数字并列最多。
示例 2：

输入：n = 2
输出：2
解释：总共有 2 个大小为 1 的组 [1]，[2]。
示例 3：

输入：n = 15
输出：6
示例 4：

输入：n = 24
输出：5


提示：

1 <= n <= 10^4
*/

class Solution {
public:
	int countLargestGroup(int n) {
		unordered_map<int, int> hashMap;
		int maxValue = 0;
		for (int i = 1; i <= n; ++i) {
			int key = 0, i0 = i;
			while (i0) {
				key += i0 % 10;
				i0 /= 10;
			}
			++hashMap[key];
			maxValue = max(maxValue, hashMap[key]);
		}
		int count = 0;
		for (auto& kvpair : hashMap) {
			if (kvpair.second == maxValue) {
				++count;
			}
		}
		return count;
	}
};

/*
1351. 统计有序矩阵中的负数
给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。

请你统计并返回 grid 中 负数 的数目。



示例 1：

输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
输出：8
解释：矩阵中共有 8 个负数。
示例 2：

输入：grid = [[3,2],[1,0]]
输出：0
示例 3：

输入：grid = [[1,-1],[-1,-1]]
输出：3
示例 4：

输入：grid = [[-1]]
输出：1


提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 100
*/

class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		int num = 0;
		for (auto x : grid){
			for (auto y : x){
				if (y<0) num++;
			}
		}
		return num;
	}
};

