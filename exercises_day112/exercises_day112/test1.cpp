#define _CRT_SECURE_NO_WARNINGS 1

/*
牛客：年终奖
*/

/*
思路:dfs 回溯寻找最优解
*/

#include<iostream>
#include<vector>
using namespace std;

class Bonus {
public:
	void dfs(vector<vector<int>> board, int i, int j, int& res, int tmp){
		if (i >= 6 || j >= 6){
			//越界
			if (tmp > res){
				res = tmp;
			}
			return;
		}
		//向右
		if (board[i][j] != -1){
			tmp += board[i][j];
			int flag = board[i][j];
			board[i][j] = -1;
			dfs(board, i, j + 1, res, tmp);
			//回溯
			board[i][j] = flag;
			tmp -= flag;
		}
		//向下
		if (board[i][j] != -1){
			tmp += board[i][j];
			int flag = board[i][j];
			board[i][j] = -1;
			dfs(board, i + 1, j, res, tmp);
			board[i][j] = flag;
			tmp -= flag;
		}
	}
	int getMost(vector<vector<int>> board) {
		int res = 0;
		dfs(board, 0, 0, res, 0);
		return res;
	}
};

/*
2、牛客 迷宫问题
*/

/*
思路：dfs 回溯 寻找最短路径
*/
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> map;
vector<vector<int>> res;
vector<vector<int>> tmp;
void dfs( int i, int j,int& n,int& m){
	//走当前路径
	vector<int> flag = { i, j };
	map[i][j] = 1;
	tmp.push_back(flag);

	if (i == n - 1 && j == m - 1){
		//走通迷宫
		if (res.empty()){
			res = tmp;
		}
		else if (res.size() > tmp.size()){
			res = tmp;
		}
		return;
	}
	//上
	if (i - 1 >= 0 && map[i - 1][j] == 0){
		dfs( i - 1, j, n, m);
	}

	//下
	if (i + 1 < n&&map[i + 1][j] == 0){
		dfs( i + 1, j, n, m);
	}

	//左
	if (j - 1 >= 0 && map[i][j - 1] == 0){
		dfs( i, j - 1, n, m);
	}

	//右
	if (j + 1 < m&&map[i][j + 1]==0){
		dfs(i, j + 1, n, m);
	}
	//回溯
	map[i][j] = 0;
	tmp.pop_back();
}
int main(){
	int n = 0, m = 0;
	while (cin >> n >> m){
		map = vector<vector<int>>(n, vector<int>(m, 0));
		res.clear();
		tmp.clear();
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> map[i][j];
			}
		}
		dfs(0, 0,n,m);
		for (int i = 0; i < res.size(); ++i){
			cout << "(" << res[i][0] << "," << res[i][1] << ")" << endl;
		}
	}
	return 0;
}