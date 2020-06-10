#define _CRT_SECURE_NO_WARNINGS 1

/*
1、另类加法，请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
给定两个intA和B。请返回A+B的值
例：
	1，2
	3
*/
/*
思路：采用位运算符  
^相当于两数相加当前位置产生进位之后各位当前结果：2^3 = (010)^(011) = 001 
&相当于两数相加当前位置是否产生进位：2&3 =(010)&(011) = 010 说明第二位需要进位 将其左移达到进位的效果 010<<1 = 100
如果当两数相&后的结果为0，则各位均不产生进位，则达到了加法的效果
*/

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0, tmp = 0;
		while (B != 0){
			sum = A^B;
			tmp = (A&B) << 1;
			A = sum;
			B = tmp;
		}
		return sum;
	}
};

/*
2、请编写一个函数（允许增加子函数），计算n x m的棋盘格子(n为横向的格子数，m为竖向的格子数)
沿着各自边缘线从左上角走到又下角，总共有多少方法，不能走回头路（只能往右和往下走）
输入：两个正整数
输出：返回结果
例：
输入：	2
	    2
输出:	6
*/

//思路：根据题意得出该状态转移方程 f(n,m) = f(n,m-1)+f(n-1,m)  可以采用递归

//方法一：递归
#include<iostream>
using namespace std;
int fun1(int n, int m){
	if (n == 0 || m == 0){
		return 1;
	}
	return fun1(n, m - 1) + fun1(n - 1, m);
}

//int main(){
//	int n = 0, m = 0;
//	while (cin >> n >> m){
//		cout << fun1(n, m) << endl;
//	}
//	return 0;
//}

/*方法2：尝试使用回溯法  由于是走边 而不是走格子 
2行2列的格子，根据边分 （0，0）点 （0，1）点 。。。。 （2，2）点 ，可以类比出一个3行3列的二维数组，用来作为回溯的map
*/

#include<iostream>
#include<vector>
using namespace std;

int res = 0;
vector<vector<int>> map;
bool check(int i,int j,int n,int m){
	if (i < n&&j < m&&map[i][j] == 0){
		return true;
	}
	return false;
}

void dfs(int i, int j, int n, int m){
	if (i == n - 1 && j == m - 1){
		//找到正确路线
		++res;
		return;
	}
	if (i >= n || j >= m){
		//越界
		return;
	}
	if (check(i, j, n, m)){
		//当前路线可走
		map[i][j] = 1;
	}
	dfs(i, j + 1, n, m);//向右走
	dfs(i + 1, j, n, m);//向下走
	map[i][j] = 0;//回溯
}
int main(){
	int n = 0, m = 0;
	while (cin >> n >> m){
		map.resize(n + 1);
		for (int i = 0; i < n + 1; ++i){
			map[i].resize(m + 1, 0);
		}
		dfs(0, 0, n + 1, m + 1);
		cout << res << endl;
	}
	return 0;
}