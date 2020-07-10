#define _CRT_SECURE_NO_WARNINGS 1

/*
1、年会抽奖（牛客）
	1.所有人员将自己的名字放入箱子
	2.待所有字条加入完毕，每个人从箱子中取一个字条
	3.如果抽到的字条是自己的名字，则中奖
现告诉你参加晚会的人数，请你计算有多少概率出现无人中奖？
*/


/*
思路:古典概型   无放回的情况下： 
首先分母为所有抽奖的可能性的个数即c(n,1)*c(n-1,1)...c(1,1)即n！
未中奖事件发生的个数:
	1.当每次都是相邻两两互拿对方的字条 则接下来的问题变为 （n-1）* f(n-2)
	2.否则问题变为（n-1）* f（n-1）
	则可得递推公式为 f(n) = (n-1)*(f(n-1)+f(n-2))
*/
#include<iostream>
using namespace std;

//算阶乘
double factorial(int n){
	if (n==0||n == 1){
		return 1;
	}
	return n*factorial(n - 1);
}

//算未中奖时间发生个数
double func(int n){
	if (n == 1){
		//必中奖 未中奖时间发生个数为0
		return 0;
	}
	if (n == 2){
		//终奖和不中奖个数各为1
		return 1;
	}
	return (n - 1)*(func(n - 1) + func(n - 2));
}
//int main(){
//	int n = 0;
//	while (cin >> n){
//		double res = (func(n) / factorial(n)) * 100;
//		printf("%.2f%c\n", res, '%');
//	}
//	return 0;
//}

/*
2、抄送列表（牛客）
nc每天要处理很多邮件，但它并不是在收件人列表中，有时候只是被抄送。他认为这些抄送
的邮件重要性比自己在收件人列表里的低，因此他要过滤次要的邮件，优先处理重要邮件
现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。
输入描述：
	输入有多组数据，每组数据有两行。
	第一行抄送列表，姓名之间用逗号隔开，如果姓名中包含空格或者逗号，则姓名包含在
	双引号里
输出描述:
	如果第二行的名字出现在收件人列表中，则输出"Ignore"，表示不重要，否则输出
	"Important"
*/

/*
思路:字符串分割问题
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void func(string& str, vector<string>& map){
	//将每个名字存进map中
	int i = 0, len = str.size();
	while (i < len){
		string tmp;
		if (str[i] == '\"'){
			++i;
			while (i<len&&str[i] != '\"'){
				tmp += str[i];
				++i;
			}
			++i;
		}
		else{
			while (i < len&&str[i] != ','){
				tmp += str[i];
				++i;
			}
		}
		map.push_back(tmp);
		++i;
	}
}

int main(){
	string a, b;
	while (getline(cin, a)){
		getline(cin, b);
		vector<string> map;
		func(a, map);
		cout << ((find(map.begin(), map.end(), b) != map.end()) ? "Ignore" : "Important!") << endl;
		a.clear();
	}
	return 0;
}

