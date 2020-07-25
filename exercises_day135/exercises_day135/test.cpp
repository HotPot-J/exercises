#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1��������ֵ����
����һ������ΪN(N>1)����������A�����Խ�A���ֳ������������֣��󲿷�A[0,K]���Ҳ���
[K+1...N-1]��K���Ե�ȡֵ��Χ��[0,N-2]������ô�໮�ַ����У��󲿷��е����ֵ��ȥ��
�������ֵ�ľ���ֵ������Ƕ���?
������������A������Ĵ�Сn���뷵����Ŀ����𰸡�
��������:
	[2,7,3,1,1] 5
	����6
*/

/*
˼·һ:1.�ȴ�N-2���±�ֱ�ӽ������һ���
	 2.ά������������������ֵ��ÿ�ΰ�����������һ�����ַŽ������飬
	 �󣺵����ֵ����������һ�ν���ѡ��ң������������ִ��ڵ�ǰ������֣����и���
	 (�ÿռ任ʱ��)
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
	//���������������� (�Ҳ��ù��죬ֻ��ά�����ֵ����)
		vector<int> left (A);
		left.pop_back();
	//����һ����� �����ж�left�����ֵ
		priority_queue<int> top(left.begin(), left.end());
		int leftMax = top.top(), rightMax = A[n - 1], res = abs(leftMax - rightMax);
	//��������������ҽ���ģʽ�������ֵ����ά��
		for (int i = n - 2; i > 0; --i){
			int tmp = left[i];
			left.pop_back();
			if (tmp > rightMax){
				//���������ֵ
				rightMax = tmp;
			}
			if (tmp == leftMax){
				//���� ���������
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
˼·���� ̰��
	�������������ֵ�Ĳ�����ֵ��ʲô����²�ֵ����أ�
	����������������ֵ-min(�ף�β)����Ϊ����������ô�仯�����ֵ���ܱ����ֵ��һ��������䣬
	�����ף�β��λ���ǹ̶��� �����Ᵽ֤��left[0,k]  right[k+1,n-1]
	����ֻ��ҪO��n����ʱ�临�Ӷȣ�O��1���Ŀռ临�Ӷ���Ŀ�ɽ�
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
2��˳ʱ���ӡ����
����һ�����������һ���㷨�����Ͻ�(mat[0][0])��ʼ��˳ʱ���ӡ����Ԫ�أ�����int
����mat���Լ�����ά�����뷵��һ�����飬�����е�Ԫ��Ϊ����Ԫ�ص�˳ʱ�����
*/

class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		vector<int> res;
		int h = 0, d = n-1, l = 0, r = m-1; //��������
		int i = 0;
		while (l<=r||h<=d){		
			//��-����
			for (i = l; i <= r; ++i){
				res.push_back(mat[h][i]);
			}
			h++;
			if (h > d){
				break;
			}
			//��-����
			for (i = h; i <= d; ++i){
				res.push_back(mat[i][r]);
			}
			r--;
			if (r < l){
				break;
			}
			//��->��
			for (i = r; i >= l; --i){
				res.push_back(mat[d][i]);
			}
			d--;
			if (d < h){
				break;
			}
			//��-����
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