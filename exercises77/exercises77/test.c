#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
1162. ��ͼ����
������������һ�ݴ�СΪ N x N �ġ���ͼ�������� grid�������ÿ�������򡹣���Ԫ�񣩶��� 0 �� 1 ��Ǻ��ˡ����� 0 ������1 ����½�أ������ҳ�һ������������������������������½������ľ��������ġ�

��������˵�ľ����ǡ������پ��롹�� Manhattan Distance����(x0, y0) �� (x1, y1) ����������֮��ľ����� |x0 - x1| + |y0 - y1| ��

������ǵĵ�ͼ��ֻ��½�ػ��ߺ����뷵�� -1��



ʾ�� 1��



���룺[[1,0,1],[0,0,0],[1,0,1]]
�����2
���ͣ�
�������� (1, 1) ������½������֮��ľ��붼�ﵽ���������Ϊ 2��
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

