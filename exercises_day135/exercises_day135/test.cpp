#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1、左右最值最大差
给定一个长度为N(N>1)的整型数组A，可以将A划分成左右两个部分，左部分A[0,K]，右部分
[K+1...N-1]，K可以的取值范围是[0,N-2]。求这么多划分方案中，左部分中的最大值减去右
部分最大值的绝对值，最大是多少?
给定整数数组A和数组的大小n，请返回题目所求答案。
测试样例:
	[2,7,3,1,1] 5
	返回6
*/

/*
思路一:1.先从N-2的下标直接进行左右划分
	 2.维护左右两个数组的最大值，每次把左数组的最后一个数字放进右数组，
	 左：当最大值出数组后进行一次建大堆。右：当进来的数字大于当前最大数字，进行更新
	 (用空间换时间)
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
	//构造左右两个区间 (右不用构造，只用维护最大值即可)
		vector<int> left (A);
		left.pop_back();
	//构造一个大堆 用来判断left的最大值
		priority_queue<int> top(left.begin(), left.end());
		int leftMax = top.top(), rightMax = A[n - 1], res = abs(leftMax - rightMax);
	//接下来进行左出右进的模式，对最大值进行维护
		for (int i = n - 2; i > 0; --i){
			int tmp = left[i];
			left.pop_back();
			if (tmp > rightMax){
				//跟新右最大值
				rightMax = tmp;
			}
			if (tmp == leftMax){
				//建堆 更新左最大
				priority_queue<int> top1(left.begin(), left.end());
				leftMax = top1.top();
			}
			res = abs(leftMax - rightMax) > res ? abs(leftMax - rightMax) : res;
		}
		return res;
	}
};

//int main(){
//	MaxGap a;
//	vector<int> a = { 2, 7, 3, 1, 1 };
//	cout << a.findmaxgap(a, 5) << endl;
//	return 0;
//}

/*
思路二： 贪心
	求左右区间最大值的差的最大值，什么情况下差值最大呢？
	答案是整个数组的最大值-min(首，尾)，因为无论区间怎么变化，最大值可能被划分到右或者左区间，
	但是首，尾的位置是固定的 由题意保证：left[0,k]  right[k+1,n-1]
	所以只需要O（n）的时间复杂度，O（1）的空间复杂度题目可解
*/
class MaxGap1 {
public:
	int findMaxGap(vector<int> A, int n) {
		int max = 0;
		int min = A[0] < A[n - 1] ? A[0] : A[n - 1];
		for (auto e : A){
			if (e>max){
				max = e;
			}
		}
		return abs(max - min);
	}
};

/*
2、顺时针打印矩阵
对于一个矩阵，请设计一个算法从左上角(mat[0][0])开始，顺时针打印矩阵元素，给定int
矩阵mat，以及它的维数，请返回一个数组，数组中的元素为矩阵元素的顺时针输出
*/

class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		vector<int> res;
		int h = 0, d = n-1, l = 0, r = m-1; //上下左右
		int i = 0;
		while (l<=r||h<=d){		
			//左-》右
			for (i = l; i <= r; ++i){
				res.push_back(mat[h][i]);
			}
			h++;
			if (h > d){
				break;
			}
			//上-》下
			for (i = h; i <= d; ++i){
				res.push_back(mat[i][r]);
			}
			r--;
			if (r < l){
				break;
			}
			//右->左
			for (i = r; i >= l; --i){
				res.push_back(mat[d][i]);
			}
			d--;
			if (d < h){
				break;
			}
			//下-》上
			for (i = d; i >=h; --i){
				res.push_back(mat[i][l]);
			}
			l++;
			if (l>r){
				break;
			}
		}
		return res;
	}
};

int main(){
	vector<vector<int>> a;
	Printer b;
	int n = 7, m = 6;
	a.resize(n);
	for (int i = 0; i < n; ++i){
		a[i].resize(m, 0);
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			int tmp = 0;
			cin >> tmp;
			a[i][j] = tmp;
		}
	}
  vector<int> res = b.clockwisePrint(a, n, m);
	return 0;
}