#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1、解读密码
nowcoder要和朋友交流一些铭=敏感信息，需要在这些信息中掺入一些额外符号，让他们看起来
像乱码。
现在请你帮忙开发一款程序，解析从nowcoder那里接收到的信息，读取出中间有用的信息。

输入描述:
	每一行有一段经过加密的信息(可能有空格)，比并且原始信息长度不确定

输出描述:
	输出每段信息中的数字信息
*/

/*
思路:简单的字符串匹配
*/

#include<iostream>
#include<string>
using namespace std;

//int main(){
//	string a;
//	while (getline(cin, a)){
//		string res;
//		size_t len = a.size();
//		for (size_t i = 0; i < len; ++i){
//			if (a[i] >= '0'&&a[i] <= '9'){
//				res += a[i];
//			}
//		}
//		cout << res << endl;
//	}
//	
//	return 0;
//}


/*
2、走迷宫
nc最喜欢游乐场的迷宫游戏，他和小伙伴们比赛谁先走出迷宫。现在把迷宫的地图给你，你们能
帮他算出最快走出迷宫需要多少步吗？
输入描述:
	每组数据包含一个10*10，由“#”和“.”组成的迷宫。其中“#”代表墙；
	“.”代表通路。
	入口在第一行第二列，出口在最后一行第九列
	上下左右都能走
输出描述:
	对应每组数据，输入从入口到出口最短需要几步。
	
*/

/*
思路：回溯+dfs+剪枝
*/
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

bool check(vector<string>& map,int i,int j){
	if (i<0 || i>9 || j<0 || j>9 || map[i][j] == '#'){
		return false;
	}
	return true;
}
void dfs(vector<string>& map, int i, int j, int tmp, int& res){
	if (i == 9 && j == 8){
		//到达目的地
		if (tmp < res){
			res = tmp;
		}
		return;
	}
	if (!check(map,i,j)){
		//当前路径不可行
		return;
	}
	if (tmp>res){
		//当前结果大于res直接剪枝
		return;
	}
	//当前路径可行
	map[i][j] = '#'; //记录走过的路径
	++tmp;
	
	//上
	dfs(map, i - 1, j, tmp, res);

	//下
	dfs(map, i + 1, j, tmp, res);

	//左
	dfs(map, i , j-1, tmp, res);

	//右
	dfs(map, i , j+1, tmp, res);

	//回溯
	map[i][j] = '.';
	--tmp;

}
int main(){
	vector<string> map;
	while (1){
		for (int i = 0; i < 10; ++i){
			string tmp;
			cin >> tmp;
			map.push_back(tmp);
		}
		int res = INT_MAX;
		dfs(map, 0, 1, 0, res);
		cout << res << endl;
	}
	return 0;
}