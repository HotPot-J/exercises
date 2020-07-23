#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1、数组中出现次数超过一半的数字

数组中有一个数字出现的此处超过数组长度的一半，请找出这个数字。输入一个数组长度为9的
数组{1，2，3，2，2，2，5，4，2}.由于数字2在数组中出现了5次，超过数组长度的一半，因此
输出2。如果不存在则输出0。
*/

/*
思路： 1.可以排序，然后取arr[len/2+1]即可，但是此题有不存在超过半数的情况，所以不合适。
	   2.哈希遍历即可
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

