#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1、红与黑（牛客）
有一间长方形的房子，地上铺满了红色黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，
只能向相邻（上下左右四个方向）黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色
的瓷砖。
输入描述:
	每组数据第一行是两个整数，m和n(1<=m,n<=20)。紧接着m行，每行包括n个字符。每个字符表示
	一块瓷砖颜色，规则如下:
		1."."黑色
		2."#"白色
		3."@"黑色，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次
		....#.
		.....#
		......
		......
		......
		......
		......
		#@...#
		.#..#.

输出描述:
	对应每组数据，输出总共能够到达多少块黑色的瓷砖
*/

/*
思路：dfs (此题不用回溯，因为判断的不是最长路径 而是总共能到达多少块黑色瓷砖)
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool check(vector<string>& map, int& m, int& n, int i, int j){
	if (i < m&&i>=0&&j<n&&j>=0&&map[i][j]=='.'){
		return true;
	}
	return false;
}
void dfs(vector<string>& map, int& m, int& n, int i, int j, int& res){
	if (!check(map, m, n, i, j)){
		return;
	}

	++res;
	map[i][j] = '#';//涂白

	//上
	dfs(map, m, n, i - 1, j, res);
	//下
	dfs(map, m, n, i + 1, j, res);
	//左
	dfs(map, m, n, i, j - 1, res);
	//右
	dfs(map, m, n, i , j+1, res);

}

int main(){
	int m = 0, n = 0;
	while (cin >> m >> n){
		cin.ignore();
		vector<string> map;
		string tmp;
		for (int i = 0; i < m; ++i){
			getline(cin, tmp);
			map.push_back(tmp);
		}
		//寻找起点
		int row = 0, col = 0, flag = 0;
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (map[i][j] == '@'){
					map[i][j] = '.';
					row = i;
					col = j;
					flag = 1;
					break;
				}
			}
			if (flag){
				break;
			}
		}
		//寻找黑色路径
		int res = 0;
		dfs(map, m, n, row, col, res);
		cout << res << endl;
	}
	return 0;
}

/*
2、蘑菇阵
现在有两个好友A、B住在一片长有蘑菇的由n*m个放个组成的草地上，A在（1，1），B在（n，m）。
现在A要拜访B，由于他只想去B家，所以他只会走（i，j+1）或（i+1，j）这样的路线，在草地上
有k个蘑菇种在格子里(多个蘑菇可能在同一方格)，问：A如果每一步随机选择的话（若她在边界上，
则只有一种选择），问：A如果每一步随机选择的话（若他在边界上。则只有一种选择）那么他
不碰到蘑菇走到B家的概率是多少？

输入描述:
	第一行N M，K（1<=N,M<=20,k<=100）,N M为草地大小，接下来K行，每行两个整数X,Y，
	代表（x，y）有一个蘑菇
输出描述：
	输出一行，代表所求概率(保留两位小数)
*/

/*
思路： 动态规划
	1.只能向下和向右走
	2.[0,0]概率为1
	3.当第一行时，例如[0,1]，当前路径的概率来源只有其左的一半即[0,0]*0.5
	4.当最后一行，例如[n-1,1],当前路径的概率来源有其左,上，且左只能向右走 即[n-1,0]+[n-2,1]*0.5
	5.第一列时，和3相似
	6.最后一列，和4相似
	7.普通情况，例如2<n,3<m, 当前路径的概率来源为其上+左，即[1,3]*0.5+[2,2]*0.5
*/

#include<iostream>
#include<vector>
using namespace std;
int main(){
	int N = 0, M = 0, K = 0;
	while (cin >> N >> M >> K){
		vector<vector<int>> map;
		vector<vector<double>> dp;
		map.resize(N+1);
		dp.resize(N+1);
		for (int i = 0; i <= N; ++i){
			map[i].resize(M+1, 0);
			dp[i].resize(M+1, 0);
		}
		for (int z = 0; z < K; ++z){
			int i = 0, j = 0;
			cin >> i >> j;
			map[i][j] = 1;//种蘑菇
		}
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= M; ++j){
				//[0,0]概率为1
				if (i == 1 && j == 1){ dp[i][j] = 1; }
				//有蘑菇
				else if (map[i][j]){ dp[i][j] = 0; }
				//到达终点
				else if (i == N  && j == M ){ dp[i][j] = dp[i][j - 1] + dp[i - 1][j]; }
				//最后一行
				else if (i == N ){ dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1]; }
				//最后一列
				else if (j == M ){ dp[i][j] = dp[i - 1][j] + dp[i][j - 1] * 0.5; }
				//第一行
				else if (i == 0){ dp[i][j] = dp[i][j - 1] * 0.5; }
				//第一列
				else if (j == 0){ dp[i][j] = dp[i - 1][j] * 0.5; }
	
				//普通情况
				else{
					dp[i][j] = dp[i][j - 1] * 0.5 + dp[i - 1][j] * 0.5;
				}
			}
		}
		printf("%.2f\n", dp[N][M]);
	}
	return 0;
}



