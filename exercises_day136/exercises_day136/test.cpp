#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*
70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。
示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
*/

/*
 思路一：递归 回溯 (类似于求数字之和 不过不用设置搜索起点)
 （该思路会超时）
*/

class Solution1 {
public:
	void dfs(int aim,int& res){
		if (aim==0){
			++res;
			return;
		}
		for (int i = 1; i <= 2; ++i){
			if (aim - i < 0){
				break;
			}
			dfs(aim - i, res);
		}
	}
	int climbStairs(int n) {
		int res = 0;
		dfs(n, res);
		cout << res << endl;
		return res;
	}
};
//int main(){
//	Solution a;
//	a.climbStairs(44);
//	return 0;
//}

/*
思路二：动态规划：
	f(n) = f(n-1)+f(n-2)  
	f(0) =1 f(1) = 1  f(2) = 2 f(3) = 3
*/

class Solution {
public:
	int climbStairs(int n) {
		int a = 0, b = 0, c = 1;
		for (int i = 0; i < n; ++i){
			a = b;
			b = c;
			c = a + b;
		}
		return c;
	}
};

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
示例 2：
输入：3
输出：false
解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。
提示：

1 <= N <= 1000
*/

/*
2:  ai:1  t
3: ai:1 n = 2 b:1 n =1  f
4: a:1 n = 3 b 1 n = 2  a:1 n = 1 t
5: a:1 n =4 b:2 n = 2 a:1 n =1 f
6: t
通过推理：最终当n = 2的时刻是谁，那么该人必胜

	当n为奇数，其约数位奇数，那么奇数-奇数=偶数 那么下一位必胜
	当n位偶数 其约束为偶数 偶数减去偶数 那么当前面对的永远是偶数 一直到2 所以当前必胜
*/

class Solution {
public:
	bool divisorGame(int N) {
		if (N % 2 == 0){
			return true;
		}
		else{
			return false;
		}
	}
};