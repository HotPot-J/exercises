#define _CRT_SECURE_NO_WARNINGS 1

/*
1、五子棋（牛客）
给你一个棋盘，判断有没有五子连珠（超过5颗也算）

输入描述：
	输入有多组数据，每组数据为一张20x20的棋盘
	其中黑子用“*”表示，白子用“+”表示 空白用.表示

输出描述：
	如果棋盘上存在五子连珠（无论哪种颜色的棋子），输出yes否则输出No
	
*/

/*
2、Emacs计算器
Emacs号称神的编辑器，它自带了一个计算器，与其他计算器不同，它是基于后缀表达式的，即
运算符在操作数后面。例如：2 3 + 等价于2+3
请你实现一个后缀表达式的计算器

输入描述：
	输入包含多组数据
	每组数据包括两行：第一行是一个正整数n(3<=n<=50)；紧接着第二行包含n个由数值和运算符
	组成的列表。
"+ - * /"

输出描述：
	对应每一组数据，输出他们的运算结果

*/

/*
思路:	将数据存在队queue中 
		每次出队：
		1.当出队为数字，直接进stack
		2.当遇见一个运算符 直接对前两个数字进行运算 然后pop两次 将运算结果入栈
		3.最终栈顶元素即为答案
*/

#include<iostream>
#include<deque>
#include<stack>
#include<string>
using namespace std;

int main(){
	int n = 0;
	while (cin>>n){
		deque<string> q;
		stack<int> s;
		string tmp;
		for (int i = 0; i < n; ++i){
			cin >> tmp;
			q.push_back(tmp);
		}
		for (int i = 0; i < n; ++i){
			string a = q.front();
			q.pop_front();
			if (a == "+"){
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				s.push(num1 + num2);
			}
			else if (a == "-"){
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				s.push(num2 - num1);
			}
			else if (a == "*"){
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				s.push(num1 * num2);
			}
			else if (a == "/"){
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				s.push(num2 / num1);
			}
			else{
				int num = 0;
				for (size_t i = 0; i < a.size(); ++i){
					num = num * 10 + (a[i] - '0');
				}
				s.push(num);
			}
		}
		cout << s.top() << endl;
	}
	return 0;
}