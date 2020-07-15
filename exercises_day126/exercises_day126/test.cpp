#define _CRT_SECURE_NO_WARNINGS 1

/*
1、最长公共子串
链接：https://www.nowcoder.com/questionTerminal/02e7cc263f8a49e8b1e1dc9c116f7602
来源：牛客网
对于两个字符串，请设计一个时间复杂度为O(m*n)的算法(这里的m和n为两串的长度)，
求出两串的最长公共子串的长度。这里的最长公共子串的定义为两个序列U1,U2,..Un和
V1,V2,...Vn，其中Ui + 1 == Ui+1,Vi + 1 == Vi+1，同时Ui == Vi。
给定两个字符串A和B，同时给定两串的长度n和m。
测试样例：
	1ab2345cd 9  12345ef 7
*/

/*
思路:动态规划
	1.i=0/j=0  dp[i][j] = 0
	2.x[j]=y[i] dp[i][j] = dp[i-1][j-1]+1
	2.x[j]!=y[i] dp[i][j] = 0 
	4.需要设置max去更新结果
*/

class LongestSubstring {
public:
	int findLongest(string A, int n, string B, int m) {
		vector<vector<int>> dp;
		dp.resize(n + 1);
		for (size_t i = 0; i < n + 1; ++i){
			dp[i].resize(m + 1, 0);
		}
		int max = 0;
		for (size_t i = 1; i < n + 1; ++i){
			for (size_t j = 1; j < m + 1; ++j){
				if (A[i - 1] == B[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (dp[i][j]>max){
						max = dp[i][j];
					}
				}
				else{
					dp[i][j] = 0;
				}
			}
		}
		return max;
	}
};


/*
2、最长公共子序列
我们有两个字符串m和n，如果他们的子串a和b内容相同，则称a和b是m和n的公共子序列。子串中的
字符不一定在原字符串中连续。
例如字符串abcfbc和abfcab，因此abc是他们的公共子序列。此外ab af都是他们的子串
现给你两个任意字符串(不包含空格)，请帮忙计算他们的最长公共子序列长度
输入描述：
	输入包含多组数据，每组数据包含两个字符串m和n，他们仅包含字母，并且长度不超过1024
输出描述：
	对应每组输入，输出最长公共子序列的长度
*/

/*
该题为动态规划解法：
	当i或j = 0时，dp[i][j] = 0
	当x[j]=y[i]   dp[i][j] = dp[i-1][i-1]+1
	当x[j]!=y[i]  dp[i][j] = max(dp[i-1][j],dp[i][j-1])
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	
	string a; string b;
	while (cin>>a>>b){
		size_t lenA = a.size(), lenB = b.size();
		vector<vector<int>> dp;
		dp.resize(lenA + 1);
		for (size_t i = 0; i < lenA+1; ++i){
			dp[i].resize(lenB + 1, 0);
		}
		for (size_t i = 1; i < lenA+1; ++i){
			for (size_t j = 1; j < lenB+1; ++j){
				if (a[i - 1] == b[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[lenA][lenB] << endl;
	}
	return 0;
}

/*
这里给出如何输出最长子序列的思路: 倒着推dp
当x[j] = y[i] 该字符进res j-1 i-1
否则，选择max(dp[i-1][j],dp[i][j-1])的那条路径
*/