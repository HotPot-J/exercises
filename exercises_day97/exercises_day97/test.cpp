#define _CRT_SECURE_NO_WARNINGS 1

/*
1�������������
��һ��������������������ڵ㰴���ڵ�һ��һ��Ĵ����������α�ţ����ڵ���Ϊ1.��������
���a��b�������һ���㷨�����a��b�������������ȵı�š�
��������int a bΪ�������ı�š��뷵��a b������������ȵı�š�ע������Ľ�㱾��Ҳ������
����
���ӣ�
	2 3
���أ�1
*/

/*˼· �ݹ飺������������������ �����ǹ��ɵĴ�������  ��ô�����Ϊ 
(��Ϊ���ڵ����Ϊ1�������Ƶ����Ƚ��Ĺ�ʽһ��) 
1.ż����Ϊ������Ѱ�����Ƚ��Ĺ�ʽ: x/2  
2.������Ϊ������Ѱ�����Ƚ��Ĺ�ʽ: x/2
3.��С���п��������Ƚ�㣬��������ϴ������Ѱ�� ���εݹ���ȥ
*/

#include<iostream>
using namespace std;
class LCA {
public:
	int getLCA(int a, int b) {
		int _min = a < b ? a : b;
		int _max = a>b ? a : b;
		if (a == b){
			return a;
		}
		return getLCA(_min, _max / 2);
	}
};

//int main(){
//	lca a;
//	a.getlca(6, 7);
//	return 0;
//}


/*
2���������bit��
����:��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����λ00000011�У��������
2��1
���룺һ��byte�͵�����
�������
���أ���Ӧ��������1�����������
*/

#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int main(){
	int a = 0;
	int max = 0;
	string s;
	while (cin >> a){
		max = 0;
		s.clear();
		while (a){
			s.push_back(a % 2);
			a /= 2;
		}
		reverse(s.begin(), s.end());
		for (size_t i = 0; i < s.size(); ++i){
			int tmp = 0;
			while (i < s.size() && s[i] == 1){
				++tmp;
				++i;
			}
			if (tmp>max){
				max = tmp;
			}
		}
		cout << max << endl;
	}
	return 0;
}