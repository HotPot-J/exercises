#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
链接：https://www.nowcoder.com/questionTerminal/ceb89f19187b4de3997d9cdef2d551e8
来源：牛客网

1、电话号码
1 2 3
4 5 6
7 8 9
  0
上图是一个电话的九宫格，如你所见一个数字对应一些字母，因此在国外企业喜欢把电话
号码设计成与自己公司名字相对应。例如公司的Help Desk号码是4357，因为4对应H、3对
应E、5对应L、7对应P，因此4357就是HELP。同理，TUT-GLOP就代表888-4567、310-GINO代
表310-4466。
NowCoder刚进入外企，并不习惯这样的命名方式，现在给你一串电话号码列表，
请你帮他转换成数字形式的号码，并去除重复的部分。

输入描述:
输入包含多组数据。

每组数据第一行包含一个正整数n（1≤n≤1024）。

紧接着n行，每行包含一个电话号码，电话号码仅由连字符“-”、数字和大写字母组成。
没有连续出现的连字符，并且排除连字符后长度始终为7（美国电话号码只有7位）。


输出描述:
对应每一组输入，按照字典顺序输出不重复的标准数字形式电话号码，即“xxx-xxxx”形式。

每个电话号码占一行，每组数据之后输出一个空行作为间隔符。
*/

/*
思路:
	1.用哈希思想，将a-z每个字符作为下标，对应的数字存在对应下标的元素内
		例如arr['a'] = 1; arr['b'] = 1;arr['c'] = 1;
	2.当出现的连字符直接跳过
	3.(跑了半天没跑过 发现需要去重！！！) 用set存数据,正好还能排序 简直完美
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<cctype>
#include<algorithm>
using namespace std;

int main(){
	int arr[256] = { 0 };
	for (int i = 'P'; i <= 'S'; ++i){
		arr[i] = 7;
	}
	for (int i = 'W'; i <= 'Z'; ++i){
		arr[i] = 9;
	}
	int j = 'A';
	for (int i = 2; i <= 8; ++i){
		if (i == 7){
			j += 4;
		}
		else{ 
			int tmp = j + 2;
			for (j; j <= tmp; ++j){
				arr[j] = i;
			}
		}
	}
	int n = 0;
	while (cin >> n){
		set<string> res;
		string c_name;
		string tmp1;
		for (int i = 0; i < n; ++i) {
			cin >> c_name;
			int len = c_name.size();
			for (int i = 0; i < len; ++i){
				if (tmp1.size() == 3){
					tmp1 += '-';
				}
				if (c_name[i] >= '0'&&c_name[i] <= '9'){
					tmp1 += c_name[i];
				}
				else if (c_name[i] == '-'){
					continue;
				}
				else{
					//字母
					if (c_name[i] >= 'a'&&c_name[i] <= 'z'){
						c_name[i] = toupper(c_name[i]);
					}
					tmp1 += to_string(arr[c_name[i]]);
				}
			}
			res.insert(tmp1);
			tmp1.clear();
		}
		auto it = res.begin();
		while (it != res.end()){
			cout << *it << endl;
			++it;
		}
		cout << endl;
	}
	return 0;
}

/*
2.求和

输入两个整数n和m，从数列1，2，3...n中随意取几个数，使其和等于m
要求将其中所有可能的组合列出来

输入描述：
每个测试输入包含2个整数，n和m

输出描述：
按每个组合的字典排序列输出，每行输出一种组合

例子:
	5 5 
输出：
	1 4
	2 3
	5
*/

/*
思路: 
     1.回溯 寻找各种可能解
     2.剪枝法 避免重复计算
	 3.设置搜索起点，防止重复解
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

void dfs(set<vector<int>>& res, vector<int>& tmp,int begin, int& n,int target)
{
	if (target == 0){
		res.insert(tmp);
		return;
	}
	for (int i = begin; i <= n; ++i){
		if (target - i < 0){
			//进行剪枝
			break;
		}
		tmp.push_back(i);
		target -= i;
		dfs(res, tmp, i + 1, n, target);
		tmp.pop_back();
		target += i;
	}
}
int main(){
	int n, m;
	while (cin >> n >> m){
		set<vector<int>> res;
		vector<int> tmp;
		dfs(res, tmp, 1, n, m);
		auto it = res.begin();
		while (it != res.end()){
			int len = (*it).size();
			for (int i = 0; i < len - 1; ++i){
				cout << (*it)[i] << " ";
			}
			cout << (*it)[len - 1] << endl;
			++it;
		}
	}
	return 0;
}
