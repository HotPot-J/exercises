#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
/*
953. 验证外星语词典
某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。



示例 1：

输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
输出：true
解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
示例 2：

输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
输出：false
解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
*/
class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		unordered_map<char, int>m;
		for (int i = 0; i < order.size(); i++) {
			m[order[i]] = i;
		}
		bool flag = true;
		for (int i = 0; i < words.size() - 1; i++) {
			string w1 = words[i];
			string w2 = words[i + 1];
			for (int j = 0; j < w1.size(); j++) {
				int index2 = 0;
				if (j < w2.size()) {
					index2 = m[w2[j]];
				}
				if (m[w1[j]] == index2) continue;
				if (m[w1[j]] < index2) break;
				return false;
			}
		}
		return true;
	}
};


/*
1037. 有效的回旋镖
回旋镖定义为一组三个点，这些点各不相同且不在一条直线上。

给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。



示例 1：

输入：[[1,1],[2,3],[3,2]]
输出：true
示例 2：

输入：[[1,1],[2,2],[3,3]]
输出：false


提示：

points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100
*/
class Solution {
public:
	bool isBoomerang(vector<vector<int>>& points) {
		bool f = 0;
		double k1 = 0, k2 = 0;
		if (points[0][1] - points[1][1] == 0)
		{
			k1 = INT_MAX;
		}

		if (points[1][1] - points[2][1] == 0)
		{
			k2 = INT_MAX;
		}
		if (points[0] != points[1] && points[0] != points[2] && points[2] != points[1])
		{
			if (k1 != INT_MAX) k1 = (double)(points[0][0] - points[1][0]) / (points[0][1] - points[1][1]);
			if (k2 != INT_MAX) k2 = (double)(points[1][0] - points[2][0]) / (points[1][1] - points[2][1]);
			if (k1 != k2) f = 1;
		}
		return f;
	}
};

