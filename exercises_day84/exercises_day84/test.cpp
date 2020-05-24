#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
1399. ͳ����������Ŀ
����һ������ n ������������� 1 �� n ��ÿ������ 10 ���Ʊ�ʾ�µ���λ�ͣ�ÿһλ�ϵ�������ӣ���Ȼ�����λ����ȵ����ַŵ�ͬһ�����С�

����ͳ��ÿ�����е�������Ŀ��������������Ŀ�����������ж��ٸ���



ʾ�� 1��

���룺n = 13
�����4
���ͣ��ܹ��� 9 ���飬�� 1 �� 13 ����λ��ͺ���Щ��ֱ��ǣ�
[1,10]��[2,11]��[3,12]��[4,13]��[5]��[6]��[7]��[8]��[9]���ܹ��� 4 ����ӵ�е����ֲ�����ࡣ
ʾ�� 2��

���룺n = 2
�����2
���ͣ��ܹ��� 2 ����СΪ 1 ���� [1]��[2]��
ʾ�� 3��

���룺n = 15
�����6
ʾ�� 4��

���룺n = 24
�����5


��ʾ��

1 <= n <= 10^4
*/

class Solution {
public:
	int countLargestGroup(int n) {
		unordered_map<int, int> hashMap;
		int maxValue = 0;
		for (int i = 1; i <= n; ++i) {
			int key = 0, i0 = i;
			while (i0) {
				key += i0 % 10;
				i0 /= 10;
			}
			++hashMap[key];
			maxValue = max(maxValue, hashMap[key]);
		}
		int count = 0;
		for (auto& kvpair : hashMap) {
			if (kvpair.second == maxValue) {
				++count;
			}
		}
		return count;
	}
};

/*
1351. ͳ����������еĸ���
����һ�� m * n �ľ��� grid�������е�Ԫ�������ǰ��л��ǰ��У����Էǵ���˳�����С�

����ͳ�Ʋ����� grid �� ���� ����Ŀ��



ʾ�� 1��

���룺grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
�����8
���ͣ������й��� 8 ��������
ʾ�� 2��

���룺grid = [[3,2],[1,0]]
�����0
ʾ�� 3��

���룺grid = [[1,-1],[-1,-1]]
�����3
ʾ�� 4��

���룺grid = [[-1]]
�����1


��ʾ��

m == grid.length
n == grid[i].length
1 <= m, n <= 100
*/

class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		int num = 0;
		for (auto x : grid){
			for (auto y : x){
				if (y<0) num++;
			}
		}
		return num;
	}
};

