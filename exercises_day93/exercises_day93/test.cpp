#define _CRT_SECURE_NO_WARNINGS 1

/*
1、Fibnacci数列是这样定义的：
 F[0] = 0
 F[1] = 1
 for eachi>=2 : F[i] = F[i-1]+F[i-2]
 因此 斐波那契数列:0 1 1 2 3 5 8 13...，在斐波那契数列中的数我们称之为斐波那契数。
 现有一个数字N，你想让其变为一个Fibonacci，每一步你可以把当前的数字X变为X-1或者X+1，现
 给你一个数N，求最少需要多少步可以变为斐波那契数。
 输入描述: 
	输入为一个整数(1<=1 000 000)
 输出描述：
	输入一个最小的步数变为斐波那契数
示例：
	15
输出 2
*/

//思路: 首先排除递归去写斐波那契数（成本太高），采用 F[i] = F[i-1]+F[i-2]的递推公式去将斐波那契
//数列存在一个数组中，当寻找到 F[i]<= N <=F[i](当=时，结果即为0步)，然后计算齐差值 取较小的为结果
#include<iostream>
#include<vector>
using namespace std;
int Fibonacci(int N){
	vector<int> arr;
	arr.resize(1000000);
	arr[0] = 0;
	arr[1] = 1;
	int i = 2;
	if (N == 0 || N == 1){
		return 0;
	}
	while (1){
		arr[i] = arr[i - 1] + arr[i - 2];
		if (arr[i - 1] <= N&&arr[i] >= N){
			//N介于其之间
			if (arr[i - 1] == N || arr[i] == N){
				return 0;
			}
			int a = N - arr[i - 1];
			int b = arr[i] - N;
			return a < b ? a : b;
		}
		++i;
	}
}
//int main(){
//	int N = 0;
//	cin >> N;
//	cout << Fibonacci(N) << endl;
//	return 0;
//}

/*
2、对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
一个合法的括号串定义为:1.只包括括号字符。2.左括号和右括号一一对应
例子:
	"(()())",6
	返回：true

	"()a()()",7
	返回：false

	"()(()()",7
*/

//思路一：使用栈解决问题 字符串A的元素依次入栈匹配上直接出栈 最终栈为空则全部匹配成功
#include<stack>
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		if (A.size() <= 0){
			return false;
		}
		stack<char> tmp;
		char* str = (char*)A.c_str();
		while (*str){
			if (*str != '('&&*str != ')'){
				return false;
			}
			if (tmp.empty()){
				tmp.push(*str);
			}
			else{
				if (*str == ')'&&tmp.top() == '('){
					//匹配上一对
					tmp.pop();
				}
				else if (*str == '('&&tmp.top() == '('){
					tmp.push(*str);
				}
			}
			++str;
		}
		if (tmp.empty()){
			return true;
		}
			return false;
	}
};

int main(){
	string s = "()(()()";
	Parenthesis a;
	a.chkParenthesis(s, 0);
	return 0;
}