#define _CRT_SECURE_NO_WARNINGS 1

/*
1、计算日期到天数转换：
	根据输入的日期，计算是这一年的第几天
	输入某年某月某日，判断这一天是这一年的第几天？
输入描述：
	输入三行，年，月，日
	成功：返回输出计算后的第几天
	失败:返回-1
*/

#include<iostream>
using namespace std;

class Date{
public:
	Date(int year ,int mouth,int day)
	:_year(year)
	, _mouth(mouth)
	, _day(day)
	{}

	int fun(){
		int res = 0;
		int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};
		if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0){
			arr[2] = 29;
		}
		if (_year <= 0 || _mouth<0||_mouth>12 || _day <= 0||_day>arr[_mouth]){
			return -1;
		}
		for (int i = 1; i < _mouth; ++i){
			res += arr[i];
		}
		res += _day;
		return res;
	}
private:
	int _year;
	int _mouth;
	int _day;
};
//int main(){
//	int year = 0, mouth = 0, day = 0;
//	while (cin >> year >> mouth >> day){
//		Date d(year, mouth, day);
//		cout << d.fun() << endl;
//	}
//	return 0;
//}

/*
2、幸运的袋子
	一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。
如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例：如果袋子里面的球的号码是(1，1，2，3)，这个袋子就是幸运的，因为1+1+2+3>1*1*2*3
你可以适当从袋子里移除一些球（可以移除0个，但是别移除完），要使移除后的袋子是
幸运的。现在让你编程计算一下你可以获得多少种不同的幸运的袋子。

输入描述：
	第一行输入一个正整数n(n<=1000)
	第二行为n个正整数
输出描述：
	输出可以产生的幸运的袋子数
例子：
	3
	1 1 1

	输出：
		2
*/

/*
思路：回溯法 
*/

//方法一：使用了_add和_mul数组去记录拿取的结果，然后每次将结果存储在vv中，最终右将VV中的数组转化为string，使用
//set去重  时间复杂度大大超出  无法AC  （总体思路没问题，但是具体的实现过于复杂，但是强行用set去重这种方法，也有参考价值 保留该代码 ）
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
bool check(vector<int>& add,vector<int>mul){
	int _add = 0;
	int _mul = 1;
	for (size_t i = 0; i < add.size(); ++i){
		_add += add[i];
	}
	for (size_t i = 0; i<mul.size(); ++i){
		_mul *= mul[i];
	}
	if (_add>_mul){
		return true;
	}
	return false;
}

void dfs(vector<vector<int>>&vv,vector<int>& map,vector<int>_add,vector<int>_mul,int depth){
	if (depth == map.size()-1){
		//不能全部拿出
		if (check(_add,_mul)){
			//将其放入vv中
			vv.push_back(_add);
		}
		return;
	}
	_add[depth] = 0; //从加法数组中拿出
	_mul[depth] = 1;//从乘法数组中拿出
	dfs(vv,map, _add,_mul, depth + 1);
	//回溯
	_add[depth] = map[depth];
	_mul[depth] = map[depth];
	dfs(vv,map, _add,_mul, depth + 1);
}
//int main(){
//	int n = 0, a = 0;
//	while (cin >> n){
//		vector<int> map;
//		vector<int> _add;
//		vector<int> _mul;
//		vector<vector<int>> vv;
//		for (int i = 0; i < n; ++i){
//			cin >> a;
//			map.push_back(a);
//		}
//		_add = map;
//		_mul = map;
//		dfs(vv, map, _add, _mul, 0);
//		//去重,将VV中相同的数组去掉；
//		vector<string> ss;
//		for (size_t i = 0; i < vv.size(); ++i){
//			sort(vv[i].begin(), vv[i].end());
//			string s;
//			for (size_t j = 0; j < vv[i].size(); ++j){
//				s += to_string(vv[i][j]);
//			}
//			ss.push_back(s);
//		}
//		set<string> t(ss.begin(), ss.end());
//		cout << t.size() << endl;
//	}
//	return 0;
//}


/*
方法二： 分析方法一，时间复杂度过高，如何减少时间复杂度呢?
	将原始数组按照递增提前排序，便于剪枝操作
	从map[0]开始 拿到这个球 ，然后去遍历当袋子中有这个球的全部排列组合  找完以后将其放下 又从map[1]开始
	以此类推
 分析题目，	情况一：当前a+b>a*b 符合题意 res++  可以进行下一步的递归
			情况二：当下一个数字为1 显然加法式子会变大 程法式子不变，递归下去可能找到正确答案，可以进行下一步递归
			情况三：既不满足福袋要求（+ < *），下一个数字又不为1 ，而该数组为递增序列，继续递归下去一定乘法越来越大
			,肯定没有正确答案，进行剪枝
 
 */
void dfs(vector<int>&map, int depth, int& res,int _add,int _mul){
	size_t len = map.size();
	for (size_t i = depth; i < len; ++i){
		_add += map[i];
		_mul *= map[i];
		if (_add>_mul){
			++res;
			dfs(map, i + 1, res, _add, _mul);
		}
		else if (map[i] == 1){
			dfs(map, i + 1, res, _add, _mul);
		}
		else{
			break;  //进行剪枝
		}
		//回溯
		_add -= map[i];
		_mul /= map[i];
		//去重 如果下一个数字和当前数字一致 就没必要进行判断
		while (i < len - 1 && map[i] == map[i + 1]){
			++i;
		}
	}
}
//int main(){
//	int n = 0, a = 0;
//  while (cin >> n){
//	 vector<int>map;
//	 int res = 0;
//	 for (int i = 0; i < n; ++i){
//		cin >> a;
//		map.push_back(a);
//	 }
//	 sort(map.begin(), map.end());
//	 dfs(map, 0, res, 0, 1);
//	 cout << res << endl;
//  }
//	return 0;
//}

