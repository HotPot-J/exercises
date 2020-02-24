#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
泰波那契序列?Tn?定义如下：?

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0?的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数?n，请返回第 n 个泰波那契数?Tn 的值。

?

 示例 1：

 输入：n = 4
 输出：4
 解释：
 T_3 = 0 + 1 + 1 = 2
 T_4 = 1 + 1 + 2 = 4

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/n-th-tribonacci-number
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
1.动态规划 每次保存该次结果 如果递归到n-1 而dp[n-1]之前已经被计算 直接用即可避免重复计算
*/
int res;
int dp[38] = { 0 };
int tribonacci(int n){
	if (dp[n] != 0){
		return dp[n];
	}
	if (n == 0){
		return 0;
	}
	else if (n == 1 || n == 2){
		return 1;
	}
	else{
		res = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
		dp[n] = res;
		return res;
	}
}
int main(){
	tribonacci(4);
	return 0;
}