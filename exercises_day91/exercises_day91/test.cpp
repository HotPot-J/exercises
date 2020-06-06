#define _CRT_SECURE_NO_WARNINGS 1

/*
1、回文串是一个正读和反读都一样的字符串，比如level或者noon等等就是回文串，花花非常喜欢这种
回文串，生日他收到两个礼物分别为字符串A和B，她非常好奇有没有办法将字符串B插入字符串A
使产生的字符串为回文串，请帮他寻找有多少种插入办法可以使得新串为回文串。
例子:
	A = "aba" B = "b" 有四种吧B插入A的办法：
		baba 不是
		abba是
		abba是
		abab不是
		所以答案为2

		输入： 第一行A 第二行B  字符串长度均小于100 只包含小写字母
		输出: 一个数字（答案）
*/
//思路：主要练习了reverse函数  和string成员函数 compare（字符串比较）和substr（字符串截取）函数
//a.compare(b); 当a==b 返回0   
//substr(0,3); 从起始位置（包含起始位置的字符）返回3个字符
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
bool check(string s){
	//验证回文
	string tmp = s;
	reverse(s.begin(), s.end());
	if (tmp.compare(s) == 0){
		return true;
	}
	return false;
}
void fun(string A,string B){
	int res = 0;
	string tmp;
	tmp = B;
	tmp.append(A);
	if (check(tmp)){
		++res;
	}
	tmp.erase();
	for (int i = 0; i < A.size(); ++i){
		tmp += A.substr(0, i + 1);
		tmp += B;
		tmp += A.substr(i+1, A.size() - i-1);
		if (check(tmp)){
			++res;
		}
		tmp.erase();
	}
	cout << res << endl;
}
//int main(){
//	string A;
//	string B;
//	getline(cin, A);
//	getline(cin, B);
//	fun(A, B);
//	return 0;
//}

/*
2、一个数组有N个元素，求连续子数组的最大和，例如:-1,2,1 最大连续子数组为[2，1] 其和
为3
输入描述:
	输入为两行，第一行一个整数n(1<=n<=1000000)，表示一共有N个元素，第二行为N个数 每个整数都在int范围内
	输出： 所有连续子数组中和最大的值
*/

//思路: 动态规划 当遇到当前数组有变小趋势 即从该位置开始重新尝试寻找
#include<iostream>
#include<vector>
using namespace std;

	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1){
			return nums[0];
		}
		int max = nums[0];
		for (int i = 1; i < nums.size(); ++i){
			int a = nums[i] + nums[i - 1];
			int b = nums[i];
			nums[i] = a>b ? a : b;
			if (nums[i] > max){
				max = nums[i];
			}
		}
		cout << max << endl;
	}

int  main(){
	int n = 0;
	int tmp = 0;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> tmp;
		arr.push_back(tmp);
	}
	maxSubArray(arr);
	return 0;
}