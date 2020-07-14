#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1������ڣ�ţ�ͣ�
��һ�䳤���εķ��ӣ����������˺�ɫ��ɫ������ɫ�������δ�ש����վ������һ���ɫ�Ĵ�ש�ϣ�
ֻ�������ڣ����������ĸ����򣩺�ɫ��ש�ƶ�����дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ
�Ĵ�ש��
��������:
	ÿ�����ݵ�һ��������������m��n(1<=m,n<=20)��������m�У�ÿ�а���n���ַ���ÿ���ַ���ʾ
	һ���ש��ɫ����������:
		1."."��ɫ
		2."#"��ɫ
		3."@"��ɫ��������վ������ש�ϡ����ַ���ÿ�����ݼ�����Ψһ����һ��
		....#.
		.....#
		......
		......
		......
		......
		......
		#@...#
		.#..#.

�������:
	��Ӧÿ�����ݣ�����ܹ��ܹ�������ٿ��ɫ�Ĵ�ש
*/

/*
˼·��dfs (���ⲻ�û��ݣ���Ϊ�жϵĲ����·�� �����ܹ��ܵ�����ٿ��ɫ��ש)
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
	map[i][j] = '#';//Ϳ��

	//��
	dfs(map, m, n, i - 1, j, res);
	//��
	dfs(map, m, n, i + 1, j, res);
	//��
	dfs(map, m, n, i, j - 1, res);
	//��
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
		//Ѱ�����
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
		//Ѱ�Һ�ɫ·��
		int res = 0;
		dfs(map, m, n, row, col, res);
		cout << res << endl;
	}
	return 0;
}

/*
2��Ģ����
��������������A��Bס��һƬ����Ģ������n*m���Ÿ���ɵĲݵ��ϣ�A�ڣ�1��1����B�ڣ�n��m����
����AҪ�ݷ�B��������ֻ��ȥB�ң�������ֻ���ߣ�i��j+1����i+1��j��������·�ߣ��ڲݵ���
��k��Ģ�����ڸ�����(���Ģ��������ͬһ����)���ʣ�A���ÿһ�����ѡ��Ļ��������ڱ߽��ϣ�
��ֻ��һ��ѡ�񣩣��ʣ�A���ÿһ�����ѡ��Ļ��������ڱ߽��ϡ���ֻ��һ��ѡ����ô��
������Ģ���ߵ�B�ҵĸ����Ƕ��٣�

��������:
	��һ��N M��K��1<=N,M<=20,k<=100��,N MΪ�ݵش�С��������K�У�ÿ����������X,Y��
	����x��y����һ��Ģ��
���������
	���һ�У������������(������λС��)
*/

/*
˼·�� ��̬�滮
	1.ֻ�����º�������
	2.[0,0]����Ϊ1
	3.����һ��ʱ������[0,1]����ǰ·���ĸ�����Դֻ�������һ�뼴[0,0]*0.5
	4.�����һ�У�����[n-1,1],��ǰ·���ĸ�����Դ������,�ϣ�����ֻ�������� ��[n-1,0]+[n-2,1]*0.5
	5.��һ��ʱ����3����
	6.���һ�У���4����
	7.��ͨ���������2<n,3<m, ��ǰ·���ĸ�����ԴΪ����+�󣬼�[1,3]*0.5+[2,2]*0.5
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
			map[i][j] = 1;//��Ģ��
		}
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= M; ++j){
				//[0,0]����Ϊ1
				if (i == 1 && j == 1){ dp[i][j] = 1; }
				//��Ģ��
				else if (map[i][j]){ dp[i][j] = 0; }
				//�����յ�
				else if (i == N  && j == M ){ dp[i][j] = dp[i][j - 1] + dp[i - 1][j]; }
				//���һ��
				else if (i == N ){ dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1]; }
				//���һ��
				else if (j == M ){ dp[i][j] = dp[i - 1][j] + dp[i][j - 1] * 0.5; }
				//��һ��
				else if (i == 0){ dp[i][j] = dp[i][j - 1] * 0.5; }
				//��һ��
				else if (j == 0){ dp[i][j] = dp[i - 1][j] * 0.5; }
	
				//��ͨ���
				else{
					dp[i][j] = dp[i][j - 1] * 0.5 + dp[i - 1][j] * 0.5;
				}
			}
		}
		printf("%.2f\n", dp[N][M]);
	}
	return 0;
}



