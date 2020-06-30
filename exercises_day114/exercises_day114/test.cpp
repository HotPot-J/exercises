#define _CRT_SECURE_NO_WARNINGS 1

/*
1、变态跳台阶
一只青蛙一次可以挑上1级台阶，也可以跳上2级....它也可以挑上n级。求该青蛙
挑上一个n级台阶有多少种方法
*/


/*
思路：回溯+剪枝  （该题与leetcode 39.数组总和类似 只不过这里更简单 是有序的1-n，
且只用算方法总数不必保留具体方案,由于需要每一种方案比如：（1 2） （2 1）都算做方案 所以不需要进行搜索起点设计（剪枝）
只需要再（number-i<0的时候进行剪枝即可）
）
*/
#include<iostream>
using namespace std;
class Solution {
public:
	int _res = 0;
	int jumpFloorII(int number) {
		dfs( number,number);
		return _res;
	}
	void dfs(int number,int n){
		if (number == 0){
			//找到可行解
			++_res;
			return;
		}
		for (int i = 1 ; i <= n; i++){
			if (number - i < 0){
				//剪枝 当前n-i小于0 那么后边的数字也不符合条件
				break;
			}
			number -= i;
			dfs(number,n);
			//回溯
			number += i;
		}
	}
};

//int main(){
//	Solution a;
//	cout<<a.jumpFloorII(3)<<endl;
//	return 0;
//}

/*
2、快到碗里来
小喵们很喜欢把自己装进容器里(例如碗)，但是要是碗的周长比喵的身长短，他们就进不去了
现在告诉你他们的身长和碗的半径，请判断能否到碗里去？

输入：
	两个整数 n( 1<=n<=2^128) r( 1<=r<=2^128)  分别代表喵的身长和碗的半径
	圆周率3.14
输出:
	能进就输出YES 不能就NO
*/

/*
思路: 该题应该用long double 进行比较 int会溢出
*/

#include<iostream>
using namespace std;
int main()
{
	long double n;
	long double r;
	while (cin >> n >> r)
	{
		if (n <= 2 * 3.14*r)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}