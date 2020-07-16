#define _CRT_SECURE_NO_WARNINGS 1

/*
1、发邮件
链接：https://www.nowcoder.com/questionTerminal/95e35e7f6ad34821bc2958e37c08918b
来源：牛客网

NowCoder每天要给很多人发邮件。有一天他发现发错了邮件，把发给A的邮件发给了B，
把发给B的邮件发给了A。于是他就思考，要给n个人发邮件，在每个人仅收到1封邮件的情况下，
有多少种情况是所有人都收到了错误的邮件？
即没有人收到属于自己的邮件。

输入描述:
输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。


输出描述:
对应每一组数据，输出一个正整数，表示无人收到自己邮件的种数。
*/

/*
思路:递归 古典概型：
	1.若每次都是相邻的寄错则接下来的问题为：（n-1)*f(n-2)
	2.否则：（n-1)*f（n-1）
	可得递推公式为f（n） = （n-1）*（f（n-1）f（n-2））
*/

#include<iostream>
using namespace std;

//求发错事件发生次数

long long fun(long long n){
	if (n == 1){
		return 0;
	}
	if (n == 2){
		return 1;
	}
	return (n - 1)*(fun(n - 1) + fun(n - 2));
}

//int main(){
//	long long n = 0;
//	while (cin >> n){
//		cout << fun(n) << endl;
//	}
//	return 0;
//}


/*
2、
链接：https://www.nowcoder.com/questionTerminal/d83721575bd4418eae76c916483493de
来源：牛客网

编程题]最长上升子序列

广场上站着一支队伍，她们是来自全国各地的扭秧歌代表队，现在有她们的身高数据，
请你帮忙找出身高依次递增的子序列。 例如队伍的身高数据是（1、7、3、5、9、4、8），
其中依次递增的子序列有（1、7），（1、3、5、9），（1、3、4、8）等，其中最长的长度为4。

输入描述:
输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000）。
紧接着第二行包含n个正整数m（1≤n≤10000），代表队伍中每位队员的身高。

输出描述:
对应每一组数据，输出最长递增子序列的长度。

例子:
  输入：  7
		  1 7 3 5 9 4 8
  输出： 4    （即1 3 5 9）
*/

/*
思路:动态规划
	1.当arr[i]>arr[j]	dp[i] = max(dp[i],dp[j]+1);
	2.每次更新最大值
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n = 0;
	while (cin>>n){
		vector<int> arr;
		vector<int> dp;
		dp.resize(n, 0);
		int tmp = 0;
		for (int i = 0; i < n; ++i){
			cin >> tmp;
			arr.push_back(tmp);
		}
		int res = 0;
		for (int i = 1; i < n; ++i){
			for (int j = 0; j < i; ++j){
				if (arr[i]>arr[j]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
				if (dp[i]>res){
					res = dp[i];
				}
			}
		}
		cout << res + 1 << endl;
	}
	return 0;
}