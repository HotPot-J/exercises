#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1���������
nowcoderҪ�����ѽ���һЩ��=������Ϣ����Ҫ����Щ��Ϣ�в���һЩ������ţ������ǿ�����
�����롣
���������æ����һ����򣬽�����nowcoder������յ�����Ϣ����ȡ���м����õ���Ϣ��

��������:
	ÿһ����һ�ξ������ܵ���Ϣ(�����пո�)���Ȳ���ԭʼ��Ϣ���Ȳ�ȷ��

�������:
	���ÿ����Ϣ�е�������Ϣ
*/

/*
˼·:�򵥵��ַ���ƥ��
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
2�����Թ�
nc��ϲ�����ֳ����Թ���Ϸ������С����Ǳ���˭���߳��Թ������ڰ��Թ��ĵ�ͼ���㣬������
�����������߳��Թ���Ҫ���ٲ���
��������:
	ÿ�����ݰ���һ��10*10���ɡ�#���͡�.����ɵ��Թ������С�#������ǽ��
	��.������ͨ·��
	����ڵ�һ�еڶ��У����������һ�еھ���
	�������Ҷ�����
�������:
	��Ӧÿ�����ݣ��������ڵ����������Ҫ������
	
*/

/*
˼·������+dfs+��֦
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
		//����Ŀ�ĵ�
		if (tmp < res){
			res = tmp;
		}
		return;
	}
	if (!check(map,i,j)){
		//��ǰ·��������
		return;
	}
	if (tmp>res){
		//��ǰ�������resֱ�Ӽ�֦
		return;
	}
	//��ǰ·������
	map[i][j] = '#'; //��¼�߹���·��
	++tmp;
	
	//��
	dfs(map, i - 1, j, tmp, res);

	//��
	dfs(map, i + 1, j, tmp, res);

	//��
	dfs(map, i , j-1, tmp, res);

	//��
	dfs(map, i , j+1, tmp, res);

	//����
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