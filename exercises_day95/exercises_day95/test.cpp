#define _CRT_SECURE_NO_WARNINGS 1

/*
1������ӷ������дһ��������������������ӡ�����ʹ��+�����������������
��������intA��B���뷵��A+B��ֵ
����
	1��2
	3
*/
/*
˼·������λ�����  
^�൱��������ӵ�ǰλ�ò�����λ֮���λ��ǰ�����2^3 = (010)^(011) = 001 
&�൱��������ӵ�ǰλ���Ƿ������λ��2&3 =(010)&(011) = 010 ˵���ڶ�λ��Ҫ��λ �������ƴﵽ��λ��Ч�� 010<<1 = 100
�����������&��Ľ��Ϊ0�����λ����������λ����ﵽ�˼ӷ���Ч��
*/

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0, tmp = 0;
		while (B != 0){
			sum = A^B;
			tmp = (A&B) << 1;
			A = sum;
			B = tmp;
		}
		return sum;
	}
};

/*
2�����дһ�����������������Ӻ�����������n x m�����̸���(nΪ����ĸ�������mΪ����ĸ�����)
���Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж��ٷ����������߻�ͷ·��ֻ�����Һ������ߣ�
���룺����������
��������ؽ��
����
���룺	2
	    2
���:	6
*/

//˼·����������ó���״̬ת�Ʒ��� f(n,m) = f(n,m-1)+f(n-1,m)  ���Բ��õݹ�

//����һ���ݹ�
#include<iostream>
using namespace std;
int fun1(int n, int m){
	if (n == 0 || m == 0){
		return 1;
	}
	return fun1(n, m - 1) + fun1(n - 1, m);
}

//int main(){
//	int n = 0, m = 0;
//	while (cin >> n >> m){
//		cout << fun1(n, m) << endl;
//	}
//	return 0;
//}

/*����2������ʹ�û��ݷ�  �������߱� �������߸��� 
2��2�еĸ��ӣ����ݱ߷� ��0��0���� ��0��1���� �������� ��2��2���� ��������ȳ�һ��3��3�еĶ�ά���飬������Ϊ���ݵ�map
*/

#include<iostream>
#include<vector>
using namespace std;

int res = 0;
vector<vector<int>> map;
bool check(int i,int j,int n,int m){
	if (i < n&&j < m&&map[i][j] == 0){
		return true;
	}
	return false;
}

void dfs(int i, int j, int n, int m){
	if (i == n - 1 && j == m - 1){
		//�ҵ���ȷ·��
		++res;
		return;
	}
	if (i >= n || j >= m){
		//Խ��
		return;
	}
	if (check(i, j, n, m)){
		//��ǰ·�߿���
		map[i][j] = 1;
	}
	dfs(i, j + 1, n, m);//������
	dfs(i + 1, j, n, m);//������
	map[i][j] = 0;//����
}
int main(){
	int n = 0, m = 0;
	while (cin >> n >> m){
		map.resize(n + 1);
		for (int i = 0; i < n + 1; ++i){
			map[i].resize(m + 1, 0);
		}
		dfs(0, 0, n + 1, m + 1);
		cout << res << endl;
	}
	return 0;
}