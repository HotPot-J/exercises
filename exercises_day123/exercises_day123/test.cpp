#define _CRT_SECURE_NO_WARNINGS 1

/*
1�����齱��ţ�ͣ�
	1.������Ա���Լ������ַ�������
	2.����������������ϣ�ÿ���˴�������ȡһ������
	3.����鵽���������Լ������֣����н�
�ָ�����μ�������������������ж��ٸ��ʳ��������н���
*/


/*
˼·:�ŵ����   �޷Żص�����£� 
���ȷ�ĸΪ���г齱�Ŀ����Եĸ�����c(n,1)*c(n-1,1)...c(1,1)��n��
δ�н��¼������ĸ���:
	1.��ÿ�ζ��������������öԷ������� ��������������Ϊ ��n-1��* f(n-2)
	2.���������Ϊ��n-1��* f��n-1��
	��ɵõ��ƹ�ʽΪ f(n) = (n-1)*(f(n-1)+f(n-2))
*/
#include<iostream>
using namespace std;

//��׳�
double factorial(int n){
	if (n==0||n == 1){
		return 1;
	}
	return n*factorial(n - 1);
}

//��δ�н�ʱ�䷢������
double func(int n){
	if (n == 1){
		//���н� δ�н�ʱ�䷢������Ϊ0
		return 0;
	}
	if (n == 2){
		//�ս��Ͳ��н�������Ϊ1
		return 1;
	}
	return (n - 1)*(func(n - 1) + func(n - 2));
}
//int main(){
//	int n = 0;
//	while (cin >> n){
//		double res = (func(n) / factorial(n)) * 100;
//		printf("%.2f%c\n", res, '%');
//	}
//	return 0;
//}

/*
2�������б�ţ�ͣ�
ncÿ��Ҫ����ܶ��ʼ����������������ռ����б��У���ʱ��ֻ�Ǳ����͡�����Ϊ��Щ����
���ʼ���Ҫ�Ա��Լ����ռ����б���ĵͣ������Ҫ���˴�Ҫ���ʼ������ȴ�����Ҫ�ʼ�
���ڸ���һ�������б������ж�Ŀ���û��Ƿ��ڳ����б��С�
����������
	�����ж������ݣ�ÿ�����������С�
	��һ�г����б�����֮���ö��Ÿ�������������а����ո���߶��ţ�������������
	˫������
�������:
	����ڶ��е����ֳ������ռ����б��У������"Ignore"����ʾ����Ҫ���������
	"Important"
*/

/*
˼·:�ַ����ָ�����
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void func(string& str, vector<string>& map){
	//��ÿ�����ִ��map��
	int i = 0, len = str.size();
	while (i < len){
		string tmp;
		if (str[i] == '\"'){
			++i;
			while (i<len&&str[i] != '\"'){
				tmp += str[i];
				++i;
			}
			++i;
		}
		else{
			while (i < len&&str[i] != ','){
				tmp += str[i];
				++i;
			}
		}
		map.push_back(tmp);
		++i;
	}
}

int main(){
	string a, b;
	while (getline(cin, a)){
		getline(cin, b);
		vector<string> map;
		func(a, map);
		cout << ((find(map.begin(), map.end(), b) != map.end()) ? "Ignore" : "Important!") << endl;
		a.clear();
	}
	return 0;
}

