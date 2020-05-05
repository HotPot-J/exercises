#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
1162. 地图分析
你现在手里有一份大小为 N x N 的「地图」（网格） grid，上面的每个「区域」（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，请你找出一个海洋区域，这个海洋区域到离它最近的陆地区域的距离是最大的。

我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。

如果我们的地图上只有陆地或者海洋，请返回 -1。



示例 1：



输入：[[1,0,1],[0,0,0],[1,0,1]]
输出：2
解释：
海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
*/

class Solution {
public:
	int maxDistance(vector<vector<int>>& grid) {
		int N = grid.size();
		int count_land = 0;
		int count_turn = 0;
		int count_last_space;
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				if (grid[i][j] == 1){
					count_land++;
				}
			}
		}
		if (count_land == N*N || count_land == 0){
			return -1;
		}
		count_last_space = N*N - count_land;
		while (count_last_space != 0){
			count_turn++;
			for (int i = 0; i<N; i++){
				for (int j = 0; j<N; j++){
					if (grid[i][j] == count_turn){
						if (i>0 && grid[i - 1][j] == 0){
							grid[i - 1][j] = count_turn + 1;
							count_last_space--;
						}
						if (i<N - 1 && grid[i + 1][j] == 0){
							grid[i + 1][j] = count_turn + 1;
							count_last_space--;
						}
						if (j>0 && grid[i][j - 1] == 0){
							grid[i][j - 1] = count_turn + 1;
							count_last_space--;
						}
						if (j<N - 1 && grid[i][j + 1] == 0){
							grid[i][j + 1] = count_turn + 1;
							count_last_space--;
						}
					}
				}
			}
		}
		return count_turn;
	}
};

