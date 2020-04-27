#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
/*
953. ��֤������ʵ�
ĳ��������Ҳʹ��Ӣ��Сд��ĸ��������˳�� order ��ͬ����ĸ���˳��order����һЩСд��ĸ�����С�

����һ������������д�ĵ��� words���Լ�����ĸ���˳�� order��ֻ�е������ĵ����������������а��ֵ�������ʱ������ true�����򣬷��� false��



ʾ�� 1��

���룺words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
�����true
���ͣ��ڸ����Ե���ĸ���У�'h' λ�� 'l' ֮ǰ�����Ե��������ǰ��ֵ������еġ�
ʾ�� 2��

���룺words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
�����false
���ͣ��ڸ����Ե���ĸ���У�'d' λ�� 'l' ֮����ô words[0] > words[1]����˵������в��ǰ��ֵ������еġ�
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
1037. ��Ч�Ļ�����
�����ڶ���Ϊһ�������㣬��Щ�������ͬ�Ҳ���һ��ֱ���ϡ�

����ƽ������������ɵ��б��ж���Щ���Ƿ���Թ��ɻ����ڡ�



ʾ�� 1��

���룺[[1,1],[2,3],[3,2]]
�����true
ʾ�� 2��

���룺[[1,1],[2,2],[3,3]]
�����false


��ʾ��

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

