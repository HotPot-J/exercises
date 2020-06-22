#define _CRT_SECURE_NO_WARNINGS 1

/*
1、汽水瓶
有这样一道智力题：某商店规定 三个汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，他最多
可以换多少瓶汽水喝？答案是5瓶。方法:先用9个空瓶换三瓶，喝掉，就剩4个空瓶子，用三个再
换一瓶喝掉，就剩2个，让后借老板一瓶，喝完，就有三个空瓶给老板了。如果小张手上有n个空
汽水瓶，最多可以换多少瓶汽水?
输入:
	输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n(1<=100)，表示小张
	手上的空气水瓶数字。n = 0表示输入结束，你的程序不应当处理这一行。
输入:
	3
	10
	81
	0
输出:
	1
	5
	40
*/

/*
思路: 递归  
		兑换饮料分为如下三部分:
			1.当前空瓶可兑换的饮料
			2.喝完的空瓶+上一次不够兑换饮料的瓶子 可兑换的饮料
*/
#include<iostream>
#include<vector>
using namespace std;
int fun(int n){
	if (n<2){
		return 0;
	}
	else if (n == 2||n==3){
		return 1;
	}
	//n/3为当前可直接兑换的饮料 n%3为上一次不够兑换饮料的瓶子 n/3是兑换完喝光的空瓶
		return n / 3 + fun(n%3+n/3);
}
//int main(){
//	int n = 0;
//	while (cin >> n){
//		if (n == 0){
//			break;
//		}
//		cout << fun(n) << endl;
//	}
//	return 0;
//}

/*
2、查找两个字符串a，b中的最长公共子串
查找a b中的最长公共子串，若有多个，输出在较短串中最先出现的那个
例子：
	输入：
		abcdefghijklmnop
		abcsafjklmnopqrstuvw
	输出:
		jklmop
*/
/*
思路： 双指针遍历长串 以长串的每个单词作为开头去短字符串中寻找到这个单词 开始寻找公共子串
每次跟新最长子字符
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void publicSting(vector<string>& res,string& a,string& b){
	//i指向长字符串 j指向短字符串  a代表长字符串 b代表短字符串
	string tmp;
	int i = 0, j = 0, aSize = a.size(), bSize = b.size(), k = i, start = 0;
	while (i < aSize){
		while (j < bSize&&a[i]!=b[j]){
			++j;
		}
		      if (j<bSize&&a[k] == b[j]){
				//此时开始寻找
				  int startTmp = j;
				while (k < aSize&&j < bSize&&a[k] == b[j]){
					tmp += b[j];
					++k;
					++j;
				}
				if (res.empty()){
					start = startTmp;
					res.push_back(tmp);
				}
				else if(tmp.size()>res[0].size()){
						res.clear();
						start = startTmp;
						res.push_back(tmp);
					}
				else if(tmp.size()==res[0].size()){
					if (startTmp < start){
						res.clear();
						start = startTmp;
						res.push_back(tmp);
					}
				}
				tmp.clear();
			}
		j = 0;
		++i;
		k = i;
	}
}

int main(){
	string a, b;
	while (cin >> a >> b){
		vector<string> res;
		if (a.size() < b.size()){
			swap(a, b);
		}
		publicSting(res, a, b);
		cout << res[0] << endl;
	}
	return 0;
}