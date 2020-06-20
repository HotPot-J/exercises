#define _CRT_SECURE_NO_WARNINGS 1

/*
1、统计每个月兔子的总数
有一只兔子，从出生后第三个月起，每个月都生一只兔子，小兔子长到第三个月后，每个月
又生一只兔子，假如兔子都不死，问每个月兔子的总数为多少?
输入: 月份
输出：个数
*/

/*
思路: 一月：1 二月：1 三月： 2  四:3  五：5 六月:8...
总结其就为一个斐波那契数列 递归即可
*/
#include<iostream>
#include<vector>
using namespace std;
////递归版
//int rabbit1(int mouth){
//	if (mouth == 1 || mouth == 2){
//		return 1;
//	}
//	return rabbit1(mouth - 2) + rabbit1(mouth - 1);
//}
//递推版 （递推较递归效率更高 避免了很多重复计算）
int rabbit2(int mouth){
	vector<int> arr;
	arr.push_back(1); arr.push_back(1);
	if ((mouth)-1 <= 1){
		return 1;
	}
	int i = 2;
	while (i<mouth){
		arr.push_back(arr[i - 2] + arr[i - 1]);
		++i;
	}
	return arr[i-1];
}

//int main(){
//	int m = 0;
//	while (cin >> m){
//		cout<<rabbit2(m)<<endl;
//	}
//	return 0;
//}

/*
2、字符串通配符
题目描述:
	在计算机中，通配符是一种特殊语法，广泛用于文件搜索、数据库、正则表达式等领域。要求
	各位实现字符串通配符的算法。
	要求：
	实现如下2个通配符：
	*:匹配0或以上的字符(字符由英文和数字0-9组成，不区分大小写。下同)
	?:匹配1个字符

	输入：
		通配符表达式；
		一组字符串
	输出：
		返回匹配的结果，正确输出true 错误输出false
例子:
输入：
	te？t*.*
	txt12.xls
输出：
	false
*/

/*
思路一:暴力法：字符串比较的变型题 基本上就是双指针往后走 进行匹配即可 需要注意的是?匹配任意一个字符 *可匹配0个或多个字符

*/
#include<iostream>
#include<string>
using namespace std;

void _compare(string a, string b){
	int i = 0, j = 0,flag = 0, aSize = a.size(), bSize = b.size();
	while (i < aSize||j < bSize){
		 if (i<aSize&&a[i] == '*'){
			++i;
			flag = 1;//代表其上一个为*
		}
		 else if (a[i] == '?' || a[i] == b[j]){
			 //?代表任何字母 直接算做匹配成功
			 ++i;
			 ++j;
		 }
		 else if (flag){
			 while (a[i] != b[j]){
				 ++j;
			 }
			 flag = 0;
		 }
		else {
			cout << "false" <<endl;
			break;
		}
		if (i == aSize && j == bSize){
			//同时走到尽头代表匹配成功
			cout << "true" << endl;
			break;
		}
	}
}


/*思路二：递归解决
1.当遇到?问号或两字符相等 同时往后走一步
2.当遇到*
	*匹配0个||*匹配一个||*匹配多个
*/

int main(){
	string a, b;
	while (cin >> a >> b){
		_compare(a, b);
	}
	return 0;
}