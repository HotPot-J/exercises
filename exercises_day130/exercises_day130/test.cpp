#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
���ӣ�https://www.nowcoder.com/questionTerminal/ceb89f19187b4de3997d9cdef2d551e8
��Դ��ţ����

1���绰����
1 2 3
4 5 6
7 8 9
  0
��ͼ��һ���绰�ľŹ�����������һ�����ֶ�ӦһЩ��ĸ������ڹ�����ҵϲ���ѵ绰
������Ƴ����Լ���˾�������Ӧ�����繫˾��Help Desk������4357����Ϊ4��ӦH��3��
ӦE��5��ӦL��7��ӦP�����4357����HELP��ͬ��TUT-GLOP�ʹ���888-4567��310-GINO��
��310-4466��
NowCoder�ս������󣬲���ϰ��������������ʽ�����ڸ���һ���绰�����б�
�������ת����������ʽ�ĺ��룬��ȥ���ظ��Ĳ��֡�

��������:
��������������ݡ�

ÿ�����ݵ�һ�а���һ��������n��1��n��1024����

������n�У�ÿ�а���һ���绰���룬�绰����������ַ���-�������ֺʹ�д��ĸ��ɡ�
û���������ֵ����ַ��������ų����ַ��󳤶�ʼ��Ϊ7�������绰����ֻ��7λ����


�������:
��Ӧÿһ�����룬�����ֵ�˳��������ظ��ı�׼������ʽ�绰���룬����xxx-xxxx����ʽ��

ÿ���绰����ռһ�У�ÿ������֮�����һ��������Ϊ�������
*/

/*
˼·:
	1.�ù�ϣ˼�룬��a-zÿ���ַ���Ϊ�±꣬��Ӧ�����ִ��ڶ�Ӧ�±��Ԫ����
		����arr['a'] = 1; arr['b'] = 1;arr['c'] = 1;
	2.�����ֵ����ַ�ֱ������
	3.(���˰���û�ܹ� ������Ҫȥ�أ�����) ��set������,���û������� ��ֱ����
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<cctype>
#include<algorithm>
using namespace std;

int main(){
	int arr[256] = { 0 };
	for (int i = 'P'; i <= 'S'; ++i){
		arr[i] = 7;
	}
	for (int i = 'W'; i <= 'Z'; ++i){
		arr[i] = 9;
	}
	int j = 'A';
	for (int i = 2; i <= 8; ++i){
		if (i == 7){
			j += 4;
		}
		else{ 
			int tmp = j + 2;
			for (j; j <= tmp; ++j){
				arr[j] = i;
			}
		}
	}
	int n = 0;
	while (cin >> n){
		set<string> res;
		string c_name;
		string tmp1;
		for (int i = 0; i < n; ++i) {
			cin >> c_name;
			int len = c_name.size();
			for (int i = 0; i < len; ++i){
				if (tmp1.size() == 3){
					tmp1 += '-';
				}
				if (c_name[i] >= '0'&&c_name[i] <= '9'){
					tmp1 += c_name[i];
				}
				else if (c_name[i] == '-'){
					continue;
				}
				else{
					//��ĸ
					if (c_name[i] >= 'a'&&c_name[i] <= 'z'){
						c_name[i] = toupper(c_name[i]);
					}
					tmp1 += to_string(arr[c_name[i]]);
				}
			}
			res.insert(tmp1);
			tmp1.clear();
		}
		auto it = res.begin();
		while (it != res.end()){
			cout << *it << endl;
			++it;
		}
		cout << endl;
	}
	return 0;
}

/*
2.���

������������n��m��������1��2��3...n������ȡ��������ʹ��͵���m
Ҫ���������п��ܵ�����г���

����������
ÿ�������������2��������n��m

���������
��ÿ����ϵ��ֵ������������ÿ�����һ�����

����:
	5 5 
�����
	1 4
	2 3
	5
*/

/*
˼·: 
     1.���� Ѱ�Ҹ��ֿ��ܽ�
     2.��֦�� �����ظ�����
	 3.����������㣬��ֹ�ظ���
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

void dfs(set<vector<int>>& res, vector<int>& tmp,int begin, int& n,int target)
{
	if (target == 0){
		res.insert(tmp);
		return;
	}
	for (int i = begin; i <= n; ++i){
		if (target - i < 0){
			//���м�֦
			break;
		}
		tmp.push_back(i);
		target -= i;
		dfs(res, tmp, i + 1, n, target);
		tmp.pop_back();
		target += i;
	}
}
int main(){
	int n, m;
	while (cin >> n >> m){
		set<vector<int>> res;
		vector<int> tmp;
		dfs(res, tmp, 1, n, m);
		auto it = res.begin();
		while (it != res.end()){
			int len = (*it).size();
			for (int i = 0; i < len - 1; ++i){
				cout << (*it)[i] << " ";
			}
			cout << (*it)[len - 1] << endl;
			++it;
		}
	}
	return 0;
}
