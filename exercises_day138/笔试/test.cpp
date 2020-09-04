#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
员工上台阶
*/
/*
f(i) = f(i-1)+f(i-2)
*/
int main(){
	int n = 0;
	while (cin >> n){
		if (n == 0){
			cout << 0 << endl;
		}
		else{
			vector<int> dp(n + 1, 0);
			//初始状态
			dp[0] = 1;
			dp[1] = 1;//到达第一个台阶只有一种方法
			for (int i = 2; i <= n; ++i){
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			cout << dp[n] << endl;
		}
	}
	return 0;
}

//int fun(int n){
//	if (n == 0 || n == 1){
//		return 1;
//	}
//	return fun(n - 1) + fun(n - 2);
//}
//
//int main(){
//	int n = 0;
//	while (cin >> n){
//		if (n==0||n > 36){ cout << 0 << endl; }
//		else{
//			cout << fun(n) << endl;
//		}
//	}
//}

/*
拆迁房：有一排房子要拆，保证每一户都至少分一套。
1.相邻房子，家人多的分配的房子大于少的。
2.家人相同的住户，不管是否相邻 分到的房子都可以不同
求最少分配房子的方案
*/
/*
当arr[i-1]<arr[i]: f(i) = f(i-1)+1
当arr[i-1]>arr[i]: s) = f(i)+1
初始状态：每户都先分一套房子 保证至少分一套
*/

class Solution {
public:
	int house(int* person, int personLen) {
		if (personLen == 0 || person == NULL){ return 0; }
		if (personLen == 1){ return 1; }
		vector<int>dp(personLen + 1, 1);
		for (int i = 2; i <= personLen; ++i){
			if (person[i - 1] == 0){
				dp[i] = 0;
			}
			else if (person[i - 2] < person[i - 1]){
				dp[i] = dp[i - 1] + 1;
			}
			else if (person[i - 2] > person[i - 1]){
				dp[i - 1] = dp[i] + 1;
			}
		}
		long res = 0;
		for (int i = 1; i <= personLen; ++i){
			res += dp[i];
		}
		return res;
	}
};

//int main(){
//	int arr[3] = { 3,2,4};
//	Solution a;
//	a.house(arr, 3);
//	return 0;
//}

/*
1.找出一串字符串能被分成多少份。
比如：aaabbbcc
（3（aaa）+3（bbb）+2（cc））/3 = 2 
*/
class Solution {
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	*
	* @param str string字符串
	* @return int整型
	*/
	int GetFragment(string str) {
		if (str.empty()){ return 0; }
		vector<int> res;
		int a = 0, i = 0;
		while (i<str.size()){
			int tmp = 0;
			++i;
			++tmp;
			while (i < str.size() && str[i] == str[i - 1]){
				++i;
				++tmp;
			}
			a += tmp;
			res.push_back(tmp);
		}
		return a / res.size();
	}
};

//int main(){
//	string s = "aaabbaaac";
//	Solution2 a;
//	a.GetFragment(s);
//	return 0;
//}

/*
面试题 17.16. 按摩师
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，
因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
注意：本题相对原题稍作改动
示例 1：

输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
示例 2：

输入： [2,7,9,3,1]
输出： 12
解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
示例 3：

输入： [2,1,4,5,3,1,1,3]
输出： 12
解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。
*/
/*
思路：动态规划
目标：求预约总时长最长的
子问题，状态：f(i)：以i结尾的最长预约时长
由于相间隔的不能一起预约，但是不间隔的都可以所以：
f(i) = j<i&&max(f(i),f(j)+arr[i])
*/
class Solution {
public:
	int massage(vector<int>& nums) {
		if (nums.empty()){ return 0; }
		vector<int> dp(nums.size() + 2, 0);
		int res = INT_MIN;
		for (int i = 2; i<nums.size() + 2; ++i){
			for (int j = 0; j<i - 1; ++j){
				//保证j<i-1(不相邻)
				dp[i] = max(dp[i], dp[j] + nums[i - 2]);
			}
			if (dp[i]>res){ res = dp[i]; }
		}
		return res;
	}
};