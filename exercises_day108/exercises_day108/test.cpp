#define _CRT_SECURE_NO_WARNINGS 1

/*
1.字符串翻转
*/

/*
思路：双指针
*/
#include<iostream>
#include<string>
using namespace std;
void _reverse(string& str){
	int top = 0, tail = str.size() - 1;
	while (top < tail){
		swap(str[top], str[tail]);
		++top;
		--tail;
	}
}
//int main(){
//	string str;
//	while (cin >> str){
//		_reverse(str);
//		cout << str << endl;
//	}
//	return 0;
//}

/*
2.公共字符串计算
计算两个字符串最大公共子串的长度，字符不区分大小写。
*/

/*
思路：动态规划
先将两个字符串都转换为小写/大写
可以使用#include <algorithm>里的如下方法进行大小写转换；
转小写:
	transform(str.begin(),str.end(),str.begin(),::tolower);
转大写:
    transform(str.begin(),str.end(),str.begin(),::toupper);
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
void publicSting(int& res, string& str1, string& str2){
	int len1 = str1.size();
	int len2 = str2.size();
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 0; i < len1; ++i){
		for (int j = 0; j < len2; ++j){
			if (str1[i] == str2[j])
				dp[i+1][j+1] = dp[i][j] + 1;
			if (dp[i+1][j+1] > res)
				res = dp[i+1][j+1];
		}
	}
}

int main(){
	string str1, str2;
	while (cin >> str1 >> str2){
	//全转小写
	int res = 0;
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	publicSting(res, str1, str2);
	cout << res << endl;
	}
	return 0;
}