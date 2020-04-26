#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
/*
1025. 除数博弈
爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。
最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：
选出任一 x，满足 0 < x < N 且 N % x == 0 。
用 N - x 替换黑板上的数字 N 。
如果玩家无法执行这些操作，就会输掉游戏。
只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 false。假设两个玩家都以最佳状态参与游戏。
示例 1：

输入：2
输出：true
解释：爱丽丝选择 1，鲍勃无法进行操作。
示 2：
输入：3
输出：false
解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作
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
	给定一个整数数组 ?nums，求出数组从索引?i?到?j??(i?≤?j) 范围内元素的总和，包含?i,? j?两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:

你可以假设数组不可变。
会多次调用?sumRange?方法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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