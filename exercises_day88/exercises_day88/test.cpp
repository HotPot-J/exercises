#define _CRT_SECURE_NO_WARNINGS 1

/*
组队竞赛
一个队伍的水平值为该队伍成员中第二高水平值 参加比赛的有3*n个选手
一个队伍水平值分别为3，3，3 队伍的水平值即为3
一个队伍水平值分别为3，2，3 队伍的水平值即为3

如果把6个队员分为1 2 5 和 5 5 8 水平值为2+5 = 7
                 2 5 8 和 1 5 5 水平值5+5 = 10
求出水平值最高的组队方法
输入描述:
	第一行一个正整数n
	第二行3*n个整数
输出:最大水平值总和	
*/

//思路：贪心算法 排序
//#include<iostream>
//#include<deque>
//#include<algorithm>
//using namespace std;
//int main(){
//	int n = 0;
//	int tmp = 0;
//	int res = 0;
//	deque<int> a;
//	cin >> n;
//	for (int i = 0; i < n * 3; ++i){
//		cin >> tmp;
//		a.push_back(tmp);
//	}
//	//排序 每次选出最大和次大的还有最小的出队 res+=次大的 
//	sort(a.begin(), a.end());
//	while (a.size() >= 3){
//		a.pop_back();//弹出最大
//		res += a.back();//记录水平
//		a.pop_back();//弹出次大
//		a.pop_front();//弹出最小
//	}
//	cout << res << endl;
//	return 0;
//}

/*
输入两个字符串，从第一个字符中删除第二个字符中所有的字符。例如：
They are students和aeiou 删除之后：Thy r stdnts
*/
/*
思路：哈希表+string中的erase（size_t pos,size_t n）函数(从pos位置删除n个字符)
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
	string a;
	string b;
	getline(cin,a);
	getline(cin, b);
	unordered_map<char, bool> m;
	for (auto it : b){
		m[it] = true;
	}
	for (size_t i = 0; i < a.size(); ++i){
		if (m[a[i]]){
			a.erase(i, 1);
		}
	}
	cout << a << endl;
	return 0;
}