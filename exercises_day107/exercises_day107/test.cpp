#define _CRT_SECURE_NO_WARNINGS 1

/*
1����ˮƿ
������һ�������⣺ĳ�̵�涨 ������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ�������
���Ի�����ƿ��ˮ�ȣ�����5ƿ������:����9����ƿ����ƿ���ȵ�����ʣ4����ƿ�ӣ���������
��һƿ�ȵ�����ʣ2�����ú���ϰ�һƿ�����꣬����������ƿ���ϰ��ˡ����С��������n����
��ˮƿ�������Ի�����ƿ��ˮ?
����:
	�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n(1<=100)����ʾС��
	���ϵĿ���ˮƿ���֡�n = 0��ʾ�����������ĳ���Ӧ��������һ�С�
����:
	3
	10
	81
	0
���:
	1
	5
	40
*/

/*
˼·: �ݹ�  
		�һ����Ϸ�Ϊ����������:
			1.��ǰ��ƿ�ɶһ�������
			2.����Ŀ�ƿ+��һ�β����һ����ϵ�ƿ�� �ɶһ�������
*/
#include<iostream>
#include<vector>
using namespace std;
int fun(int n){
	if (n<2){
		return 0;
	}
	else if (n == 2||n==3){
		return 1;
	}
	//n/3Ϊ��ǰ��ֱ�Ӷһ������� n%3Ϊ��һ�β����һ����ϵ�ƿ�� n/3�Ƕһ���ȹ�Ŀ�ƿ
		return n / 3 + fun(n%3+n/3);
}
//int main(){
//	int n = 0;
//	while (cin >> n){
//		if (n == 0){
//			break;
//		}
//		cout << fun(n) << endl;
//	}
//	return 0;
//}

/*
2�����������ַ���a��b�е�������Ӵ�
����a b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ�
���ӣ�
	���룺
		abcdefghijklmnop
		abcsafjklmnopqrstuvw
	���:
		jklmop
*/
/*
˼·�� ˫ָ��������� �Գ�����ÿ��������Ϊ��ͷȥ���ַ�����Ѱ�ҵ�������� ��ʼѰ�ҹ����Ӵ�
ÿ�θ�������ַ�
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void publicSting(vector<string>& res,string& a,string& b){
	//iָ���ַ��� jָ����ַ���  a�����ַ��� b������ַ���
	string tmp;
	int i = 0, j = 0, aSize = a.size(), bSize = b.size(), k = i, start = 0;
	while (i < aSize){
		while (j < bSize&&a[i]!=b[j]){
			++j;
		}
		      if (j<bSize&&a[k] == b[j]){
				//��ʱ��ʼѰ��
				  int startTmp = j;
				while (k < aSize&&j < bSize&&a[k] == b[j]){
					tmp += b[j];
					++k;
					++j;
				}
				if (res.empty()){
					start = startTmp;
					res.push_back(tmp);
				}
				else if(tmp.size()>res[0].size()){
						res.clear();
						start = startTmp;
						res.push_back(tmp);
					}
				else if(tmp.size()==res[0].size()){
					if (startTmp < start){
						res.clear();
						start = startTmp;
						res.push_back(tmp);
					}
				}
				tmp.clear();
			}
		j = 0;
		++i;
		k = i;
	}
}

int main(){
	string a, b;
	while (cin >> a >> b){
		vector<string> res;
		if (a.size() < b.size()){
			swap(a, b);
		}
		publicSting(res, a, b);
		cout << res[0] << endl;
	}
	return 0;
}