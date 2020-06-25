#define _CRT_SECURE_NO_WARNINGS 1

/*
1.微信红包
春节期间，小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额
出现的次数超过了红包总数的一半。请帮小明找到该红包金额。具体算法思路和代码实现，要求
尽可能高效。给定一个红包的金额数组gifts及他的大小n，请返回所求红包的金额。若没有金额
超过总数一半，返回0
*/

/*
思路：寻找超过数组中一半数字的变形 ，这里的输入有可能没有超过一半的
排序，滑动窗口寻找超过半数的数字
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		int i = 0, j = 0, count = 0;
		for (int i = 0; i < n; ++i){
			for (j = i + 1; j < n; ++j){
				if (gifts[i] != gifts[j]){
					count = (j - i)>count ? (j - i) : count;
					if (count>n / 2){
						return gifts[i];
					}
					break;
				}
			}
		}
		return 0;
	}
};

//int main(){
//	vector<int> arr;
//	Gift a;
//	int tmp = 0, n = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i){
//		cin >> tmp;
//		arr.push_back(tmp);
//	}
//	cout << a.getValue(arr, n) << endl;
//	return 0;
//}

/*
2.计算字符串的距离
levenshtein距离，又称为编辑距离，指的是两个字符串之间，由一个转换成另一个所需要的最少
编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除字符。
编辑距离的算法是首先由俄国科学家levenshtein提出的。
字符串A：abcdefg
字符串B：abcdef
增加或者删掉g都可以达到目的，而都只需要一次操作，把这个1定义为距离
*/

/*
思路：dfs 回溯  
该思路实现了 但是空间时间复杂度过大 无法AC....
*/
#include<iostream>
#include<string>
using namespace std;
void dfs(string a, string b,size_t i,size_t j, int tmp, int& res){
	if (i >= a.size()){
		if (j < b.size()){
			tmp += b.size() - a.size();
		}
		if (res == 0 && tmp != 0){
			res = tmp;
			return;
		}
		res = tmp < res ? tmp: res;
		return;
	}
	else if (j >= b.size())
	{
		if (i < a.size()){
			tmp += a.size() - b.size();
		}
		if (res == 0 && tmp != 0){
			res = tmp;
			return;
		}
		res = tmp < res ? tmp : res;
		return;
	}

	//替换的路
	if (a[i] != b[j]){
		char c = a[i];
		a[i] = b[i];
		int tmp1 = tmp;
		++tmp;
		dfs(a, b, i + 1, j + 1, tmp, res);
		//回溯 注意 tmp也需要进行回溯
		a[i] = c;
		tmp = tmp1;
	}
	//插入的路
	if (a[i] != b[j]&&j+1<b.size()&&a[i]==b[j+1]){
		a.insert(i, 1, b[j]);
		++tmp;
		int tmp1 = tmp;
		dfs(a, b, i + 1, j + 1, tmp, res);
		a.erase(i, 1);
		tmp = tmp1;
	}
	//删除的路
	if (a[i] != b[j] && j + 1 < b.size() && a[i] == b[j + 1]){
		char c = b[j];
		b.erase(j, 1);
		int tmp1 = tmp;
		++tmp;
		dfs(a, b, i + 1, j + 1, tmp, res);
		b.insert(j, 1, c);
		tmp = tmp1;
	}
	dfs(a, b, i + 1, j + 1, tmp, res);
}
//int main(){
//	string A, B;
//	while (cin >> A >> B){
//		int res = 0;
//		string a, b;
//		if (A.size() > B.size()){
//			 a = B;
//			 b = A;
//		}
//		else{
//			a = A;
//			b = B;
//		}
//		dfs(a, b, 0, 0, 0, res);
//		cout << res << endl;
//	}
//	return 0;
//}

/*
思路2：动态规划
 设ai为字符串A(a1a2a3....ai)的前i个字符
   bj为字符串B(b1b2b3....bj)的前j个字符
 if(ai==bj) f(i,j) = f(i-1,j-1)
 
 if(ai!=bj)
	1.选择替换则两个字符串还需要操作 f(i-1,j-1)次
	2.选择删除ai或者在bj后添加ai 还需要操作f(i-1，j)
	3.选择删除bj或者在ai后添加bj 还需要操作f(i,j-1)
	此时 f(i,j) = min（f（i-1，j-1），f(i-1,j),f(i,j-1)）+1
	f(0,j) = j,f(i,0) = i
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int _dp(string& a,string& b,int& n1,int& n2,vector<vector<int>>& dp){
	for (int i = 1; i < n1; ++i){
		for (int j = 1; j < n2; ++j){
			if (a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}
	return dp[n1 - 1][n2 - 1];
}
int main(){
	string A, B;
	while (cin >> A >> B){
		vector<vector<int>> dp;
		int n1 = A.size()+1, n2 = B.size()+1;
		dp.resize(n1);
		for (int i = 0; i < n1; ++i){
			dp[i].resize(n2, 0);
		}
		//f(i,0) = i;
		for (int i = 0; i < n1; ++i){
			dp[i][0] = i;
		}
		//f(0,j) = j
		for (int j = 0; j < n2; ++j){
			dp[0][j] = j;
		}
		cout << _dp(A, B, n1, n2, dp) << endl;
	}
	return 0;
}