#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1��ƹ�����
nc�����У�A,B��ƹ�����к�˫ϲ�ģ��������ǵ�...��������Ҫ�б�A���Ƿ������B��������
�����࣬����ÿ���������������B���е�����������ô���أ�

��������:
	�����ж������ݡ�
	ÿ�����ݰ��������ַ���A,B������A����B���е�ƹ����ÿ��ƹ������һ����д��ĸ��ʾ��
	����ͬ���͵�ƹ����Ϊ��ͬ�Ĵ�д��ĸ��
�ַ������Ȳ�����10000

�������:
	ÿһ�����붼��Ӧһ�����:���B�������е���������A�ж��У�����ÿ�����������������
	A���������Yes��;���������No����

����:
����:
	ABCDFYE CDE
	ABCDGEAS CDECDE
���:
	Yes
	No
*/

/*
˼·:  ��ϣ
*/
//
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
	string a, b;
	while (cin >> a >> b){
		unordered_map<char, int> a_map;
		unordered_map<char, int> b_map;
		int Asize = a.size();
		int Bsize = b.size();
		for (int i = 0; i < Asize; ++i){
			++a_map[a[i]];
		}
		for (int i = 0; i < Bsize; ++i){
			++b_map[b[i]];
		}
		int flag = 1;
		for (int i = 0; i < Bsize; ++i){
			if (a_map.find(b[i]) == a_map.end()){
				flag = 0;
				break;
			}
			if (a_map[b[i]] < b_map[b[i]]){
				flag = 0;
				break;
			}
		}
		if (flag){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}

/*
2�������ֵܵ���(ţ��)

��Ŀ����:
	ʵ��һ���ɴ洢���ɸ����ʵ��ֵ䡣�û����ԣ�
		1.���ֵ��м��뵥��
		2.����ָ���������ֵ��е��ֵܵ��ʸ���
		3.����ָ�����ʵ�ָ����ŵ��ֵܵ��ʣ�ָ�����ָ�ֵ����ֵܵ��ʰ��ֵ�
		˳��(�μ�page 3)���������(��1��ʼ)
		4.����ֵ������е���
	    ..........
*/

/*
˼·: ���� �ַ����Ƚ�
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int n = 0;
	while (cin >> n){
		vector<string> arr;
		string tmp;
		for (int i = 0; i < n; ++i){
			cin >> tmp;
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end());
		string aim;
		vector<string> res;
		int k = 0;
		cin >> aim >> k;
		int a = aim.size();
		string tmp1 = aim;
		sort(tmp1.begin(), tmp1.end());
		for (int i = 0; i < n; ++i){
			int b = arr[i].size();
			if (b == a&&aim!=arr[i]){
				tmp = arr[i];
				sort(tmp.begin(), tmp.end());
				if (tmp == tmp1){
					res.push_back(arr[i]);
				}
			}
		}
		if (!res.empty()){
			cout << res.size() << endl;
		}
		else{
			cout << 0 << endl;
		}
		if (res.size() >= k){
			cout << res[k - 1] << endl;
		}
	}
	return 0;
}