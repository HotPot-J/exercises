#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1、乒乓球筐
nc有两盒（A,B）乒乓球，有红双喜的，有亚力亚的...现在他需要判别A盒是否包含了B盒中所有
的种类，并且每种球的数量不少于B盒中的数量，该怎么办呢？

输入描述:
	输入有多组数据。
	每组数据包含两个字符串A,B，代表A盒与B盒中的乒乓球，每个乒乓球用一个大写字母表示，
	即相同类型的乒乓球为相同的大写字母。
字符串长度不大于10000

输出描述:
	每一组输入都对应一行输出:如果B盒中所有的球类型在A中都有，并且每种球的数量都不大于
	A，则输出“Yes”;否则输出“No”。

例子:
输入:
	ABCDFYE CDE
	ABCDGEAS CDECDE
输出:
	Yes
	No
*/

/*
思路:  哈希
*/
//
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
	string a, b;
	while (cin >> a >> b){
		unordered_map<char, int> a_map;
		unordered_map<char, int> b_map;
		int Asize = a.size();
		int Bsize = b.size();
		for (int i = 0; i < Asize; ++i){
			++a_map[a[i]];
		}
		for (int i = 0; i < Bsize; ++i){
			++b_map[b[i]];
		}
		int flag = 1;
		for (int i = 0; i < Bsize; ++i){
			if (a_map.find(b[i]) == a_map.end()){
				flag = 0;
				break;
			}
			if (a_map[b[i]] < b_map[b[i]]){
				flag = 0;
				break;
			}
		}
		if (flag){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}

/*
2、查找兄弟单词(牛客)

题目描述:
	实现一个可存储若干个单词的字典。用户可以：
		1.在字典中加入单词
		2.查找指定单词在字典中的兄弟单词个数
		3.查找指定单词的指定序号的兄弟单词，指定序号指字典中兄弟单词按字典
		顺序(参见page 3)排序后的序号(从1开始)
		4.清空字典中所有单词
	    ..........
*/

/*
思路: 排序 字符串比较
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int n = 0;
	while (cin >> n){
		vector<string> arr;
		string tmp;
		for (int i = 0; i < n; ++i){
			cin >> tmp;
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end());
		string aim;
		vector<string> res;
		int k = 0;
		cin >> aim >> k;
		int a = aim.size();
		string tmp1 = aim;
		sort(tmp1.begin(), tmp1.end());
		for (int i = 0; i < n; ++i){
			int b = arr[i].size();
			if (b == a&&aim!=arr[i]){
				tmp = arr[i];
				sort(tmp.begin(), tmp.end());
				if (tmp == tmp1){
					res.push_back(arr[i]);
				}
			}
		}
		if (!res.empty()){
			cout << res.size() << endl;
		}
		else{
			cout << 0 << endl;
		}
		if (res.size() >= k){
			cout << res[k - 1] << endl;
		}
	}
	return 0;
}