#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1�������г��ִ�������һ�������

��������һ�����ֳ��ֵĴ˴��������鳤�ȵ�һ�룬���ҳ�������֡�����һ�����鳤��Ϊ9��
����{1��2��3��2��2��2��5��4��2}.��������2�������г�����5�Σ��������鳤�ȵ�һ�룬���
���2����������������0��
*/

/*
˼·�� 1.��������Ȼ��ȡarr[len/2+1]���ɣ����Ǵ����в����ڳ�����������������Բ����ʡ�
	   2.��ϣ��������
*/

#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int len = numbers.size() / 2;
		unordered_map<int, int> map;
		for (auto e : numbers){
			++map[e];
		}
		for (auto e : numbers){
			if (map[e] > len){
				return e;
			}
		}
		return 0;
	}
};

