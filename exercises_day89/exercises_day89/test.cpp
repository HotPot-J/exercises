#define _CRT_SECURE_NO_WARNINGS 1

/*
一、牛牛定义排序子序列为一个数组中一段连续的子序列，并且这段子序列是非递增或者
非递减排序的。牛牛有一个长度为n的整数数组A，他现在有一个任务是把数组A分成若干段
排序子序列，牛牛想知道他最少可以把这个数组分为几段排序子序列。
例：牛牛可以把A【1 2 3 2 2 1】划分为1 2 3 和 2 2 1两个排序子序列，至少需要划分两个子序列
所以输出2

输入描述：
	输入的第一行为一个正整数n（1<=n<=10^5）
	第二行包括n个整数 1~10^9

输出描述:
	一个整数表示牛牛可以将A最少划分为多少段排序子序列
*/

//思路：找到完递增找递减/找完递减找递增

#include<iostream>
#include<vector>
using namespace std;
void fun( vector<int> arr){
	size_t res = 0, p = 0;
	size_t flag = 0;//该值为波峰或者波谷
	if (arr.size() <= 2){
		//当小于两个数字时只有一种情况
		cout << 1 << endl;
		return;
	}
	while (p < arr.size() - 1){
		if (arr[p] < arr[p + 1]){
			//递增
			while (p<arr.size()-1&&arr[p] <= arr[p + 1]){
				++p;
			}
			++res;
			flag = p; //波峰
			++p;
		}
		else if (arr[p] == arr[p + 1]){
			++p;
		}
		else {
			//递减
			while (p < arr.size() - 1 && arr[p] >= arr[p + 1]){
				++p;
			}
			++res;
			flag = p;//波谷
			++p;
		}
	}
	if (flag != arr.size() - 1){
		++res;
	}
	cout << res;
}
//int main(){
//	vector<int> arr;
//	int n = 0, tmp = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i){
//		cin >> tmp;
//		arr.push_back(tmp);
//	}
//	fun(arr);
//	return 0;
//}

/*
2、读入一个字符串str，输出字符串str中的连续最长数字串
例： abcd1234ed125ss123456789
输出：123456789
*/

//思路：双指针，遍历的同时更新最长的字符串即可
/*substr(pos, length):从string的pos位置开始提取长度为length的字符串*/

#include<iostream>
#include<string>
using namespace std;
void fun1(string& str){
	string res;
	int max = 0;
	int tmp = 0;
	size_t front = 0;
	size_t rear = 0;
	size_t tail = 0;
	while (rear < str.size()){
		while (rear<str.size() && !isdigit(str[rear])){
			//如果不是数字
			++rear;
		}
		front = rear;
		while (rear < str.size() && isdigit(str[rear])){
		  //先找到该段数字的末尾位置
			++tmp;
			++rear;
		}
		if (tmp>max){
			//当该数字段大于当前最大连续数字串 才有探讨的必要
			 tail = rear - 1; //该数字段的末尾
			
			//此时题目转换为寻找最长连续子字符串 采用滑动窗口解决问题
			rear = front;
			tmp = 0; //记录窗口长度
			while (rear <= tail){
				if (str[rear + 1] - str[rear] == 1){
					//连续
					++tmp;//记录当前窗口长度
					++rear;
				}
				else{
					//不连续
					if (tmp>max){
						res = str.substr(front, tmp+1);
						max = tmp;
						tmp = 0;
					}
					++rear;
					front = rear;
				}
			}
			rear = tail + 1;//找完这一段数字后 继续遍历下一段
		}
	}
	cout << res << endl;
}
//int main(){
//	string str;
//	getline(cin, str);
//	fun1(str);
//	return 0;
//}

/*
3、数组中出现次数超过一半的数字
*/
/*
思路1：哈希表 时间复杂度O（2n）
*/

#include<iostream>
#include<unordered_map>
#include<vector>
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		unordered_map<int, int> map;
		int tmp = 0;
		for (int i = 0; i < numbers.size(); ++i){
			tmp = ++map[numbers[i]];
			if (tmp>numbers.size()/2){
				return numbers[i];
			}
		}
		return 0;
	}
};

//思路2：排序寻找
#include<iostream>
#include<vector>
#include<algorithm>

//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		if ( numbers.empty()){
//			return 0;
//		}
//		sort(numbers.begin(), numbers.end());
//		int tmp = 1, i = 0, j = 1, res = 0;
//		while (j < numbers.size()){
//			while (numbers[i] == numbers[j]){
//				++j;
//				++tmp;
//			}
//			if (tmp>numbers.size() / 2){
//				return numbers[i];
//			}
//			tmp = 1;
//			i = j;
//			++j;
//		}
//		return 0;
//	}
//};
int main(){
	Solution a;
	vector<int> arr = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	a.MoreThanHalfNum_Solution(arr);
	return 0;
}

